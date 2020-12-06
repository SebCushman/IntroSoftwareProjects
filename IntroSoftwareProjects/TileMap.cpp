#include "pch.h"
#include "TileMap.h"
#include "Objects/ObjectFactory.h"
#include "Objects/GameObject.h"
#include "Objects/Scene.h"

namespace nc {
    void nc::TileMap::Read(const rapidjson::Value& value)
    {
        /*json::Get(value, "roomName", m_roomName);
        json::Get(value, "map", m_map);*/
        json::Get(value, "numX", m_numX);
        json::Get(value, "numY", m_numY);
        json::Get(value, "size", m_size);
        json::Get(value, "start", m_start);

        json::Get(value, "tileNames", m_tileNames);
        json::Get(value, "tiles", m_tiles);
    }

    bool nc::TileMap::Create(Scene* scene)
    {
        for (size_t i = 0; i < m_tiles.size(); i++) {
            int index = m_tiles[i];
            if (index != 0) 
            {
                GameObject* gameObject = ObjectFactory::Instance().Create<GameObject>(m_tileNames[index]);
                
                float x = static_cast<float>(i % m_numX);
                float y = static_cast<float>(i / m_numY);
                gameObject->m_transform.position = (m_start + (nc::Vector2{ x,y } * m_size));
                //gameObject->m_name = "Tile " + std::to_strig(index);

                array[(int)x][(int)y] = *gameObject;
                scene->AddGameObject(gameObject);
            }
        }
        return false;
    }
}
