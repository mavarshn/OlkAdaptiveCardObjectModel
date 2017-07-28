#pragma once

#include "stdafx.h"
#include "Enums.h"
#include <jsondom/ijsondom.h>
#include <jsondom/JsonCommon.h>
#include "ParseUtil.h"

namespace AdaptiveCards
{
class BaseActionElement
{
public:
    BaseActionElement(ActionType type, std::wstring speak);
    BaseActionElement(ActionType type);

    virtual ~BaseActionElement();

    std::wstring GetSpeak() const;
    void SetSpeak(const std::wstring value);

    std::wstring GetTitle() const;
    void SetTitle(const std::wstring value);

    const ActionType GetElementType() const;

    virtual std::wstring Serialize() = 0;
    virtual Mso::Json::value SerializeToJsonValue();

    template <typename T>
    static std::shared_ptr<T> Deserialize(const Mso::Json::value& json);

private:
    ActionType m_type;
    std::wstring m_speak;
    std::wstring m_title;
};

template <typename T>
std::shared_ptr<T> BaseActionElement::Deserialize(const Mso::Json::value& json)
{
    std::shared_ptr<T> cardElement = std::make_shared<T>();
    std::shared_ptr<BaseActionElement> BaseActionElement = cardElement;

    ParseUtil::ThrowIfNotJsonObject(json);

    BaseActionElement->SetTitle(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Title, true));
    BaseActionElement->SetSpeak(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Speak));

    return cardElement;
}
}

