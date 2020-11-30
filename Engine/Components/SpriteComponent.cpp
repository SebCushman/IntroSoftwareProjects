#include "pch.h"
#include "SpriteComponent.h"
#include "Graphics/Texture.h"
#include "CameraComponent.h"
#include <list>
#include "../../IntroSoftwareProjects/Components/PlayerComponent.h"

namespace nc {
	void SpriteComponent::Create(void* data)
	{
		m_owner = static_cast<nc::GameObject*>(data);

		//m_texture = m_owner->m_engine->GetSystem<nc::ResourceManager>()->Get<nc::Texture>(m_textureName, m_owner->m_engine->GetSystem<nc::Renderer>());
		//ASSERT_MSG((m_texture != nullptr), "Error texture " + m_textureName + " not loaded");
	}

	void nc::SpriteComponent::Destroy()
	{
	}

	void SpriteComponent::Read(const rapidjson::Value& value)
	{
		json::Get(value, "texture", m_textureName);
		json::Get(value, "origin", m_origin);
		json::Get(value, "rect", m_rect);
	}

	void nc::SpriteComponent::Update()
	{
	}

	void nc::SpriteComponent::Draw()
	{
		//{ 125, 440, 60, 110 }

		//Get camera position
		//set sprite position offset from camera position
		// sprite position = sprite position - camera position
		Vector2 cameraOffset = { 0, 0 };

		//get scene -> camera object
		GameObject* player = m_owner->m_scene->Find("Player");
		if (player)
		{
			CameraComponent* component = player->GetComponent<CameraComponent>();
			if (component)
			{
				component->UpdateCameraPosition(player->m_transform.position);
				component->SetCropFactor({ player->GetComponent<PlayerComponent>()->GetTileMap().GetNums()[0], player->GetComponent<PlayerComponent>()->GetTileMap().GetNums()[1] });
				cameraOffset = (component->GetCameraPosition() - (m_owner->m_engine->GetSystem<Renderer>()->GetDimensions() * 0.5f)); // / component->GetCropFactor();
				

			}
		}


		//get camera transform position.
		Vector2 position = m_owner->m_transform.position;
		Vector2 offsetPosition = m_owner->m_transform.position - cameraOffset;


		Texture* texture = m_owner->m_engine->GetSystem<nc::ResourceManager>()->Get<nc::Texture>(m_textureName, m_owner->m_engine->GetSystem<nc::Renderer>());
		
		//std::vector<GameObject*> objectVec = m_owner->m_scene->FindGameObjectsWithTag("wall");

		/*for (GameObject* gameObject : m_owner->m_scene->FindGameObjectsWithTag("wall"))
		{


		}
		*/

		texture->Draw(m_rect, offsetPosition, m_owner->m_transform.angle, Vector2::one * m_owner->m_transform.scale, m_origin, m_flip);

		/*if (std::find(objectVec.begin(), objectVec.end(), this) != objectVec.end())
		{
			texture->Draw(m_rect, offsetPosition, m_owner->m_transform.angle, Vector2::one * m_owner->m_transform.scale, m_origin, m_flip);
		}
		else
		{

		}*/
		//texture->Draw(m_rect, position, m_owner->m_transform.angle, Vector2::one * m_owner->m_transform.scale, m_origin, m_flip);

		//texture->Draw(m_rect, m_owner->m_transform.position, m_owner->m_transform.angle, Vector2::one * m_owner->m_transform.scale, m_origin, m_flip);
	}
}

