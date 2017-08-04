#include "stdafx.h"
#include "ParseUtil.h"
#include "AdaptiveCardParseException.h"

namespace AdaptiveCards
{

Mso::Json::value ParseUtil::GetValue(Mso::Json::value const &parent, const std::wstring& name)
{
	if (parent.is_object())
	{
		return parent.get(name);
	}

	return Mso::Json::value::nullvalue();
}

std::wstring ParseUtil::GetString(Mso::Json::value const &parent, const std::wstring& name, const wchar_t *defaultString)
{
	auto val = GetValue(parent, name);
	if (val.is_string())
	{
		return val.as_string();
	}

	return defaultString == nullptr ? std::wstring() : defaultString;
}

int32_t ParseUtil::GetInteger(Mso::Json::value const &parent, const std::wstring& name)
{
	auto val = GetValue(parent, name);
	if (val.is_number())
	{
		return val.as_integer();
	}

	return MAXINT32;
}

bool ParseUtil::GetBoolean(Mso::Json::value const &parent, const std::wstring& name, bool fDefault)
{
	auto val = GetValue(parent, name);

	if (val.is_boolean())
	{
		return val.as_bool();
	}

	return fDefault;
}

void ParseUtil::ThrowIfNotJsonObject(const Mso::Json::value& json)
{
    if (!json.is_object()) {
        throw AdaptiveCardParseException(L"Expected JSON Object\n");
    }
}

void ParseUtil::ExpectString(const Mso::Json::value& json)
{
    if (!json.is_string())
    {
        throw AdaptiveCardParseException(L"The JSON element did not have the expected type 'string'");
    }
}

// TODO: Remove? This code path might not be desirable going forward depending on how we decide to support forward compat. Task 10893205
std::wstring ParseUtil::GetTypeAsString(const Mso::Json::value& json)
{
    std::wstring typeKey = L"type";

    auto val = GetValue(json, typeKey);
	if (!val.is_string())
	{
		throw AdaptiveCardParseException(L"The JSON element is missing the following value: " + typeKey);
	}

    return val.as_string();;
}

std::wstring ParseUtil::TryGetTypeAsString(const Mso::Json::value& json)
{
    try
    {
        return GetTypeAsString(json);
    }
    catch (const AdaptiveCardParseException&)
    {
        return L"";
    }

}

std::wstring ParseUtil::GetString(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = GetValue(json, propertyName);
    if (propertyValue.is_null())
    {
        if (isRequired)
        {
            throw AdaptiveCardParseException(L"Property is required but was found empty: " + propertyName);
        }
        else
        {
            return L"";
        }
    }

    if (!propertyValue.is_string())
    {
        throw AdaptiveCardParseException(L"Value was invalid. Expected type string.");
    }

    return propertyValue.as_string();
}

std::wstring ParseUtil::GetJsonString(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = GetValue(json, propertyName);
    if (propertyValue.is_null())
    {
        if (isRequired)
        {
            throw AdaptiveCardParseException(L"Property is required but was found empty: " + propertyName);
        }
        else
        {
            return L"";
        }
    }

    return propertyValue.to_string();
}

std::wstring ParseUtil::GetValueAsString(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = GetValue(json, propertyName);
    if (propertyValue.is_null())
    {
        if (isRequired)
        {
            throw AdaptiveCardParseException(L"Property is required but was found empty: " + propertyName);
        }
        else
        {
            return L"";
        }
    }

    return propertyValue.as_string();
}

bool ParseUtil::GetBool(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool defaultValue, bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = GetValue(json, propertyName);
    if (propertyValue.is_null())
    {
        if (isRequired)
        {
            throw AdaptiveCardParseException(L"Property is required but was found empty: " + propertyName);
        }
        else
        {
            return defaultValue;
        }
    }

    if (!propertyValue.is_boolean())
    {
        throw AdaptiveCardParseException(L"Value was invalid. Expected type bool.");
    }

    return propertyValue.as_bool();
}

unsigned int ParseUtil::GetUInt(const Mso::Json::value & json, AdaptiveCardSchemaKey key, unsigned int defaultValue, bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = GetValue(json, propertyName);
    if (propertyValue.is_null())
    {
        if (isRequired)
        {
            throw AdaptiveCardParseException(L"Property is required but was found empty: " + propertyName);
        }
        else
        {
            return defaultValue;
        }
    }

    if (!propertyValue.is_number())
    {
        throw AdaptiveCardParseException(L"Value was invalid. Expected type UINT.");
    }

    return propertyValue.as_integer();
}

int ParseUtil::GetInt(const Mso::Json::value & json, AdaptiveCardSchemaKey key, int defaultValue, bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = GetValue(json, propertyName);
    if (propertyValue.is_null())
    {
        if (isRequired)
        {
            throw AdaptiveCardParseException(L"Property is required but was found empty: " + propertyName);
        }
        else
        {
            return defaultValue;
        }
    }

    if (!propertyValue.is_number())
    {
        throw AdaptiveCardParseException(L"Value was invalid. Expected type int.");
    }

    return propertyValue.as_integer();
}

void ParseUtil::ExpectTypeString(const Mso::Json::value& json, CardElementType bodyType)
{
    std::wstring actualType = GetTypeAsString(json);
    std::wstring expectedTypeStr = CardElementTypeToString(bodyType);
    bool isTypeCorrect = expectedTypeStr.compare(actualType) == 0;
    if (!isTypeCorrect)
    {
        throw AdaptiveCardParseException(L"The JSON element did not have the correct type. Expected: " + expectedTypeStr + L", Actual: " + actualType);
    }
}

// throws if the key is missing or the value mapped to the key is the wrong type
void ParseUtil::ExpectKeyAndValueType(const Mso::Json::value& json, const wchar_t* expectedKey, std::function<void(const Mso::Json::value&)> throwIfWrongType)
{
    if (expectedKey == nullptr)
    {
        throw AdaptiveCardParseException(L"null expectedKey");
    }

    auto jsonValue = GetValue(json, expectedKey);
    if (json.is_null())
    {
        throw AdaptiveCardParseException(L"The JSON element is missing the following key: " + std::wstring(expectedKey));
    }

    throwIfWrongType(jsonValue);
}

CardElementType ParseUtil::GetCardElementType(const Mso::Json::value& json)
{
    std::wstring actualType = GetTypeAsString(json);
    try
    {
        return CardElementTypeFromString(actualType);
    }
    catch (const std::out_of_range&)
    {
        throw AdaptiveCardParseException(L"Invalid CardElementType");
    }
}

CardElementType ParseUtil::TryGetCardElementType(const Mso::Json::value& json)
{
    try
    {
        return GetCardElementType(json);
    }
    catch (const AdaptiveCardParseException&)
    {
        return CardElementType::Unsupported;
    }
}

ActionType ParseUtil::GetActionType(const Mso::Json::value& json)
{
    std::wstring actualType = GetTypeAsString(json);
    try
    {
        return ActionTypeFromString(actualType);
    }
    catch (const std::out_of_range&)
    {
        throw AdaptiveCardParseException(L"Invalid ActionType");
    }
}

ActionType ParseUtil::TryGetActionType(const Mso::Json::value& json)
{
    try
    {
        return GetActionType(json);
    }
    catch (const AdaptiveCardParseException&)
    {
        return ActionType::Unsupported;
    }
}

Mso::Json::value ParseUtil::GetArray(
    const Mso::Json::value& json,
    AdaptiveCardSchemaKey key,
    bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto elementArray = GetValue(json, propertyName);
    if (isRequired && elementArray.is_null())
    {
        throw AdaptiveCardParseException(L"Could not parse required key: " + propertyName + L". It was not found");
    }

    if (!elementArray.is_null() && !elementArray.is_array())
    {
        throw AdaptiveCardParseException(L"Could not parse specified key: " + propertyName + L". It was not an array");
    }
    return elementArray;
}

Mso::Json::value ParseUtil::GetJsonValueFromString(const std::wstring& jsonString)
{
    Mso::Json::value jsonValue;
    try
    {
        Mso::TCntPtr<Mso::Json::IJsonDom> spdomJson = Mso::Json::CreateJsonDom(jsonString.c_str());
        jsonValue = spdomJson->ParseAll();
    }
    catch(...)
    {
        throw AdaptiveCardParseException(L"Expected JSON Object\n");
    }

    return jsonValue;
}

Mso::Json::value ParseUtil::ExtractJsonValue(const Mso::Json::value& json, AdaptiveCardSchemaKey key, bool isRequired)
{
    std::wstring propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = GetValue(json, propertyName);
    if (isRequired && propertyValue.is_null())
    {
        throw AdaptiveCardParseException(L"Could not extract specified key: " + propertyName + L".");
    }
    return propertyValue;
}

ParseUtil::ParseUtil()
{
}

ParseUtil::~ParseUtil()
{
}

}