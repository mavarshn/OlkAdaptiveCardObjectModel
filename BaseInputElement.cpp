#include "stdafx.h"
#include "BaseInputElement.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

BaseInputElement::BaseInputElement(CardElementType elementType) :
    BaseCardElement(elementType)
{
}

BaseInputElement::BaseInputElement(CardElementType elementType, SeparationStyle separationStyle, std::wstring speak) :
    BaseCardElement(elementType, separationStyle, speak)
{
}

std::wstring BaseInputElement::GetId() const
{
    return m_id;
}

void BaseInputElement::SetId(const std::wstring value)
{
    m_id = value;
}

bool BaseInputElement::GetIsRequired() const
{
    return m_isRequired;
}

void BaseInputElement::SetIsRequired(const bool value)
{
    m_isRequired = value;
}

Mso::Json::value BaseInputElement::SerializeToJsonValue()
{
    Mso::Json::value root = BaseCardElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Id)] = Mso::Json::value(GetId());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::IsRequired)] = Mso::Json::value(GetIsRequired());

    return root;
}

