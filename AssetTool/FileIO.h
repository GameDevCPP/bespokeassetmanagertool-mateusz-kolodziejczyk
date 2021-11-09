//
// Created by mk on 09/11/2021.
//

#ifndef ASSETTOOL_FILEIO_H
#define ASSETTOOL_FILEIO_H

#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <utility>

namespace asset_tool{
    bool saveToJSON(std::string fileName, nlohmann::json& json);
    std::pair<nlohmann::json, bool> loadFromJSON(std::string fileName);
}

#endif //ASSETTOOL_FILEIO_H
