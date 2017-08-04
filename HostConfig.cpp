#include "stdafx.h"
#include "stdafx.h"
#include "HostConfig.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

HostConfig HostConfig::DeserializeFromString(const std::wstring& jsonString)
{
    return HostConfig::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

HostConfig HostConfig::Deserialize(const Mso::Json::value& json)
{
    HostConfig result;
    std::wstring fontFamily = ParseUtil::GetString(json, AdaptiveCardSchemaKey::FontFamily);
    result.fontFamily = fontFamily == L"" ? fontFamily : result.fontFamily;

    result.supportsInteractivity = ParseUtil::GetBool(
        json, AdaptiveCardSchemaKey::SupportsInteractivity, result.supportsInteractivity);
    result.maxActions = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::MaxActions, result.maxActions);

    result.fontSizes = ParseUtil::ExtractJsonValueAndMergeWithDefault<FontSizesConfig>(
        json, AdaptiveCardSchemaKey::FontSizes, result.fontSizes, FontSizesConfig::Deserialize);

    result.colors = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorsConfig>(
        json, AdaptiveCardSchemaKey::Colors, result.colors, ColorsConfig::Deserialize);

    result.imageSizes = ParseUtil::ExtractJsonValueAndMergeWithDefault<ImageSizesConfig>(
        json, AdaptiveCardSchemaKey::ImageSizes, result.imageSizes, ImageSizesConfig::Deserialize);

    result.strongSeparation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::StrongSeparation, result.strongSeparation, SeparationConfig::Deserialize);

    result.adaptiveCard = ParseUtil::ExtractJsonValueAndMergeWithDefault<AdaptiveCardConfig>(
        json, AdaptiveCardSchemaKey::AdaptiveCard, result.adaptiveCard, AdaptiveCardConfig::Deserialize);

    return result;
}

FontSizesConfig FontSizesConfig::Deserialize(const Mso::Json::value& json, const FontSizesConfig& defaultValue)
{
    FontSizesConfig result;
    result.smallFontSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Small, defaultValue.smallFontSize);
    result.normalFontSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Normal, defaultValue.normalFontSize);
    result.mediumFontSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Medium, defaultValue.mediumFontSize);
    result.largeFontSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Large, defaultValue.largeFontSize);
    result.extraLargeFontSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::ExtraLarge, defaultValue.extraLargeFontSize);
    return result;
}

SpacingDefinition SpacingDefinition::Deserialize(const Mso::Json::value& json, const SpacingDefinition& defaultValue)
{

    SpacingDefinition result;
    result.left = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Left, defaultValue.left);
    result.right = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Right, defaultValue.right);
    result.top = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Top, defaultValue.top);
    result.bottom = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Bottom, defaultValue.bottom);

    return result;
}

ColorConfig ColorConfig::Deserialize(const Mso::Json::value& json, const ColorConfig& defaultValue)
{
    ColorConfig result;
    std::wstring normal = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Normal);
    result.normal = normal == L"" ? defaultValue.normal : normal;

    std::wstring subtle = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Subtle);
    result.subtle = subtle == L"" ? defaultValue.subtle: subtle;

    return result;
}

ColorsConfig ColorsConfig::Deserialize(const Mso::Json::value& json, const ColorsConfig& defaultValue)
{
    ColorsConfig result;
    auto colorDeserializer = &ColorConfig::Deserialize;

    result.defaultColor = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorConfig>(
        json, AdaptiveCardSchemaKey::Default, defaultValue.defaultColor, colorDeserializer);

    result.accent = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorConfig>(
        json, AdaptiveCardSchemaKey::Accent, defaultValue.accent, colorDeserializer);

    result.dark = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorConfig>(
        json, AdaptiveCardSchemaKey::Dark, defaultValue.dark, colorDeserializer);

    result.light = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorConfig>(
        json, AdaptiveCardSchemaKey::Light, defaultValue.light, colorDeserializer);

    result.good = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorConfig>(
        json, AdaptiveCardSchemaKey::Good, defaultValue.good, colorDeserializer);

    result.warning = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorConfig>(
        json, AdaptiveCardSchemaKey::Warning, defaultValue.warning, colorDeserializer);

    result.attention = ParseUtil::ExtractJsonValueAndMergeWithDefault<ColorConfig>(
        json, AdaptiveCardSchemaKey::Attention, defaultValue.attention, colorDeserializer);

    return result;
}

TextConfig TextConfig::Deserialize(const Mso::Json::value& json, const TextConfig& defaultValue)
{
    TextConfig result;
    result.weight = ParseUtil::GetEnumValue<TextWeight>(
        json, AdaptiveCardSchemaKey::Weight, defaultValue.weight, TextWeightFromString);

    result.size = ParseUtil::GetEnumValue<TextSize>(
        json, AdaptiveCardSchemaKey::Size, defaultValue.size, TextSizeFromString);

    result.color = ParseUtil::GetEnumValue<TextColor>(
        json, AdaptiveCardSchemaKey::Color, defaultValue.color, TextColorFromString);

    result.isSubtle = ParseUtil::GetBool(
        json, AdaptiveCardSchemaKey::IsSubtle, defaultValue.isSubtle);

    return result;
}

SeparationConfig SeparationConfig::Deserialize(const Mso::Json::value& json, const SeparationConfig& defaultValue)
{
    SeparationConfig result;
    std::wstring lineColor = ParseUtil::GetString(json, AdaptiveCardSchemaKey::LineColor);
    result.lineColor = lineColor == L"" ? defaultValue.lineColor : lineColor;

    result.spacing = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Spacing, defaultValue.spacing);
    result.lineThickness = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::LineThickness, defaultValue.lineThickness);

    return result;
}

ImageSizesConfig ImageSizesConfig::Deserialize(const Mso::Json::value& json, const ImageSizesConfig& defaultValue)
{
    ImageSizesConfig result;
    result.smallSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Small, defaultValue.smallSize);
    result.mediumSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Medium, defaultValue.mediumSize);
    result.largeSize = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Large, defaultValue.largeSize);

    return result;
}

AdaptiveCardConfig AdaptiveCardConfig::Deserialize(const Mso::Json::value& json, const AdaptiveCardConfig& defaultValue)
{
    AdaptiveCardConfig result;

    result.padding = ParseUtil::ExtractJsonValueAndMergeWithDefault<SpacingDefinition>(
        json, AdaptiveCardSchemaKey::Padding, defaultValue.padding, SpacingDefinition::Deserialize);

    std::wstring backgroundColor = ParseUtil::GetString(json, AdaptiveCardSchemaKey::BackgroundColor);
    result.backgroundColor = backgroundColor == L"" ? defaultValue.backgroundColor : backgroundColor;

    return result;
}

ImageSetConfig ImageSetConfig::Deserialize(const Mso::Json::value& json, const ImageSetConfig& defaultValue)
{
    ImageSetConfig result;
    result.imageSize = ParseUtil::GetEnumValue<ImageSize>(
        json, AdaptiveCardSchemaKey::ImageSet, defaultValue.imageSize, ImageSizeFromString);

    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

ImageConfig ImageConfig::Deserialize(const Mso::Json::value& json, const ImageConfig& defaultValue)
{
    ImageConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);
    return result;
}

FactSetConfig FactSetConfig::Deserialize(const Mso::Json::value& json, const FactSetConfig& defaultValue)
{
    FactSetConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    result.spacing = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::Spacing, defaultValue.spacing);
    result.title = ParseUtil::ExtractJsonValueAndMergeWithDefault<TextConfig>(
        json, AdaptiveCardSchemaKey::Title, defaultValue.title, TextConfig::Deserialize);

    result.value = ParseUtil::ExtractJsonValueAndMergeWithDefault<TextConfig>(
        json, AdaptiveCardSchemaKey::Value, defaultValue.value, TextConfig::Deserialize);

    return result;
}

ColumnConfig ColumnConfig::Deserialize(const Mso::Json::value& json, const ColumnConfig& defaultValue)
{
    ColumnConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

ContainerStyleConfig ContainerStyleConfig::Deserialize(const Mso::Json::value& json, const ContainerStyleConfig& defaultValue)
{
    ContainerStyleConfig result;
    std::wstring backgroundColor = ParseUtil::GetString(json, AdaptiveCardSchemaKey::BackgroundColor);
    result.backgroundColor = backgroundColor == L"" ? defaultValue.backgroundColor : backgroundColor;

    std::wstring borderColor = ParseUtil::GetString(json, AdaptiveCardSchemaKey::BorderColor);
    result.borderColor = borderColor == L"" ? defaultValue.borderColor : borderColor;

    result.borderThickness = ParseUtil::ExtractJsonValueAndMergeWithDefault<SpacingDefinition>(
        json, AdaptiveCardSchemaKey::BorderThickness, defaultValue.borderThickness, SpacingDefinition::Deserialize);

    result.padding = ParseUtil::ExtractJsonValueAndMergeWithDefault<SpacingDefinition>(
        json, AdaptiveCardSchemaKey::Padding, defaultValue.padding, SpacingDefinition::Deserialize);

    return result;

}

ContainerConfig ContainerConfig::Deserialize(const Mso::Json::value& json, const ContainerConfig& defaultValue)
{
    ContainerConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    result.emphasis = ParseUtil::ExtractJsonValueAndMergeWithDefault<ContainerStyleConfig>(
        json, AdaptiveCardSchemaKey::Emphasis, defaultValue.emphasis, ContainerStyleConfig::Deserialize);

    result.normal = ParseUtil::ExtractJsonValueAndMergeWithDefault<ContainerStyleConfig>(
        json, AdaptiveCardSchemaKey::Normal, defaultValue.normal, ContainerStyleConfig::Deserialize);

    return result;
}

ColumnSetConfig ColumnSetConfig::Deserialize(const Mso::Json::value& json, const ColumnSetConfig& defaultValue)
{
    ColumnSetConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

TextBlockConfig TextBlockConfig::Deserialize(const Mso::Json::value& json, const TextBlockConfig& defaultValue)
{
    TextBlockConfig result;
    result.extraLargeSeparation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::ExtraLarge, defaultValue.extraLargeSeparation, SeparationConfig::Deserialize);

    result.largeSeparation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Large, defaultValue.largeSeparation, SeparationConfig::Deserialize);

    result.mediumSeparation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Medium, defaultValue.mediumSeparation, SeparationConfig::Deserialize);

    result.normalSeparation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Normal, defaultValue.normalSeparation, SeparationConfig::Deserialize);

    result.smallSeparation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Small, defaultValue.smallSeparation, SeparationConfig::Deserialize);

    return result;
}

DateInputConfig DateInputConfig::Deserialize(const Mso::Json::value& json, const DateInputConfig& defaultValue)
{
    DateInputConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

TimeInputConfig TimeInputConfig::Deserialize(const Mso::Json::value& json, const TimeInputConfig& defaultValue)
{
    TimeInputConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

NumberInputConfig NumberInputConfig::Deserialize(const Mso::Json::value& json, const NumberInputConfig& defaultValue)
{
    NumberInputConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

ToggleInputConfig ToggleInputConfig::Deserialize(const Mso::Json::value& json, const ToggleInputConfig& defaultValue)
{
    ToggleInputConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

TextInputConfig TextInputConfig::Deserialize(const Mso::Json::value& json, const TextInputConfig& defaultValue)
{
    TextInputConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

ChoiceSetConfig ChoiceSetConfig::Deserialize(const Mso::Json::value& json, const ChoiceSetConfig& defaultValue)
{
    ChoiceSetConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    return result;
}

ShowCardActionConfig ShowCardActionConfig::Deserialize(const Mso::Json::value&json, const ShowCardActionConfig& defaultValue)
{
    ShowCardActionConfig result;
    result.actionMode = ParseUtil::GetEnumValue<ActionMode>(
        json, AdaptiveCardSchemaKey::ActionMode, defaultValue.actionMode, ActionModeFromString);

    std::wstring backgroundColor = ParseUtil::GetString(json, AdaptiveCardSchemaKey::BackgroundColor);
    result.backgroundColor = backgroundColor == L"" ? defaultValue.backgroundColor : backgroundColor;

    result.inlineTopMargin = ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::InlineTopMargin, defaultValue.inlineTopMargin);
    result.padding = ParseUtil::ExtractJsonValueAndMergeWithDefault<SpacingDefinition>(
        json, AdaptiveCardSchemaKey::Padding, defaultValue.padding, SpacingDefinition::Deserialize);

    return result;
}

ActionsConfig ActionsConfig::Deserialize(const Mso::Json::value& json, const ActionsConfig& defaultValue)
{
    ActionsConfig result;
    result.separation = ParseUtil::ExtractJsonValueAndMergeWithDefault<SeparationConfig>(
        json, AdaptiveCardSchemaKey::Separation, defaultValue.separation, SeparationConfig::Deserialize);

    result.actionsOrientation = ParseUtil::GetEnumValue<ActionsOrientation>(
        json, AdaptiveCardSchemaKey::ActionsOrientation, defaultValue.actionsOrientation, ActionsOrientationFromString);

    result.actionAlignment = ParseUtil::GetEnumValue<ActionAlignment>(
        json, AdaptiveCardSchemaKey::ActionAlignment, defaultValue.actionAlignment, ActionAlignmentFromString);

    result.buttonSpacing = ParseUtil::GetUInt(
        json, AdaptiveCardSchemaKey::ButtonSpacing, defaultValue.buttonSpacing);

    result.maxActions = ParseUtil::GetUInt(
        json, AdaptiveCardSchemaKey::MaxActions, defaultValue.maxActions);

    result.showCard = ParseUtil::ExtractJsonValueAndMergeWithDefault<ShowCardActionConfig>(
        json, AdaptiveCardSchemaKey::ShowCard, defaultValue.showCard, ShowCardActionConfig::Deserialize);

    return result;
}
