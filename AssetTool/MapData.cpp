#include "MapData.h"

namespace TileMapping {
    const int* MapData::get_level() {
        //since vector must store data contiguously, the following works for array
        int* a = &map[0];
        return a;
    }
    void to_json(nlohmann::json& j, const MapData& ms) {
        j = nlohmann::json{
            {"map",ms.map},
            {"tilesize",ms.tileSize},
            {"mapsize",ms.mapSize},
            {"maptexture",ms.textureForMap}
        };
    }
    void from_json(const nlohmann::json& j, MapData& ms) {
        j.at("map").get_to(ms.map);
        j.at("tilesize").get_to(ms.tileSize);
        j.at("mapsize").get_to(ms.mapSize);
        j.at("maptexture").get_to(ms.textureForMap);
    }
}
