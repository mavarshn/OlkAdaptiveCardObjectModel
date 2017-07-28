#include "stdafx.h"
#include "SharedAdaptiveCard.h"
#include "ChoiceSetInput.h"
#include "ColumnSet.h"
#include "Container.h"
#include "DateInput.h"
#include "FactSet.h"
#include "HttpAction.h"
#include "Image.h"
#include "ImageSet.h"
#include "NumberInput.h"
#include "OpenUrlAction.h"
#include "ParseUtil.h"
#include "ShowCardAction.h"
#include "SubmitAction.h"
#include "TextBlock.h"
#include "TextInput.h"
#include "TimeInput.h"
#include "ToggleInput.h"

using namespace AdaptiveCards;

const std::unordered_map<CardElementType, std::function<std::shared_ptr<BaseCardElement>(const Mso::Json::value&)>, EnumHash> AdaptiveCard::CardElementParsers =
{
    { CardElementType::Container, Container::Deserialize },
    { CardElementType::ColumnSet, ColumnSet::Deserialize },
    { CardElementType::FactSet, FactSet::Deserialize },
    { CardElementType::Image, AdaptiveCards::Image::Deserialize },
    { CardElementType::ImageSet, ImageSet::Deserialize },
    { CardElementType::TextBlock, TextBlock::Deserialize },
    { CardElementType::ChoiceSetInput, ChoiceSetInput::Deserialize },
    { CardElementType::DateInput, DateInput::Deserialize },
    { CardElementType::NumberInput, NumberInput::Deserialize },
    { CardElementType::TextInput, TextInput::Deserialize },
    { CardElementType::TimeInput, TimeInput::Deserialize },
    { CardElementType::ToggleInput, ToggleInput::Deserialize },
};

const std::unordered_map<ActionType, std::function<std::shared_ptr<BaseActionElement>(const Mso::Json::value&)>, EnumHash> AdaptiveCard::ActionParsers =
{
    { ActionType::Http, HttpAction::Deserialize },
    { ActionType::OpenUrl, OpenUrlAction::Deserialize },
    { ActionType::ShowCard, ShowCardAction::Deserialize },
    { ActionType::Submit, SubmitAction::Deserialize },
};

AdaptiveCard::AdaptiveCard()
{
}

AdaptiveCard::AdaptiveCard(std::wstring version, std::wstring minVersion, std::wstring fallbackText, std::wstring backgroundImageUrl) :
    m_version(version),
    m_minVersion(minVersion),
    m_fallbackText(fallbackText),
    m_backgroundImageUrl(backgroundImageUrl)
{
}

AdaptiveCard::AdaptiveCard(std::wstring version, std::wstring minVersion, std::wstring fallbackText, std::wstring backgroundImageUrl, std::vector<std::shared_ptr<BaseCardElement>>& body, std::vector<std::shared_ptr<BaseActionElement>>& actions) :
    m_version(version),
    m_minVersion(minVersion),
    m_fallbackText(fallbackText),
    m_backgroundImageUrl(backgroundImageUrl),
    m_body(body),
    m_actions(actions)
{
}

std::shared_ptr<AdaptiveCard> AdaptiveCard::DeserializeFromFile(const std::wstring& jsonFile) //throw (AdaptiveCards::AdaptiveCardParseException)
{
    std::ifstream jsonFileStream(jsonFile);

    auto root = Mso::Json::value::parse(jsonFileStream);

    return AdaptiveCard::Deserialize(root);
}

std::shared_ptr<AdaptiveCard> AdaptiveCard::Deserialize(const Mso::Json::value& json) //throw(AdaptiveCards::AdaptiveCardParseException)
{
    ParseUtil::ThrowIfNotJsonObject(json);

    // Verify this is an adaptive card
    ParseUtil::ExpectTypeString(json, CardElementType::AdaptiveCard);

    std::wstring version = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Version);
    std::wstring minVersion = ParseUtil::GetString(json, AdaptiveCardSchemaKey::MinVersion);
    std::wstring fallbackText = ParseUtil::GetString(json, AdaptiveCardSchemaKey::FallbackText);
    std::wstring backgroundImageUrl = ParseUtil::GetString(json, AdaptiveCardSchemaKey::BackgroundImageUrl);

    // Parse body
    auto body = ParseUtil::GetElementCollection<BaseCardElement>(json, AdaptiveCardSchemaKey::Body, AdaptiveCard::CardElementParsers, true);

    // Parse actions if present
    auto actions = ParseUtil::GetActionCollection<BaseActionElement>(json, AdaptiveCardSchemaKey::Actions, AdaptiveCard::ActionParsers);

    auto result = std::make_shared<AdaptiveCard>(version, minVersion, fallbackText, backgroundImageUrl, body, actions);
    return result;
}

Mso::Json::value AdaptiveCard::SerializeToJsonValue()
{
    Mso::Json::value root;
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Type)] = Mso::Json::value(CardElementTypeToString(CardElementType::AdaptiveCard));
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Version)] = Mso::Json::value(GetVersion());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::MinVersion)] = Mso::Json::value(GetMinVersion());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::FallbackText)] = Mso::Json::value(GetFallbackText());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::BackgroundImageUrl)] = Mso::Json::value(GetBackgroundImageUrl());

    std::wstring bodyPropertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Body);
    root[bodyPropertyName] = Mso::Json::value::array();
    int i = 0;
    for (const auto& cardElement : GetBody())
    {
        root[bodyPropertyName][i++] = cardElement->SerializeToJsonValue();
    }

    std::wstring actionsPropertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Actions);
    root[actionsPropertyName] = Mso::Json::value::array();
    i = 0;
    for (const auto& action : GetActions())
    {
        root[actionsPropertyName][i++] = action->SerializeToJsonValue();
    }

    return root;
}

std::wstring AdaptiveCard::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

std::shared_ptr<AdaptiveCard> AdaptiveCard::DeserializeFromString(const std::wstring& jsonString) //throw(AdaptiveCards::AdaptiveCardParseException)
{
    return AdaptiveCard::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring AdaptiveCard::GetVersion() const
{
    return m_version;
}

void AdaptiveCard::SetVersion(const std::wstring value)
{
    m_version = value;
}

std::wstring AdaptiveCard::GetMinVersion() const
{
    return m_minVersion;
}

void AdaptiveCard::SetMinVersion(const std::wstring value)
{
    m_minVersion = value;
}

std::wstring AdaptiveCard::GetFallbackText() const
{
    return m_fallbackText;
}

void AdaptiveCard::SetFallbackText(const std::wstring value)
{
    m_fallbackText = value;
}

std::wstring AdaptiveCard::GetBackgroundImageUrl() const
{
    return m_backgroundImageUrl;
}

void AdaptiveCard::SetBackgroundImageUrl(const std::wstring value)
{
    m_backgroundImageUrl = value;
}

const CardElementType AdaptiveCard::GetElementType() const
{
    return CardElementType::AdaptiveCard;
}

const std::vector<std::shared_ptr<BaseCardElement>>& AdaptiveCard::GetBody() const
{
    return m_body;
}

std::vector<std::shared_ptr<BaseCardElement>>& AdaptiveCard::GetBody()
{
    return m_body;
}

const std::vector<std::shared_ptr<BaseActionElement>>& AdaptiveCard::GetActions() const
{
    return m_actions;
}
