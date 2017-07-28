#pragma once

#include "BaseCardElement.h"
#include "BaseActionElement.h"
#include "Enums.h"
#include "stdafx.h"

namespace AdaptiveCards
{
class Container;

class AdaptiveCard
{
public:
    AdaptiveCard();
    AdaptiveCard(std::wstring version, std::wstring minVersion, std::wstring fallbackText, std::wstring backgroundImageUrl);
    AdaptiveCard(
        std::wstring version,
        std::wstring minVersion,
        std::wstring fallbackText,
        std::wstring backgroundImageUrl,
        std::vector<std::shared_ptr<BaseCardElement>>& body,
        std::vector<std::shared_ptr<BaseActionElement>>& actions);

    std::wstring GetVersion() const;
    void SetVersion(const std::wstring value);
    std::wstring GetMinVersion() const;
    void SetMinVersion(const std::wstring value);
    std::wstring GetFallbackText() const;
    void SetFallbackText(const std::wstring value);
    std::wstring GetBackgroundImageUrl () const;
    void SetBackgroundImageUrl(const std::wstring value);

    std::vector<std::shared_ptr<BaseCardElement>>& GetBody();
    const std::vector<std::shared_ptr<BaseCardElement>>& GetBody() const;
    const std::vector<std::shared_ptr<BaseActionElement>>& GetActions() const;

    const CardElementType GetElementType() const;

	static std::shared_ptr<AdaptiveCard> DeserializeFromFile(const std::wstring& jsonFile); // throw(AdaptiveCards::AdaptiveCardParseException)
	static std::shared_ptr<AdaptiveCard> Deserialize(const Mso::Json::value& json); // throw(AdaptiveCards::AdaptiveCardParseException)
	static std::shared_ptr<AdaptiveCard> DeserializeFromString(const std::wstring& jsonString); // throw(AdaptiveCards::AdaptiveCardParseException)
    Mso::Json::value SerializeToJsonValue();
    std::wstring Serialize();

private:
    static const std::unordered_map<CardElementType, std::function<std::shared_ptr<BaseCardElement>(const Mso::Json::value&)>, EnumHash> CardElementParsers;
    static const std::unordered_map<ActionType, std::function<std::shared_ptr<BaseActionElement>(const Mso::Json::value&)>, EnumHash> ActionParsers;
    std::wstring m_version;
    std::wstring m_minVersion;
    std::wstring m_fallbackText;
    std::wstring m_backgroundImageUrl;

    std::vector<std::shared_ptr<BaseCardElement>> m_body;
    std::vector<std::shared_ptr<BaseActionElement>> m_actions;

};
}