#pragma once

#include "stdafx.h"
#include "Enums.h"
#include <jsondom/ijsondom.h>
#include <jsondom/JsonCommon.h>
#include "BaseActionElement.h"
#include "ParseUtil.h"

namespace AdaptiveCards
{
class Container;
class BaseCardElement
{
public:
    BaseCardElement(CardElementType type, SeparationStyle separationStyle, std::wstring speak);
    BaseCardElement(CardElementType type);

    virtual ~BaseCardElement();

    SeparationStyle GetSeparationStyle() const;
    void SetSeparationStyle(const SeparationStyle value);

    std::wstring GetSpeak() const;
    void SetSpeak(const std::wstring& value);

    const CardElementType GetElementType() const;

    virtual std::wstring Serialize() = 0;

    template <typename T>
    static std::shared_ptr<T> Deserialize(const Mso::Json::value& json);

    virtual Mso::Json::value SerializeToJsonValue();

protected:
    static std::shared_ptr<BaseActionElement> DeserializeSelectAction(const Mso::Json::value& json, AdaptiveCardSchemaKey key);
    static Mso::Json::value SerializeSelectAction(const std::shared_ptr<BaseActionElement> selectAction);

private:
    static const std::unordered_map<ActionType, std::function<std::shared_ptr<BaseActionElement>(const Mso::Json::value&)>, EnumHash> ActionParsers;
    CardElementType m_type;
    SeparationStyle m_separationStyle;
    std::wstring m_speak;
};

template <typename T>
std::shared_ptr<T> BaseCardElement::Deserialize(const Mso::Json::value& json)
{
    std::shared_ptr<T> cardElement = std::make_shared<T>();
    std::shared_ptr<BaseCardElement> baseCardElement = cardElement;

    ParseUtil::ThrowIfNotJsonObject(json);

    baseCardElement->SetSpeak(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Speak));
    baseCardElement->SetSeparationStyle(
            ParseUtil::GetEnumValue<SeparationStyle>(json, AdaptiveCardSchemaKey::Separation, SeparationStyle::Default, SeparationStyleFromString));

    return cardElement;
}
}

