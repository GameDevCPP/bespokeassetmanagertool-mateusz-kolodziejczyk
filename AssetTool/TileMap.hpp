#pragma once
#include <SFML/Graphics.hpp>
#include "MapData.h"
namespace asset_tool{
    class TileMap : public sf::Drawable, public sf::Transformable
    {
    public:
        TileMap(std::shared_ptr<asset_tool::MapData> mapData);
        void setMapData(std::shared_ptr<asset_tool::MapData> mapData);
        bool load(asset_tool::MapData map);
        bool loadTileSet();
        bool loadData(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        std::shared_ptr<asset_tool::MapData> m_mapData;
    };

}
