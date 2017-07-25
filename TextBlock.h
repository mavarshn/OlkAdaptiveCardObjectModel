#pragma once

#include "stdafx.h"
#include "BaseCardElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class TextBlock : public BaseCardElement
{
public:
    TextBlock();
    TextBlock(SeparationStyle separationStyle,
        std::string speak,
        std::string text,
        TextSize textSize,
        TextWeight textWeight,
        TextColor textColor,
        bool isSubtle,
        bool wrap,
        int maxLines,
        HorizontalAlignment hAlignment);

    static std::shared_ptr<TextBlock> Deserialize(const Json::Value& root);
    static std::shared_ptr<TextBlock> DeserializeFromString(const std::string& jsonString);

    virtual std::string Serialize();
    virtual Json::Value SerializeToJsonValue();

    std::string GetText() const;
    void SetText(const std::string value);

    TextSize GetTextSize() const;
    void SetTextSize(const TextSize value);

    TextWeight GetTextWeight() const;
    void SetTextWeight(const TextWeight value);

    TextColor GetTextColor() const;
    void SetTextColor(const TextColor value);

    bool GetWrap() const;
    void SetWrap(const bool value);

    bool GetIsSubtle() const;
    void SetIsSubtle(const bool value);

    unsigned int GetMaxLines() const;
    void SetMaxLines(const unsigned int value);

    HorizontalAlignment GetHorizontalAlignment() const;
    void SetHorizontalAlignment(const HorizontalAlignment value);

private:
    std::string m_text;
    TextSize m_textSize;
    TextWeight m_textWeight;
    TextColor m_textColor;
    bool m_isSubtle;
    bool m_wrap;
    unsigned int m_maxLines;
    HorizontalAlignment m_hAlignment;
};
}