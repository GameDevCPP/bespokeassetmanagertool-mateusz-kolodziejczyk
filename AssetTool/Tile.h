//
// Created by mk on 09/11/2021.
//

#ifndef ASSETTOOL_TILE_H
#define ASSETTOOL_TILE_H
#include <SFML/Graphics.hpp>

namespace asset_tool{
    class Tile : public sf::Drawable, public sf::Transformable{
    public:
        Tile(int width, int height, int tileNumber, sf::Texture& tileset);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        int m_width;
        int m_height;
        sf::Texture m_texture;
    };

}


#endif //ASSETTOOL_TILE_H
