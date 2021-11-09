//
// Created by mk on 09/11/2021.
//

#include "Tile.h"
namespace asset_tool{
    void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    }

    Tile::Tile(int width, int height, int tileNumber, sf::Texture& tileset) : m_width(width), m_height(height) {
        sf::VertexArray m_vertices;
    }

}
