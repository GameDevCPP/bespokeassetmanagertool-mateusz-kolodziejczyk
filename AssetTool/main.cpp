#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
#include "Display.h"
#include "MapData.h"
#include "FileIO.h"
#include "TilesDisplay.h"
#include <TGUI/TGUI.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <utility>

// for convenience
using json = nlohmann::json;
bool save(std::string fileName, asset_tool::MapData &mapData);

bool save(std::string fileName, asset_tool::MapData &mapData) {
    json j;
    j = mapData;
    asset_tool::saveToJSON(std::move(fileName), j);
    return true;;
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(768, 256), "Tilemap");
    window.setVerticalSyncEnabled(true);


    int selectedTile = 0;
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

    // Load in tilesheet then tile set
    if(!map.loadTilesheet()){
        return EXIT_FAILURE;
    }
    // Load in the tileSet data
    if (!map.loadTileSet()) {
        return EXIT_FAILURE;
    }

    asset_tool::TilesDisplay tilesDisplay;

    tilesDisplay.loadTiles(*mapData, 4);
    int tileDisplayScaleFactor = 2;
    float tileDisplayX = (float)(window.getSize().x - tileSize.x * tileDisplayScaleFactor);
    tilesDisplay.setPosition(tileDisplayX, 0);
    tilesDisplay.setScale(tileDisplayScaleFactor,tileDisplayScaleFactor);

    // Create the gui
    tgui::GuiSFML gui{window};
    // GUI Items
    auto button = tgui::Button::create();
    button->setPosition(600, 70);
    button->setText("Save");
    button->setSize(100, 30);
    button->onPress([&]{
        json j;
        asset_tool::to_json(j, *mapData);
        asset_tool::saveToJSON("map_data", j);
        std::cout << "Clicked" << std::endl;
    });
    gui.add(button);
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Mouse events
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            auto mousePosition = sf::Mouse::getPosition(window);
            int mouseX = mousePosition.x;
            int mouseY = mousePosition.y;

            // Painting tiles
            // Find what position tile in the mapdata array the click was on.
            int x = mouseX / (int)tileSize.x;
            int y = mouseY / (int)tileSize.y;
            std::cout << "x:" << x << "," << "y:" << y << std::endl;
            // Make sure the mouse was inside the map area
            if(x >= 0 && x < widthAndHeight.x && y>=0 && y < widthAndHeight.y) {
                int index = x + (int) widthAndHeight.x * y;
                std::cout << index << std::endl;
                mapData->map.at(index) = selectedTile;
            }

            // Choosing tile
            if((float)mouseX > tileDisplayX){
                // change selected tile to wherever the mouse was.
                // Only need to use mouseY as the tile display is always at the edge
                selectedTile = (int)(mouseY / (tileSize.y*tileDisplayScaleFactor));
                std::cout << "new selected tile: " << selectedTile << std::endl;
            }
        }
        // Load tile set every frame
        map.loadTileSet();
        // draw the map
        window.clear();
        window.draw(map);
        window.draw(tilesDisplay);
        gui.draw();
        window.display();

    }
    return EXIT_SUCCESS;

};