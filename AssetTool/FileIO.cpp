//
// Created by mk on 09/11/2021.
//

#include "FileIO.h"

std::pair<nlohmann::json, bool> asset_tool::loadFromJSON(std::string fileName) {
    std::ifstream inputFile(fileName + ".json");

    nlohmann::json json;
    if(!inputFile){
        return {json, false};
    }
    inputFile >> json;
    return {json, true};
}

bool asset_tool::saveToJSON(std::string fileName, nlohmann::json& json) {
    std::ofstream outputFile(fileName + ".json");
    outputFile << json << std::endl;
    return true;
}