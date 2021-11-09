#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
#include "Display.h"
#include "MapData.h"
#include "FileIO.h"
#include <TGUI/TGUI.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

// for convenience
using json = nlohmann::json;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(768, 256), "Tilemap");
    window.setVerticalSyncEnabled(true);

    sf::Vector2u widthAndHeight(16, 8), tileSize(32, 32);

    //output map as json object
    json jsonMap = {
            {"map",
                          {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                  0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
                                  1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
                                  0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                                  0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0 , 0,
                                  0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
                                  2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
                                  0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1}},
            {"tilesize",{tileSize.x,tileSize.y}},
            {"mapsize",{widthAndHeight.x,widthAndHeight.y}},
            {"maptexture","tileset.png"}
    };
    asset_tool::saveToJSON("map_data", jsonMap);
    std::pair<json, bool> result = asset_tool::loadFromJSON("map_data");
    // Only save result if loading from file was successful
    if(result.second){
        jsonMap = result.first;
    }
    else{
        std::cout << "Failed to loadData in file" << std::endl;
    }

    auto mapData = std::make_shared<asset_tool::MapData>(jsonMap.get<asset_tool::MapData>());
    // create the tilemap from the level definition
    asset_tool::TileMap map(mapData);
    //read in our data-driven-game -- well just a map - but it's a start!

    // Load in the map data
    if (!map.loadTileSet()) {
        return EXIT_FAILURE;
    }

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // draw the map
        window.clear();
        window.draw(map);
        window.display();
    }
    return EXIT_SUCCESS;

};