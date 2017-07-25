#pragma once

#include "stdafx.h"
#include "Enums.h"
#include "json/json.h"
#include "ParseUtil.h"
#include "BaseCardElement.h"

namespace AdaptiveCards 
{
class BaseInputElement : public BaseCardElement
{
public:
    BaseInputElement(CardElementType elementType);
    BaseInputElement(CardElementType type, SeparationStyle separationStyle, std::string speak);

    std::string GetId() const;
    void SetId(const std::string value);

    template <typename T>
    static std::shared_ptr<T> Deserialize(const Json::Value& json);

    bool GetIsRequired() const;
    void SetIsRequired(const bool isRequired);

    virtual std::string Serialize() = 0;
    virtual Json::Value SerializeToJsonValue();

private:
    std::string m_id;
    bool m_isRequired;
};

template <typename T>
std::shared_ptr<T> BaseInputElement::Deserialize(const Json::Value& json)
{
    std::shared_ptr<T> baseInputElement = BaseCardElement::Deserialize<T>(json);

    ParseUtil::ThrowIfNotJsonObject(json);

    baseInputElement->SetId(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Id, true));
    baseInputElement->SetIsRequired(ParseUtil::GetBool(json, AdaptiveCardSchemaKey::IsRequired, false));

    return baseInputElement;
}
}

