#pragma once

#include <filesystem>
#include <functional>
#include <fstream>
#include <sstream>

#include <Geode/Geode.hpp>
#include <matjson.hpp>

namespace fs = std::filesystem;
using namespace geode::prelude;

class CustomChest {
public:
    void showChest(std::string id);

    inline static std::string jsonFileName = "custom_chests.json";
    inline static std::string jsonFilePath = fmt::format("{}/{}", Mod::get()->getConfigDir(), jsonFileName);

private:
    std::map<std::string, int> CHEST_TYPES = {
        { "small", 1 },
        { "big", 2 },
        { "1key", 3 },
        { "5key", 4 },
        { "10key", 5 },
        { "25key", 6 },
        { "50key", 7 },
        { "100key", 8 },
        { "gold", 9 }
    };

    std::map<std::string, int> REWARD_TYPES = {
        { "fireShard", 1 },
        { "iceShard", 2 },
        { "poisonShard", 3 },
        { "shadowShard", 4 },
        { "lavaShard", 5 },
        { "key", 6 },
        { "keys", 6 },
        { "orb", 7 },
        { "orbs", 7 },
        { "diamond", 8 },
        { "diamonds", 8 },
        { "icon", 9 },
        { "earthShard", 10 },
        { "bloodShard", 11 },
        { "metalShard", 12 },
        { "lightShard", 13 },
        { "soulShard", 14 },
        { "goldKey", 15 },
    };
};