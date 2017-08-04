#pragma once

#include "stdafx.h"
#include "Enums.h"
#include <jsondom/ijsondom.h>
#include <jsondom/JsonCommon.h>
#include "ParseUtil.h"
#include "BaseCardElement.h"

namespace AdaptiveCards 
{
class BaseInputElement : public BaseCardElement
{
public:
    BaseInputElement(CardElementType elementType);
    BaseInputElement(CardElementType type, SeparationStyle separationStyle, std::wstring speak);

    std::wstring GetId() const;
    void SetId(const std::wstring& value);

    template <typename T>
    static std::shared_ptr<T> Deserialize(const Mso::Json::value& json);

    bool GetIsRequired() const;
    void SetIsRequired(const bool isRequired);

    virtual std::wstring Serialize() = 0;
    virtual Mso::Json::value SerializeToJsonValue();

private:
    std::wstring m_id;
    bool m_isRequired;
};

template <typename T>
std::shared_ptr<T> BaseInputElement::Deserialize(const Mso::Json::value& json)
{
    std::shared_ptr<T> baseInputElement = BaseCardElement::Deserialize<T>(json);

    ParseUtil::ThrowIfNotJsonObject(json);

    baseInputElement->SetId(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Id, true));
    baseInputElement->SetIsRequired(ParseUtil::GetBool(json, AdaptiveCardSchemaKey::IsRequired, false));

    return baseInputElement;
}
}

