#include <Geode/Geode.hpp>
#include "KeyPickerPopup.hpp"

bool KeyPickerPopup::init(enumKeyCodes current, std::function<void(enumKeyCodes)> onConfirm) {

    if (!Popup::init(220.0f, 130.0f)) return false;
    
    key = current;
    this->setTitle("Press a key!", "bigFont.fnt");

    keyLabel = CCLabelBMFont::create("", "goldFont.fnt");
    keyLabel->setID("selected-key");
    updateKeyLabel();
    m_mainLayer->addChildAtPosition(keyLabel, Anchor::Center, {0, 8});

    auto confirmKey = ButtonSprite::create("Confirm", "goldFont.fnt", "GJ_button_01.png");
    confirmKey->setScale(0.8f);

    auto confirmBtn = CCMenuItemExt::createSpriteExtra(confirmKey, [this, onConfirm] (CCObject* sender) { onConfirm(getKey()); this->onClose(nullptr); });
    m_buttonMenu->addChildAtPosition(confirmBtn, Anchor::Bottom, {0, 26});
    
    return true;
}

void KeyPickerPopup::keyDown(enumKeyCodes pressedKey, double balls) {
    if (pressedKey == enumKeyCodes::KEY_Escape) pressedKey = enumKeyCodes::KEY_None;
    int k = int(pressedKey);
    if (k < 0) return;
    key = pressedKey;
    updateKeyLabel();
}

void KeyPickerPopup::updateKeyLabel() {
    keyLabel->setString(keyToString(key).c_str());
    keyLabel->limitLabelWidth(160.0f, 1.0f, 0.1f);
}