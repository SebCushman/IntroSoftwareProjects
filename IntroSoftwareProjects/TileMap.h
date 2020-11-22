#pragma once
#include "Core/Json.h"
#include "Objects/GameObject.h"
#include "Math/Vector2.h"
#include "Engine.h"


namespace nc {
	class TileMap {
	public:
		void Read(const rapidjson::Value& value);
		bool Create(class Scene* scene);

		std::vector<std::string> GetTileNames() { return m_tileNames; }
		std::vector<int> GetTiles() { return m_tiles; }
		std::vector<int> GetNums() { return { m_numX, m_numY }; }

		Vector2 GetSize() { return m_size; }
		Vector2 GetStart() { return m_start; }

		void SetStart(Vector2 start) { m_start = start; }

		std::vector<GameObject*> GetGameObjectTiles() { return m_gameObjectTiles; }
 		
	protected:
		/*std::string m_roomName;
		std::string m_map;*/

		Vector2 m_offset{ 0, 0 };

		int m_numX{ 0 };
		int m_numY{ 0 };
		Vector2 m_size;
		Vector2 m_start;

		std::vector<GameObject*> m_gameObjectTiles;

		std::vector<std::string> m_tileNames;
		std::vector<int> m_tiles;
	};
}