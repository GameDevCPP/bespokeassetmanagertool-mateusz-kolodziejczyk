#pragma once
#include "nlohmann/json.hpp"
#include "SFML/Graphics.hpp"
#include <string>
namespace asset_tool {
    struct MapData {
        std::vector<int> map;
        int tileSize[2], mapSize[2];
        std::string tilesetFileName;
        const int* get_level();
    };
    void to_json(nlohmann::json& j, const MapData& md);
    void from_json(const nlohmann::json& j, MapData& md);
}
