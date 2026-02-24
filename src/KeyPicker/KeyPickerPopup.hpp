#pragma once

#include <Geode/ui/Popup.hpp>
using namespace geode::prelude;

class KeyPickerPopup : public geode::Popup {
protected:
    bool init(enumKeyCodes current, std::function<void(enumKeyCodes)> onConfirm);
    void keyDown(cocos2d::enumKeyCodes key, double balls) override;
    void updateKeyLabel();
    enumKeyCodes key;
    CCLabelBMFont* keyLabel;
public:
    static KeyPickerPopup* create(enumKeyCodes current, std::function<void(enumKeyCodes)> onConfirm) {
        auto ret = new KeyPickerPopup();
        if (ret->init(current, onConfirm)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }
    enumKeyCodes getKey() { return key; }
};

// I stole this from custom keybinds lol
// https://github.com/geode-sdk/CustomKeybinds/blob/f70ce1acaaf14d4be7ec2a42d9384d00dda928ac/src/Keybinds.cpp#L30
inline std::string keyToString(enumKeyCodes key) {
    switch (key) {
        case KEY_None:      return "(none)";
        case KEY_C:         return "C";     // rob HOW
        case KEY_Multiply:  return "Multiply";
        case KEY_Divide:    return "Divide";
        case KEY_OEMPlus:   return "Plus";
        case KEY_OEMMinus:  return "Minus";
        default: {
            auto s = CCKeyboardDispatcher::get()->keyToString(key);
            return (s != nullptr) ? s : fmt::format("(unknown: {})", int(key));
        }
    }
}