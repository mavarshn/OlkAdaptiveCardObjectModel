#pragma once

#include "stdafx.h"
#include "AdaptiveCardParseException.h"
#include "Enums.h"
#include <jsondom/ijsondom.h>
#include <jsondom/JsonCommon.h>

namespace AdaptiveCards
{

class ParseUtil
{

public:

    static void ThrowIfNotJsonObject(const Mso::Json::value& json);

    static void ExpectString(const Mso::Json::value& json);

    static std::wstring GetTypeAsString(const Mso::Json::value& json);

    static std::wstring TryGetTypeAsString(const Mso::Json::value& json);

    static std::wstring GetString(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired = false);

    // Gets the specified property and returns a JSON string of the value
    static std::wstring GetJsonString(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired = false);

    static std::wstring GetValueAsString(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired = false);

    static bool GetBool(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool defaultValue, bool isRequired = false);

    static unsigned int GetUInt(const Mso::Json::value& json, AdaptiveCardSchemaKey key, unsigned int defaultValue, bool isRequired = false);

    static int GetInt(const Mso::Json::value& json, AdaptiveCardSchemaKey key, int defaultValue, bool isRequired = false);

    static CardElementType GetCardElementType(const Mso::Json::value& json);

    static CardElementType TryGetCardElementType(const Mso::Json::value& json);

    static ActionType GetActionType(const Mso::Json::value& json);

    static ActionType TryGetActionType(const Mso::Json::value& json);

    static Mso::Json::value GetArray(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired = false);

    static Mso::Json::value GetJsonValueFromString(const std::wstring jsonString);

    static Mso::Json::value ExtractJsonValue(const Mso::Json::value& jsonRoot, AdaptiveCardSchemaKey key, bool isRequired = false);

    static Mso::Json::value GetValue(Mso::Json::value const &parent, const std::wstring &name);

    static std::wstring GetString(Mso::Json::value const &parent, const std::wstring &name, const wchar_t *defaultString = nullptr);

    static int32_t GetInteger(Mso::Json::value const &parent, const std::wstring &name);

    static bool GetBoolean(Mso::Json::value const &parent, const std::wstring &name, bool fDefault = false);

    template <typename T>
    static T GetEnumValue(
        const Mso::Json::value& json,
        AdaptiveCardSchemaKey key,
        T defaultEnumValue,
        std::function<T(const std::wstring& name)> enumConverter,
        bool isRequired = false);

    template <typename T>
    static std::vector<std::shared_ptr<T>> GetElementCollection(
        const Mso::Json::value& json,
        AdaptiveCardSchemaKey key,
        const std::unordered_map<CardElementType, std::function<std::shared_ptr<T>(const Mso::Json::value&)>, EnumHash>& parsers,
        bool isRequired = false);

    template <typename T>
    static std::vector<std::shared_ptr<T>> GetActionCollection(
        const Mso::Json::value& json,
        AdaptiveCardSchemaKey key,
        const std::unordered_map<ActionType, std::function<std::shared_ptr<T>(const Mso::Json::value&)>, EnumHash>& parsers,
        bool isRequired = false);

    template <typename T>
    static T ExtractJsonValueAndMergeWithDefault(
        const Mso::Json::value& rootJson,
        AdaptiveCardSchemaKey key,
        const T &defaultValue,
        const std::function<T(const Mso::Json::value&, const T&)>& deserializer);

    template <typename T>
    static std::shared_ptr<T> GetActionFromJsonValue(
        const Mso::Json::value& json,
        const std::unordered_map<ActionType, std::function<std::shared_ptr<T>(const Mso::Json::value&)>, EnumHash>& parsers);

    static void ExpectTypeString(const Mso::Json::value& json, CardElementType bodyType);

    // throws if the key is missing or the value mapped to the key is the wrong type
    static void ExpectKeyAndValueType(const Mso::Json::value& json, const wchar_t* expectedKey, std::function<void(const Mso::Json::value&)> throwIfWrongType);


private:
    ParseUtil();
    ~ParseUtil();

};

template <typename T>
T ParseUtil::GetEnumValue(const Mso::Json::value& json, AdaptiveCardSchemaKey key, T defaultEnumValue, std::function<T(const std::wstring& name)> enumConverter, bool isRequired)
{
    std::wstring propertyValueStr = L"";
    try
    {
        const std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
        auto propertyValue = GetValue(json, propertyName);
        if (propertyValue.is_null())
        {
            if (isRequired)
            {
                throw AdaptiveCardParseException(L"Property is required but was found empty: " + propertyName);
            }
            else
            {
                return defaultEnumValue;
            }
        }

        if (!propertyValue.is_string())
        {
            throw AdaptiveCardParseException(L"Enum type was invalid. Expected type string.");
        }

        propertyValueStr = propertyValue.as_string();
        return enumConverter(propertyValueStr);
    }
    catch (const std::out_of_range&)
    {
        throw AdaptiveCardParseException(L"Enum type was out of range. Actual: " + propertyValueStr);
    }
}

template <typename T>
std::vector<std::shared_ptr<T>> ParseUtil::GetElementCollection(
    const Mso::Json::value& json,
    AdaptiveCardSchemaKey key,
    const std::unordered_map<CardElementType, std::function<std::shared_ptr<T>(const Mso::Json::value&)>, EnumHash>& parsers,
    bool isRequired)
{
    auto elementArray = GetArray(json, key, isRequired);

    std::vector<std::shared_ptr<T>> elements;
    if (elementArray.is_null())
    {
        return elements;
    }

    elements.reserve(elementArray.size());

    for (const auto& curJsonValue : elementArray)
    {
        // Get the element's type
        CardElementType curElementType = ParseUtil::TryGetCardElementType(curJsonValue.second);

        //Parse it if it's allowed by the current parsers
        if (parsers.find(curElementType) != parsers.end())
        {
            // Use the parser that maps to the type
            elements.push_back(parsers.at(curElementType)(curJsonValue.second));
        }
    }

    return elements;
}

template <typename T>
std::vector<std::shared_ptr<T>> ParseUtil::GetActionCollection(
    const Mso::Json::value& json,
    AdaptiveCardSchemaKey key,
    const std::unordered_map<ActionType, std::function<std::shared_ptr<T>(const Mso::Json::value&)>, EnumHash>& parsers,
    bool isRequired)
{
    auto elementArray = GetArray(json, key, isRequired);

    std::vector<std::shared_ptr<T>> elements;

    if (elementArray.is_null())
    {
        return elements;
    }

    elements.reserve(elementArray.size());

    for (auto & curJsonValue : elementArray)
    {
        auto action = ParseUtil::GetActionFromJsonValue(curJsonValue.second, parsers);
        if (action != nullptr)
        {
            elements.push_back(action);
        }
    }

    return elements;
}

template <typename T>
T ParseUtil::ExtractJsonValueAndMergeWithDefault(
    const Mso::Json::value& rootJson,
    AdaptiveCardSchemaKey key,
    const T& defaultValue,
    const std::function<T(const Mso::Json::value&, const T&)>& deserializer)
{
    auto jsonObject = ParseUtil::ExtractJsonValue(rootJson, key);
    T result = jsonObject.is_null() ? defaultValue : deserializer(jsonObject, defaultValue);
    return result;
}

template <typename T>
std::shared_ptr<T> ParseUtil::GetActionFromJsonValue(
    const Mso::Json::value& json,
    const std::unordered_map<ActionType, std::function<std::shared_ptr<T>(const Mso::Json::value&)>, EnumHash>& parsers)
{
    if (json.is_null() || !json.is_object())
    {
        throw AdaptiveCardParseException(L"Expected a Json object to extract Action element");
    }
    // Get the action's type
    ActionType actionType = ParseUtil::TryGetActionType(json);

    //Parse it if it's allowed by the current parsers
    if (parsers.find(actionType) != parsers.end())
    {
        // Use the parser that maps to the type
        return parsers.at(actionType)(json);
    }

    return nullptr;
}

}
