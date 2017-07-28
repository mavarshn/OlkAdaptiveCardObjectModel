#include "stdafx.h"
#include "BaseCardElement.h"
#include "HttpAction.h"
#include "ShowCardAction.h"
#include "OpenUrlAction.h"
#include "SubmitAction.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

const std::unordered_map<ActionType, std::function<std::shared_ptr<BaseActionElement>(const Mso::Json::value&)>, EnumHash> BaseCardElement::ActionParsers =
{
    { ActionType::Http, HttpAction::Deserialize },
    { ActionType::OpenUrl, OpenUrlAction::Deserialize },
    { ActionType::ShowCard, ShowCardAction::Deserialize },
    { ActionType::Submit, SubmitAction::Deserialize },
};

BaseCardElement::BaseCardElement(
    CardElementType type,
    SeparationStyle separationStyle,
    std::wstring speak) :
    m_type(type),
    m_separationStyle(separationStyle),
    m_speak(speak)
{
}

BaseCardElement::BaseCardElement(CardElementType type) :
    m_type(type), m_separationStyle(SeparationStyle::Default), m_speak(L"")
{
}

AdaptiveCards::BaseCardElement::~BaseCardElement()
{
}

SeparationStyle BaseCardElement::GetSeparationStyle() const
{
    return m_separationStyle;
}

void BaseCardElement::SetSeparationStyle(const SeparationStyle value)
{
    m_separationStyle = value;
}

std::wstring BaseCardElement::GetSpeak() const
{
    return m_speak;
}

void BaseCardElement::SetSpeak(const std::wstring value)
{
    m_speak = value;
}

const CardElementType AdaptiveCards::BaseCardElement::GetElementType() const
{
    return m_type;
}

Mso::Json::value BaseCardElement::SerializeToJsonValue()
 {
    Mso::Json::value root;
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Type)] = Mso::Json::value(CardElementTypeToString(GetElementType()));
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Speak)] = Mso::Json::value(GetSpeak());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Separation)] = Mso::Json::value(SeparationStyleToString(GetSeparationStyle()));
    return root;
}

std::shared_ptr<BaseActionElement> BaseCardElement::DeserializeSelectAction(const Mso::Json::value & json, AdaptiveCardSchemaKey key)
{
    Mso::Json::value selectActionValue = ParseUtil::ExtractJsonValue(json, key, false);
    if (!selectActionValue.is_null())
    {
        return ParseUtil::GetActionFromJsonValue<BaseActionElement>(selectActionValue, BaseCardElement::ActionParsers);
    }
    return nullptr;
}

Mso::Json::value BaseCardElement::SerializeSelectAction(const std::shared_ptr<BaseActionElement> selectAction)
{
    if (selectAction != nullptr)
    {
        return selectAction->SerializeToJsonValue();
    }
    return Mso::Json::value();
}

