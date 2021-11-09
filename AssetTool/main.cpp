#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
#include "Display.h"
#include "MapData.h"
#include <TGUI/TGUI.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

// for convenience
using json = nlohmann::json;

int main()
{
    using nlohmann::json;
    std::ofstream outJson("map.json");

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
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
    outJson << jsonMap << std::endl;


    asset_tool::MapData mapData;


    //write json object:
    outJson << jsonMap << std::endl;


    auto p2 = jsonMap.get<asset_tool::MapData>();
    std::cout << std::endl << " p2 =";
    for (auto i : p2.map)
        std::cout << i << ' ';
    std::cout << ", mapsize = [" << p2.mapSize[0] << "," << p2.mapSize[1] << "]" << std::endl;
    // create the tilemap from the level definition
    asset_tool::TileMap map;
    //read in our data-driven-game -- well just a map - but it's a start!

    // Load in the map data
    if (!map.load(p2)) {
        return EXIT_FAILURE;
    }

    map.setScale(0.5,0.5);
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