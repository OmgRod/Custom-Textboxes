#pragma once

#include <filesystem>
#include <functional>
#include <fstream>
#include <sstream>

#include <Geode/Geode.hpp>
#include <matjson.hpp>

namespace fs = std::filesystem;
using namespace geode::prelude;

class CustomTextbox {
public:
    void showTextbox(std::string id);
    int getPortrait(matjson::Value data, int fallback);

    inline static std::string jsonFileName = "custom_dialogues.json";
    inline static std::string jsonFilePath = fmt::format("{}/{}", Mod::get()->getConfigDir(), jsonFileName);

private:
    std::map<std::string, int> TEXTBOX_POSITIONS = {
        { "center", 0 },
        { "top", 1 },
        { "bottom", 2 }
    };

    std::map<std::string, int> TEXTBOX_PORTRAITS = {
        { "spooky", 1 },
        { "keymaster", 2 },
        { "gatekeeper", 3 },
        { "keymaster2", 4 },
        { "shopkeeper", 5 },
        { "shopkeeper2", 6 },
        { "gatekeeper2", 7 },
        { "scratch", 8 },
        { "scratch2", 9 },
        { "scratch3", 10 },
        { "scratch4", 12 },
        { "scratch5", 13 },
        { "scratch6", 14 },
        { "monster", 15 },
        { "monster2", 16 },
        { "keymaster3", 17 },
        { "keymaster4", 18 },
        { "potbor", 19 },
        { "potbor2", 20 },
        { "potbor3", 21 },
        { "potbor4", 22 },
        { "potbor5", 23 },
        { "potbor6", 24 },
        { "potbor7", 25 },
        { "scratch7", 26 },
        { "scratch8", 27 },
        { "robtop", 28 },
        { "shopkeeper3", 29 },
        { "shopkeeper4", 30 },
        { "shopkeeper5", 31 },
        { "shopkeeper6", 32 },
        { "zolguroth", 33 },
        { "shopkeeper7", 34 },
        { "shopkeeper8", 35 },
        { "shopkeeper9", 36 },
        { "mechanic", 37 },
        { "mechanic2", 38 },
        { "mechanic3", 39 },
        { "diamond", 40 },
        { "diamond2", 41 },
        { "diamond3", 42 },
        { "diamond4", 43 },
        { "mechanic4", 44 },
        { "mechanic5", 45 },
        { "mechanic6", 46 },
        { "diamond5", 47 },
        { "diamond6", 48 },
        { "mechanic7", 49 },
        { "mechanic8", 50 },
        { "mechanic9", 51 },
        { "chopper", 52 },
        { "wraith", 53 },
        { "wraith2", 54 },
        { "wraith3", 55 },
        { "wraith4", 56 },
    };
};

// custom callbacks for dialog boxes
// https://discord.com/channels/911701438269386882/979402752121765898/1330246496637161564
class CustomDialogCallback : public CCNode, public DialogDelegate {
	public:
		std::function<void()> m_callback;
		virtual void dialogClosed(DialogLayer* p0) { if (m_callback) m_callback(); }
};