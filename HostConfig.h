#pragma once

#include "stdafx.h"
#include "Enums.h"
#include <jsondom/ijsondom.h>
#include <jsondom/JsonCommon.h>

namespace AdaptiveCards
{
struct SpacingDefinition
{
    unsigned int left = 0;
    unsigned int right = 0;
    unsigned int top = 0;
    unsigned int bottom = 0;

    static SpacingDefinition Deserialize(const Mso::Json::value& json, const SpacingDefinition& defaultValue);
};

struct FontSizesConfig
{
    unsigned int smallFontSize = 10;
    unsigned int normalFontSize = 12;
    unsigned int mediumFontSize = 14;
    unsigned int largeFontSize = 17;
    unsigned int extraLargeFontSize = 20;

    static FontSizesConfig Deserialize(const Mso::Json::value& json, const FontSizesConfig& defaultValue);
};

struct ColorConfig
{
    std::wstring normal;
    std::wstring subtle;

    static ColorConfig Deserialize(const Mso::Json::value& json, const ColorConfig& defaultValue);
};

struct ColorsConfig
{
    ColorConfig defaultColor = { L"#FF000000", L"#B2000000" };
    ColorConfig accent = { L"#FF0000FF", L"#B20000FF" };
    ColorConfig dark = { L"#FF101010", L"#B2101010" };
    ColorConfig light = { L"#FFFFFFFF", L"#B2FFFFFF" };
    ColorConfig good = { L"#FF008000", L"#B2008000" };
    ColorConfig warning = { L"#FFFFD700", L"#B2FFD700" };
    ColorConfig attention = { L"#FF8B0000", L"#B28B0000" };

    static ColorsConfig Deserialize(const Mso::Json::value& json, const ColorsConfig& defaultValue);
};

struct TextConfig
{
    TextWeight weight = TextWeight::Normal;
    TextSize size = TextSize::Normal;
    TextColor color = TextColor::Default;
    bool isSubtle = false;

    static TextConfig Deserialize(const Mso::Json::value& json, const TextConfig& defaultValue);
};

struct SeparationConfig
{
    unsigned int spacing = 10;
    unsigned int lineThickness = 0;
    std::wstring lineColor = L"#FF101010";

    static SeparationConfig Deserialize(const Mso::Json::value& json, const SeparationConfig& defaultValue);
};
struct ImageSizesConfig
{
    unsigned int smallSize = 80;
    unsigned int mediumSize = 120;
    unsigned int largeSize = 180;

    static ImageSizesConfig Deserialize(const Mso::Json::value& json, const ImageSizesConfig& defaultValue);
};

struct TextBlockConfig
{
    SeparationConfig smallSeparation;
    SeparationConfig normalSeparation;
    SeparationConfig mediumSeparation;
    SeparationConfig largeSeparation;
    SeparationConfig extraLargeSeparation;

    static TextBlockConfig Deserialize(const Mso::Json::value& json, const TextBlockConfig& defaultValue);
};

struct ImageSetConfig
{
    ImageSize imageSize = ImageSize::Medium;
    SeparationConfig separation;

    static ImageSetConfig Deserialize(const Mso::Json::value& json, const ImageSetConfig& defaultValue);
};

struct ColumnConfig
{
    SeparationConfig separation;
    static ColumnConfig Deserialize(const Mso::Json::value& json, const ColumnConfig& defaultValue);
};

struct ContainerStyleConfig
{
    std::wstring backgroundColor = L"#00FFFFFF";
    std::wstring borderColor = L"#00FFFFFF";
    SpacingDefinition borderThickness;
    SpacingDefinition padding;

    static ContainerStyleConfig Deserialize(const Mso::Json::value& json, const ContainerStyleConfig& defaultValue);
};

struct ContainerConfig
{
    SeparationConfig separation;
    ContainerStyleConfig normal;
    ContainerStyleConfig emphasis = { L"#FFEEEEEE", L"#FFAAAAAA", SpacingDefinition{ 1, 1, 1, 1 }, SpacingDefinition{10, 10, 10, 10 } };

    static ContainerConfig Deserialize(const Mso::Json::value& json, const ContainerConfig& defaultValue);
};

struct ColumnSetConfig
{
    SeparationConfig separation;

    static ColumnSetConfig Deserialize(const Mso::Json::value& json, const ColumnSetConfig& defaultValue);
};

struct ImageConfig
{
    SeparationConfig separation;

    static ImageConfig Deserialize(const Mso::Json::value& json, const ImageConfig& defaultValue);
};

struct AdaptiveCardConfig
{
    SpacingDefinition padding = { 8, 8, 8, 8 };
    std::wstring backgroundColor = L"#FFFFFFFF";

    static AdaptiveCardConfig Deserialize(const Mso::Json::value& json, const AdaptiveCardConfig& defaultValue);
};

struct FactSetConfig
{
    TextConfig title = { TextWeight::Bolder };
    TextConfig value;
    unsigned int spacing = 20;
    SeparationConfig separation;

    static FactSetConfig Deserialize(const Mso::Json::value& json, const FactSetConfig& defaultValue);
};

struct ShowCardActionConfig
{
    ActionMode actionMode = ActionMode::InlineEdgeToEdge;
    std::wstring backgroundColor = L"#FFF8F8F8";
    unsigned int inlineTopMargin = 16;
    SpacingDefinition padding = { 16, 16, 16, 16 };

    static ShowCardActionConfig Deserialize(const Mso::Json::value& json, const ShowCardActionConfig& defaultValue);
};

struct ActionsConfig
{
    ShowCardActionConfig showCard;
    ActionsOrientation actionsOrientation = ActionsOrientation::Horizontal;
    ActionAlignment actionAlignment = ActionAlignment::Center;
    unsigned int buttonSpacing = 8;
    unsigned int maxActions = 5;
    SeparationConfig separation;

    static ActionsConfig Deserialize(const Mso::Json::value& json, const ActionsConfig& defaultValue);
};

struct DateInputConfig
{
    SeparationConfig separation;

    static DateInputConfig Deserialize(const Mso::Json::value& json, const DateInputConfig& defaultValue);
};

struct TimeInputConfig
{
    SeparationConfig separation;

    static TimeInputConfig Deserialize(const Mso::Json::value& json, const TimeInputConfig& defaultValue);
};

struct NumberInputConfig
{
    SeparationConfig separation;

    static NumberInputConfig Deserialize(const Mso::Json::value& json, const NumberInputConfig& defaultValue);
};

struct ToggleInputConfig
{
    SeparationConfig separation;

    static ToggleInputConfig Deserialize(const Mso::Json::value& json, const ToggleInputConfig& defaultValue);
};

struct TextInputConfig
{
    SeparationConfig separation;

    static TextInputConfig Deserialize(const Mso::Json::value& json, const TextInputConfig& defaultValue);
};

struct ChoiceSetConfig
{
    SeparationConfig separation;

    static ChoiceSetConfig Deserialize(const Mso::Json::value& json, const ChoiceSetConfig& defaultValue);
};

struct HostConfig
{
    std::wstring fontFamily = L"Calibri";
    FontSizesConfig fontSizes;
    bool supportsInteractivity = true;
    ColorsConfig colors;
    ImageSizesConfig imageSizes;
    unsigned int maxActions = 5;
    SeparationConfig strongSeparation = { 20, 1, L"#FF707070" };
    AdaptiveCardConfig adaptiveCard;
    ImageSetConfig imageSet;
    ImageConfig image;
    FactSetConfig factSet;
    ColumnConfig column;
    ContainerConfig container;
    ColumnSetConfig columnSet;
    TextBlockConfig textBlock;
    DateInputConfig dateInput;
    TimeInputConfig timeInput;
    NumberInputConfig numberInput;
    ToggleInputConfig toggleInput;
    TextInputConfig textInput;
    ChoiceSetConfig choiceSet;
    ActionsConfig actions;

    static HostConfig Deserialize(const Mso::Json::value& json);
    static HostConfig DeserializeFromString(const std::wstring jsonString);
};
}