//
// Created by mk on 09/11/2021.
//

#include "TilesDisplay.h"
#include "MapData.h"

namespace asset_tool{

    void TilesDisplay::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    bool TilesDisplay::loadTiles(asset_tool::MapData &mapData, int numUniqueTiles) {
        // loadData the tileset texture
        if (!m_tileset.loadFromFile(mapData.tilesetFileName)){
            return false;
        }
        auto tileSize = sf::Vector2u(mapData.tileSize[0], mapData.tileSize[1]);
        auto width = mapData.mapSize[0];
        auto height = mapData.mapSize[1];


        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // populate the vertex array, with one quad per tile
            for (unsigned int tileNumber = 0; tileNumber < numUniqueTiles; ++tileNumber)
            {
                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(tileNumber * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(0, tileNumber * tileSize.y);
                quad[1].position = sf::Vector2f(tileSize.x, tileNumber * tileSize.y);
                quad[2].position = sf::Vector2f(tileSize.x, (tileNumber + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(0, (tileNumber + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }
}