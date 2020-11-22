#pragma once
#include "Components\Component.h"
#include "../TileMap.h"
#include "../IntroSoftwareProjects/Map/Map.h"


namespace nc {
	class PlayerComponent : public Component 
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual Object* Clone() const override { return new PlayerComponent{ *this }; }

		virtual void Update() override;

		void LoadMap(const TileMap& tileMap);
		void LoadMap(const Map& map);

		signed int GetPlayerIndex() { return m_playerIndex; }
		TileMap GetTileMap() { return m_tileMap; }

		void OnCollisionEnter(const Event& event);
		void OnCollisionExit(const Event& event);
	protected:
		signed int m_playerIndex{ 0 };
		TileMap m_tileMap;
		Map m_map;


	};
}