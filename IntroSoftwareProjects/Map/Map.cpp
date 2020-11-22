#include "Map.h"
#include "Objects/ObjectFactory.h"



void Map::Load()
{
	// iterate through the list of maps, settings each offset by the previous width
	// create a dead zone, a tileMap with only wall tiles within it along the outer ridge.
	// create a new row of tiles based off of the width from the index ( index % width ) 
    rapidjson::Document document;

    for (size_t i = 0; i < m_tiles.size(); i++) {
        int index = m_tiles[i];
        if (index != 0)
        {
            nc::TileMap tileMap;
            nc::json::Load(m_roomNames[index], document);
            tileMap.Read(document);

            for (int tile : tileMap.GetTiles())
            {
                m_tileMapTiles.push_back(tile);
            }
            if (i == m_tiles.size() - 1)
            {
                //m_numX = tileMap.GetNums()[0] * m_numX; // add 2 for border
                //m_numY = tileMap.GetNums()[1] * m_numY; // add 2 for border
                m_start = tileMap.GetStart();
                m_size = tileMap.GetSize();
                m_tileMapTileNames = tileMap.GetTileNames();

                m_templateTileMap = tileMap;
            }
            m_rooms.push_back(tileMap);
        }
    }



}

bool Map::Create(nc::Scene* scene)
{
    //for (int i = 0; i < m_rooms.size(); i++)
    //{
    //    //m_rooms.at(i).GetStart();
    //    m_rooms.at(i).Create(scene);
    //}

    int test = m_numX * m_numY;

    for (size_t x = 0; x < test; x++)
    {
        std::cout << "Index: " << x << std::endl;
        for (size_t i = 0; i < m_templateTileMap.GetTiles().size(); i++) 
        {
            int index = m_templateTileMap.GetTiles()[i];
            if (index != 0)
            {
                nc::GameObject* gameObject = nc::ObjectFactory::Instance().Create<nc::GameObject>(m_tileMapTileNames[index]);

                float x = static_cast<float>(i % m_templateTileMap.GetNums()[0]);
                float y = static_cast<float>(i / m_templateTileMap.GetNums()[1]);

            
                //nc::Vector2 offset = { (m_size.x * m_templateTileMap.GetNums()[0]), (m_size.y * m_templateTileMap.GetNums()[1]) };

            
                gameObject->m_transform.position = (m_start + (nc::Vector2{ x, y } * m_size));
                //gameObject->m_name = "Tile " + std::to_string(index);

                m_gameObjectTiles.push_back(gameObject);
                //std::cout << "Tile: {" << m_gameObjectTiles.at(i)->m_transform.position.x << ", " << m_gameObjectTiles.at(i)->m_transform.position.y << "} " << std::endl;
                scene->AddGameObject(gameObject);
            }
            // Upper left bound.
            //if (x % m_numX == 0 && x != 0)
            //{
            //    m_start = { (int)((m_templateTileMap.GetNums()[0] * m_size.x) + m_start.x), (int)(m_start.y) };


            //}
            ////
            //else if (x % m_numY == 0 && x != 0)
            //{
            //    // Room
            //    m_start = { (int)(m_start.x), (int)((m_templateTileMap.GetNums()[1] * m_size.y) + m_start.y) };

            //}
        }

    }
    return false;
}


void Map::Read(const rapidjson::Value& value)
{
	nc::json::Get(value, "map", m_mapName);
	nc::json::Get(value, "numX", m_numX);
	nc::json::Get(value, "numY", m_numY);
	nc::json::Get(value, "roomNames", m_roomNames);
	nc::json::Get(value, "tiles", m_tiles);
}
