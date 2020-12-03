#pragma once
#include <vector>
#include <string>
#include "../TileMap.h"

namespace nc {
	// TODO MAP
	class Map
	{
	public:
		Map() {}

		void Load();

		void CreateBorder();
		bool Create(nc::Scene* scene);

		std::vector<nc::TileMap> GetRooms() { return m_rooms; }
		std::vector<int> GetTiles() { return m_tiles; }
		GameObject** GetGameObjectTiles() { return m_gameObjectTiles; }
		std::vector<int> GetNums() { return { m_numX, m_numY }; }

		void Read(const rapidjson::Value& value);


	private:
		int m_numX{ 0 };
		int m_numY{ 0 };

		nc::Vector2 m_start{ 0, 0 };
		nc::Vector2 m_size{ 0, 0 };

		std::string m_mapName;

		nc::TileMap m_border;

		std::vector<int> m_tiles;

		std::vector<int> m_tileMapTiles;
		GameObject** m_gameObjectTiles;

		std::vector<nc::TileMap> m_rooms;

		std::vector<std::string> m_tileMapTileNames;
		std::vector<std::string> m_roomNames;

		nc::TileMap m_templateTileMap;

	};
}