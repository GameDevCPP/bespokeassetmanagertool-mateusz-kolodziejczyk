//
// Created by mk on 09/11/2021.
//

#ifndef ASSETTOOL_TILESDISPLAY_H
#define ASSETTOOL_TILESDISPLAY_H


#include <SFML/Graphics.hpp>
#include <string>
#include "MapData.h"

namespace asset_tool{
    class TilesDisplay : public sf::Drawable, public sf::Transformable{
    public:
        bool loadTiles(asset_tool::MapData &mapData, int numUniqueTiles);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
    };
}



#endif //ASSETTOOL_TILESDISPLAY_H
