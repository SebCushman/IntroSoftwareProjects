#include "pch.h"
#include "Graphics/Texture.h"
#include "Objects/GameObject.h"
#include "Components/PlayerComponent.h"
#include "Components/EnemyComponent.h"
#include "Core/Json.h"
#include "Core/EventManager.h"
#include "Objects/ObjectFactory.h"
#include "Objects/Scene.h"
#include "TileMap.h"
#include "Objects/GameObject.cpp"
#include "Map/Map.h"

nc::Engine engine;
nc::Scene scene;

void OnPlayerDead(const nc::Event& event) 
{
    int* pdata = static_cast<int*>(event.data);
    int score = *pdata;

    std::cout << "Player Dead: " << score << std::endl;
}


int main(int, char**) 
{
    engine.Startup();
   

    nc::ObjectFactory::Instance().Initialize();
    nc::ObjectFactory::Instance().Register("PlayerComponent", new nc::Creator<nc::PlayerComponent, nc::Object>);
    nc::ObjectFactory::Instance().Register("EnemyComponent", new nc::Creator<nc::EnemyComponent, nc::Object>);
    nc::EventManager::Instance().Subscribe("PlayerDead", &OnPlayerDead);



    rapidjson::Document document;
    nc::json::Load("scene.txt", document);
    scene.Create(&engine);
    scene.Read(document);

    //nc::json::Load("tileMap.txt", document);
    nc::json::Load("01.txt", document);
    /*Map map;
    map.Read(document);
    map.Load();
    map.Create(&scene);*/
    nc::TileMap tileMap;
    tileMap.Read(document);
    tileMap.Create(&scene);

    //Generate Tiles

    nc::GameObject* player = scene.Find("Player");
    player->GetComponent<nc::PlayerComponent>()->LoadMap(tileMap);

    //std::cout << "X: " << player->GetComponent<nc::PlayerComponent>()->GetPlayerIndex() % player->GetComponent<nc::PlayerComponent>()->GetTileMap().GetNums()[0] << " Y: " << player->GetComponent<nc::PlayerComponent>()->GetPlayerIndex() / player->GetComponent<nc::PlayerComponent>()->GetTileMap().GetNums()[1] << " Index: " << player->GetComponent<nc::PlayerComponent>()->GetPlayerIndex() << std::endl;
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        SDL_PollEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
            quit = true;
            break;
        }

        //update
        engine.Update();
        scene.Update();

        if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == nc::InputSystem::eButtonState::PRESSED) 
        {
            quit = true;
        }
        
        engine.GetSystem<nc::Renderer>()->BeginFrame();

        scene.Draw();

        engine.GetSystem<nc::Renderer>()->EndFrame();
    }

    scene.Destroy();
    engine.Shutdown();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
