#include "pch.h"
#include "Engine.h"
#include <iostream>

namespace nc 
{
	bool nc::Engine::Startup()
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		m_systems.push_back(new Renderer);
		m_systems.push_back(new InputSystem);
		m_systems.push_back(new ResourceManager);
		m_systems.push_back(new PhysicsSystem);
		m_systems.push_back(new AudioSystem);

		for (auto system : m_systems) {
			system->Startup();
		}

		//create window
		
		m_point.x = 0;
		m_point.y = 0;

		GetCursorPos(m_lpPoint);

		m_name = "Introductory Software Projects";

		GetSystem<Renderer>()->Create(m_name, 800, 800);

		return true;
	}

	void nc::Engine::Shutdown()
	{
		for (auto system : m_systems) {
			system->Shutdown();
			delete system;
		}

		m_systems.clear();

		SDL_Quit();
	}

	void nc::Engine::Update()
	{
		m_timer.Tick();
		GetCursorPos(m_lpPoint);
		//std::cout << "X: " + std::to_string(m_point.x) + " Y: " + std::to_string(m_point.y) << std::endl;

		for (auto system : m_systems) {
			system->Update();
		}
	}
}

