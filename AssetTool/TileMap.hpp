#pragma once
#include <SFML/Graphics.hpp>
#include "MapData.h"
namespace asset_tool{
    class TileMap : public sf::Drawable, public sf::Transformable
    {
    public:
        explicit TileMap(std::shared_ptr<asset_tool::MapData> mapData);
        void setMapData(std::shared_ptr<asset_tool::MapData> mapData);
        bool loadTilesheet();
        bool loadTileSet();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        std::shared_ptr<asset_tool::MapData> m_mapData;
    };

}
