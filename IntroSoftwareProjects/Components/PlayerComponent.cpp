#include "pch.h"
#include "PlayerComponent.h"
#include "Components/RigidBodyComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SpriteComponent.h"

namespace nc {

	void nc::PlayerComponent::Create(void* data)
	{
        m_owner = static_cast<nc::GameObject*>(data);

	}

	void nc::PlayerComponent::Destroy()
	{
	}

    void nc::PlayerComponent::Update()
    {
        auto contacts = m_owner->GetContactsWithTag("Floor");
        bool onGround = !contacts.empty();

        nc::Vector2 force{ 0,0 };

        // CHECK VALID MOVEMENT TODO
        // Store player's current position, check the next position... if wall tile, do not move.
        
        
        Vector2 prevPlayerIndex = m_playerIndex;

        bool diagonal = m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_Q) == nc::InputSystem::eButtonState::HELD;

        
        if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::PRESSED)
        {
            //DOWN LEFT
            if (diagonal)
            {
                m_playerIndex += {-1, 1};
            }
            //LEFT
            else
            {
                m_playerIndex += {-1, 0};

            }
            //system("cls");
            //std::cout << "X: " << playerPos[0] << " Y: " << playerPos[1] << std::endl;
            //m_owner->m_transform.angle = m_owner->m_transform.angle - 200.0f * m_owner->m_engine->GetTimer().DeltaTime();
        }
        if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == nc::InputSystem::eButtonState::PRESSED)
        {
            //UP RIGHT
            if (diagonal)
            {
                m_playerIndex += {1, -1};
            }
            //RIGHT
            else
            {
                m_playerIndex += {1, 0};

            }
            //system("cls");
            //std::cout << "X: " << playerPos[0] << " Y: " << playerPos[1] << std::endl;
        }

        //Y
        if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_W) == nc::InputSystem::eButtonState::PRESSED)
        {
            if (diagonal)
            //UP LEFT
            {
                m_playerIndex += {-1, -1};
            }
            //UP
            else
            {
                m_playerIndex += {0, -1};
                
            }
            //system("cls");
            //std::cout << "X: " << playerPos[0] << " Y: " << playerPos[1] << std::endl;
        }

        if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_S) == nc::InputSystem::eButtonState::PRESSED)
        {
            if (diagonal)
                //UP LEFT
            {
                m_playerIndex += {1, 1};
            }
            //DOWN
            else
            {
                m_playerIndex += {0, 1};

            }
            //system("cls");
        }


        int index = m_tileMap.GetTiles()[prevPlayerIndex.x + (prevPlayerIndex.y * (m_tileMap.GetNums())[0])];
        

        if ((m_playerIndex.x + (m_playerIndex.y * (m_tileMap.GetNums())[0])) < m_tileMap.GetTiles().size() && (m_playerIndex.x + (m_playerIndex.y * (m_tileMap.GetNums())[0])) > 0)
        {
            index = m_tileMap.GetTiles()[(m_playerIndex.x + (m_playerIndex.y * (m_tileMap.GetNums())[0]))];
            /*int index1 = m_tileMap.GetTiles()[playerPos[0]];
            int index2 = m_tileMap.GetTiles()[playerPos[1]];*/

            if (m_tileMap.GetTileNames()[index] == "Tile01"/* || m_tileMap.GetTileNames()[index2] == "Tile01"*/)
            {
                    m_playerIndex = prevPlayerIndex;
            }
        }
        else
        {
            m_playerIndex = prevPlayerIndex;
        }


        
        if (m_playerIndex != prevPlayerIndex)
        {
            system("cls");
            std::cout << "X: " << m_playerIndex.x << " Y: " << m_playerIndex.y << " Index: " << m_playerIndex << std::endl;

            std::cout << Lerp<Vector2>(prevPlayerIndex, m_playerIndex, 1.0f).x << " " << Lerp<Vector2>(prevPlayerIndex, m_playerIndex, 1.0f).y << std::endl;
        }

        m_owner->m_transform.position = m_tileMap.array[(int)m_playerIndex.x][(int)m_playerIndex.y].m_transform.position;
    }

    void PlayerComponent::LoadMap(const TileMap& tileMap)
    {
        m_tileMap = tileMap;
        m_playerIndex = {7, 7};

    }

    //void PlayerComponent::LoadMap(const Map& map)
    //{
    //    //m_map = map;
    //    //m_playerIndex = (m_map.GetNums()[0] * (m_map.GetNums()[1]) / 2);
    //}

    void PlayerComponent::OnCollisionEnter(const Event& event)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(event.sender);

        if (gameObject->m_tag == "Enemy") {
            AudioComponent* audioComponent = m_owner->GetComponent<AudioComponent>();
            audioComponent->SetSoundName("audio/grunt.wav");
            audioComponent->Play();

            m_owner->m_flags[GameObject::eFlags::DESTROY] = true;

            Event event;
            event.type = "PlayerDead";
            int score = 300;
            event.data = &score;
            EventManager::Instance().Notify(event);
        }

        if (gameObject->m_tag == "Coin") {
            AudioComponent* audioComponent = m_owner->GetComponent<AudioComponent>();
            audioComponent->SetSoundName("audio/coin.wav");
            audioComponent->Play();

            gameObject->m_flags[GameObject::eFlags::DESTROY] = true;
        }
    }
    void PlayerComponent::OnCollisionExit(const Event& event)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(event.sender);

    }
}
