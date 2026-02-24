using namespace geode::prelude;

struct CTKeybind {
	int value;

    // no idea what any of this does but it was in the docs
	bool operator==(CTKeybind const& other) const = default;
	operator int() const { return value; };

    CTKeybind() = default;
    CTKeybind(int value) : value(value) {}
    CTKeybind(CTKeybind const&) = default;

    enumKeyCodes getKey() const { return static_cast<enumKeyCodes>(value); }
};

class KeyPicker : public SettingBaseValueV3<int> {
public:
    // all of this is copied from the docs because i have no idea what i'm doing
    static Result<std::shared_ptr<SettingV3>> parse(
        std::string const& key,
        std::string const& modID,
        matjson::Value const& json
    ) {
        auto res = std::make_shared<KeyPicker>();
        auto root = checkJson(json, "KeyPicker");
        res->parseBaseProperties(key, modID, root);
        return root.ok(std::static_pointer_cast<SettingV3>(res));
    }

    SettingNodeV3* createNode(float width) override;
};   

template <>
struct matjson::Serialize<CTKeybind> {
    static matjson::Value toJson(CTKeybind const& settingValue) { return settingValue.value; }
    static Result<CTKeybind> fromJson(matjson::Value const& json) {
        GEODE_UNWRAP_INTO(auto num, json.asInt());
        return Ok(CTKeybind(num));
    }
};

template <>
struct geode::SettingTypeForValueType<CTKeybind> {
    using SettingType = KeyPicker;
};