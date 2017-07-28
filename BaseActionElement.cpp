#include "stdafx.h"
#include "BaseActionElement.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

BaseActionElement::BaseActionElement(
    ActionType type,
    std::wstring speak) :
    m_type(type),
    m_speak(speak)
{
}

BaseActionElement::BaseActionElement(ActionType type) :
    m_type(type), 
    m_speak(L"")
{
}

AdaptiveCards::BaseActionElement::~BaseActionElement()
{
}

std::wstring BaseActionElement::GetSpeak() const
{
    return m_speak;
}

void BaseActionElement::SetSpeak(const std::wstring value)
{
    m_speak = value;
}

std::wstring BaseActionElement::GetTitle() const
{
    return m_title;
}

void BaseActionElement::SetTitle(const std::wstring value)
{
    m_title = value;
}

const ActionType AdaptiveCards::BaseActionElement::GetElementType() const
{
    return m_type;
}

Mso::Json::value BaseActionElement::SerializeToJsonValue()
{
    Mso::Json::value root;
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Type)] = Mso::Json::value(ActionTypeToString(GetElementType()));
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Speak)] = Mso::Json::value(GetSpeak());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title)] = Mso::Json::value(GetTitle());
    return root;
}

