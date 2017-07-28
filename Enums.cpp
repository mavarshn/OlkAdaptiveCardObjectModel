#include "stdafx.h"
#include "Enums.h"

namespace AdaptiveCards
{
static std::unordered_map<AdaptiveCardSchemaKey, std::wstring, EnumHash> AdaptiveCardSchemaKeyEnumToName =
{
    { AdaptiveCardSchemaKey::Accent,  L"accent" },
    { AdaptiveCardSchemaKey::ActionAlignment,  L"actionAlignment" },
    { AdaptiveCardSchemaKey::ActionMode,  L"actionMode" },
    { AdaptiveCardSchemaKey::Actions,  L"actions" },
    { AdaptiveCardSchemaKey::ActionSetConfig,  L"actionSetConfig" },
    { AdaptiveCardSchemaKey::ActionsOrientation,  L"actionsOrientation" },
    { AdaptiveCardSchemaKey::AdaptiveCard,  L"adaptiveCard" },
    { AdaptiveCardSchemaKey::AltText,  L"altText" },
    { AdaptiveCardSchemaKey::Attention,  L"attention" },
    { AdaptiveCardSchemaKey::BackgroundColor,  L"backgroundColor" },
    { AdaptiveCardSchemaKey::BackgroundImageUrl,  L"backgroundImageUrl" },
    { AdaptiveCardSchemaKey::BaseCardElement,  L"baseCardElement" },
    { AdaptiveCardSchemaKey::Body,  L"body" },
    { AdaptiveCardSchemaKey::BorderColor,  L"borderColor" },
    { AdaptiveCardSchemaKey::BorderThickness,  L"borderThickness" },
    { AdaptiveCardSchemaKey::Bottom,  L"bottom" },
    { AdaptiveCardSchemaKey::ButtonSpacing,  L"buttonSpacing" },
    { AdaptiveCardSchemaKey::Card,  L"card" },
    { AdaptiveCardSchemaKey::Center,  L"center" },
    { AdaptiveCardSchemaKey::Choices,  L"choices" },
    { AdaptiveCardSchemaKey::ChoiceSet,  L"choiceSet" },
    { AdaptiveCardSchemaKey::Color,  L"color" },
    { AdaptiveCardSchemaKey::ColorConfig,  L"colorConfig" },
    { AdaptiveCardSchemaKey::Colors,  L"colors" },
    { AdaptiveCardSchemaKey::Column,  L"column" },
    { AdaptiveCardSchemaKey::Columns,  L"columns" },
    { AdaptiveCardSchemaKey::ColumnSet,  L"columnSet" },
    { AdaptiveCardSchemaKey::Container,  L"container" },
    { AdaptiveCardSchemaKey::ContainerStyleConfig,  L"containerStyleConfig" },
    { AdaptiveCardSchemaKey::Dark,  L"dark" },
    { AdaptiveCardSchemaKey::Data,  L"data"},
    { AdaptiveCardSchemaKey::DateInput,  L"dateInput" },
    { AdaptiveCardSchemaKey::Default,  L"default" },
    { AdaptiveCardSchemaKey::Emphasis,  L"emphasis" },
    { AdaptiveCardSchemaKey::ExtraLarge,  L"extraLarge" },
    { AdaptiveCardSchemaKey::Facts,  L"facts" },
    { AdaptiveCardSchemaKey::FactSet,  L"factSet" },
    { AdaptiveCardSchemaKey::FallbackText,  L"fallbackText" },
    { AdaptiveCardSchemaKey::FontFamily,  L"fontFamily" },
    { AdaptiveCardSchemaKey::FontSizes,  L"fontSizes" },
    { AdaptiveCardSchemaKey::Good,  L"good" },
    { AdaptiveCardSchemaKey::HorizontalAlignment,  L"horizontalAlignment" },
    { AdaptiveCardSchemaKey::Id,  L"id" },
    { AdaptiveCardSchemaKey::Image,  L"image" },
    { AdaptiveCardSchemaKey::Images,  L"images" },
    { AdaptiveCardSchemaKey::ImageSet,  L"imageSet" },
    { AdaptiveCardSchemaKey::ImageSize,  L"imageSize" },
    { AdaptiveCardSchemaKey::ImageSizes,  L"imageSizes" },
    { AdaptiveCardSchemaKey::InlineTopMargin,  L"inlineTopMargin" },
    { AdaptiveCardSchemaKey::IsMultiline,  L"isMultiline" },
    { AdaptiveCardSchemaKey::IsMultiSelect,  L"isMultiSelect" },
    { AdaptiveCardSchemaKey::IsRequired,  L"isRequired" },
    { AdaptiveCardSchemaKey::IsSelected,  L"isSelected"},
    { AdaptiveCardSchemaKey::IsSubtle,  L"isSubtle" },
    { AdaptiveCardSchemaKey::Items,  L"items" },
    { AdaptiveCardSchemaKey::Large,  L"large" },
    { AdaptiveCardSchemaKey::Left,  L"left" },
    { AdaptiveCardSchemaKey::Light,  L"light" },
    { AdaptiveCardSchemaKey::LineColor,  L"lineColor" },
    { AdaptiveCardSchemaKey::LineThickness,  L"lineThickness" },
    { AdaptiveCardSchemaKey::Max,  L"max" },
    { AdaptiveCardSchemaKey::MaxActions,  L"maxActions" },
    { AdaptiveCardSchemaKey::MaxLength,  L"maxLength" },
    { AdaptiveCardSchemaKey::MaxLines,  L"maxLines" },
    { AdaptiveCardSchemaKey::Medium,  L"medium" },
    { AdaptiveCardSchemaKey::Method,  L"method" },
    { AdaptiveCardSchemaKey::Min,  L"min" },
    { AdaptiveCardSchemaKey::MinVersion,  L"minVersion" },
    { AdaptiveCardSchemaKey::Normal,  L"normal" },
    { AdaptiveCardSchemaKey::NumberInput,  L"numberInput" },
    { AdaptiveCardSchemaKey::Padding,  L"padding" },
    { AdaptiveCardSchemaKey::Placeholder,  L"placeholder" },
    { AdaptiveCardSchemaKey::Right,  L"right" },
    { AdaptiveCardSchemaKey::SelectAction,  L"selectAction" },
    { AdaptiveCardSchemaKey::Separation,  L"separation" },
    { AdaptiveCardSchemaKey::ShowActionMode,  L"showActionMode" },
    { AdaptiveCardSchemaKey::ShowCard,  L"showCard" },
    { AdaptiveCardSchemaKey::ShowCardActionConfig,  L"showCardActionConfig" },
    { AdaptiveCardSchemaKey::Size,  L"size" },
    { AdaptiveCardSchemaKey::Small,  L"small" },
    { AdaptiveCardSchemaKey::Spacing,  L"spacing" },
    { AdaptiveCardSchemaKey::SpacingDefinition,  L"spacingDefinition" },
    { AdaptiveCardSchemaKey::Speak,  L"speak" },
    { AdaptiveCardSchemaKey::Stretch,  L"stretch" },
    { AdaptiveCardSchemaKey::StrongSeparation,  L"strongSeparation" },
    { AdaptiveCardSchemaKey::Style,  L"style" },
    { AdaptiveCardSchemaKey::Subtle,  L"subtle" },
    { AdaptiveCardSchemaKey::SupportsInteractivity,  L"supportsInteractivity" },
    { AdaptiveCardSchemaKey::Text,  L"text" },
    { AdaptiveCardSchemaKey::TextBlock,  L"textBlock" },
    { AdaptiveCardSchemaKey::TextConfig,  L"textConfig" },
    { AdaptiveCardSchemaKey::TextInput,  L"textInput" },
    { AdaptiveCardSchemaKey::TextWeight,  L"weight" },
    { AdaptiveCardSchemaKey::TimeInput,  L"timeInput" },
    { AdaptiveCardSchemaKey::Title,  L"title" },
    { AdaptiveCardSchemaKey::ToggleInput,  L"toggleInput" },
    { AdaptiveCardSchemaKey::Top,  L"top" },
    { AdaptiveCardSchemaKey::Type,  L"type" },
    { AdaptiveCardSchemaKey::Url,  L"url" },
    { AdaptiveCardSchemaKey::Value,  L"value" },
    { AdaptiveCardSchemaKey::ValueOff,  L"valueOff" },
    { AdaptiveCardSchemaKey::ValueOn,  L"valueOn" },
    { AdaptiveCardSchemaKey::Version,  L"version" },
    { AdaptiveCardSchemaKey::Warning,  L"warning" },
    { AdaptiveCardSchemaKey::Weight,  L"weight" },
    { AdaptiveCardSchemaKey::Wrap,  L"wrap" },
};

static std::unordered_map<std::wstring, AdaptiveCardSchemaKey, CaseInsensitiveHash, CaseInsensitiveEqualTo> 
AdaptiveCardSchemaKeyNameToEnum = GenerateStringToEnumMap<AdaptiveCardSchemaKey>(AdaptiveCardSchemaKeyEnumToName);

static std::unordered_map<CardElementType, std::wstring, EnumHash> CardElementTypeEnumToName =
{
    { CardElementType::AdaptiveCard,  L"AdaptiveCard" },
    { CardElementType::Column,  L"Column" },
    { CardElementType::ColumnSet,  L"ColumnSet"},
    { CardElementType::Container,  L"Container" },
    { CardElementType::Fact,  L"Fact" },
    { CardElementType::FactSet,  L"FactSet" },
    { CardElementType::Image,  L"Image" },
    { CardElementType::ImageSet,  L"ImageSet" },
    { CardElementType::ChoiceSetInput,  L"Input.ChoiceSet" },
    { CardElementType::DateInput,  L"Input.Date" },
    { CardElementType::NumberInput,  L"Input.Number" },
    { CardElementType::TextInput,  L"Input.Text" },
    { CardElementType::TimeInput,  L"Input.Time" },
    { CardElementType::ToggleInput,  L"Input.Toggle" },
    { CardElementType::TextBlock,  L"TextBlock" },
};

static std::unordered_map<std::wstring, CardElementType, CaseInsensitiveHash, CaseInsensitiveEqualTo> 
CardElementTypeNameToEnum = GenerateStringToEnumMap<CardElementType>(CardElementTypeEnumToName);

static std::unordered_map<ActionType, std::wstring, EnumHash> ActionTypeEnumToName =
{
    { ActionType::Http,  L"Action.Http" },
    { ActionType::OpenUrl,  L"Action.OpenUrl" },
    { ActionType::ShowCard,  L"Action.ShowCard" },
    { ActionType::Submit,  L"Action.Submit" }
};

static std::unordered_map<std::wstring, ActionType, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ActionTypeNameToEnum = GenerateStringToEnumMap<ActionType>(ActionTypeEnumToName);

static std::unordered_map<SeparationStyle, std::wstring, EnumHash> SeparationStyleEnumToName =
{
    { SeparationStyle::Default,  L"default" },
    { SeparationStyle::None,  L"none" },
    { SeparationStyle::Strong,  L"strong" }
};

static std::unordered_map<std::wstring, SeparationStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
SeparationStyleNameToEnum = GenerateStringToEnumMap<SeparationStyle>(SeparationStyleEnumToName);

static std::unordered_map<ImageStyle, std::wstring, EnumHash> ImageStyleEnumToName =
{
    {ImageStyle::Normal,  L"normal"},
    {ImageStyle::Person,  L"person"}
};

static std::unordered_map<std::wstring, ImageStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ImageStyleNameToEnum = GenerateStringToEnumMap<ImageStyle>(ImageStyleEnumToName);

static std::unordered_map<ImageSize, std::wstring, EnumHash> ImageSizeEnumToName =
{
    { ImageSize::Auto,  L"Auto" },
    { ImageSize::Default,  L"Auto" },
    { ImageSize::Large,  L"Large" },
    { ImageSize::Medium,  L"Medium" },
    { ImageSize::Small,  L"Small" },
    { ImageSize::Stretch,  L"Stretch" },
};

static std::unordered_map<std::wstring, ImageSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ImageSizeNameToEnum = GenerateStringToEnumMap<ImageSize>(ImageSizeEnumToName);

static std::unordered_map<HorizontalAlignment, std::wstring, EnumHash> HorizontalAlignmentEnumToName = 
{
    {HorizontalAlignment::Center,  L"Center"},
    {HorizontalAlignment::Left,  L"Left"},
    {HorizontalAlignment::Right,  L"Right"}
};

static std::unordered_map<std::wstring, HorizontalAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>
HorizontalAlignmentNameToEnum = GenerateStringToEnumMap<HorizontalAlignment>(HorizontalAlignmentEnumToName);

static std::unordered_map<TextColor, std::wstring, EnumHash> TextColorEnumToName =
{
    {TextColor::Accent,  L"Accent"},
    {TextColor::Attention,  L"Attention"},
    {TextColor::Dark,  L"Dark"},
    {TextColor::Default,  L"Default"},
    {TextColor::Good,  L"Good"},
    {TextColor::Light,  L"Light"},
    {TextColor::Warning,  L"Warning"},
};

static std::unordered_map<std::wstring, TextColor, CaseInsensitiveHash, CaseInsensitiveEqualTo>
TextColorNameToEnum = GenerateStringToEnumMap<TextColor>(TextColorEnumToName);

static std::unordered_map<TextWeight, std::wstring, EnumHash> TextWeightEnumToName =
{
    {TextWeight::Bolder,  L"Bolder"},
    {TextWeight::Lighter,  L"Lighter"},
    {TextWeight::Normal,  L"Normal"},
};

static std::unordered_map<std::wstring, TextWeight, CaseInsensitiveHash, CaseInsensitiveEqualTo>
TextWeightNameToEnum = GenerateStringToEnumMap<TextWeight>(TextWeightEnumToName);

static std::unordered_map<TextSize, std::wstring, EnumHash> TextSizeEnumToName =
{
    {TextSize::ExtraLarge,  L"ExtraLarge"},
    {TextSize::Large,  L"Large"},
    {TextSize::Medium,  L"Medium"},
    {TextSize::Normal,  L"Normal"},
    {TextSize::Small,  L"Small"},
};

static std::unordered_map<std::wstring, TextSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>
TextSizeNameToEnum = GenerateStringToEnumMap<TextSize>(TextSizeEnumToName);

static std::unordered_map<ActionsOrientation, std::wstring, EnumHash> ActionsOrientationEnumToName =
{
    { ActionsOrientation::Horizontal,  L"Horizontal" },
    { ActionsOrientation::Vertical,  L"Vertical" },
};

static std::unordered_map<std::wstring, ActionsOrientation, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ActionsOrientationNameToEnum = GenerateStringToEnumMap<ActionsOrientation>(ActionsOrientationEnumToName);

static std::unordered_map<ActionMode, std::wstring, EnumHash> ActionModeEnumToName =
{
    { ActionMode::Inline,  L"Inline" },
    { ActionMode::Popup,  L"Popup" }
};

static std::unordered_map<std::wstring, ActionMode, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ActionModeNameToEnum = GenerateStringToEnumMap<ActionMode>(ActionModeEnumToName);

static std::unordered_map<ChoiceSetStyle, std::wstring, EnumHash> ChoiceSetStyleEnumToName =
{
    { ChoiceSetStyle::Compact,  L"Compact" },
    { ChoiceSetStyle::Expanded,  L"Expanded" }
};

static std::unordered_map<std::wstring, ChoiceSetStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ChoiceSetStyleNameToEnum = GenerateStringToEnumMap<ChoiceSetStyle>(ChoiceSetStyleEnumToName);

static std::unordered_map<TextInputStyle, std::wstring, EnumHash> TextInputStyleEnumToName =
{
    { TextInputStyle::Email,  L"Email" },
    { TextInputStyle::Tel,  L"Tel" },
    { TextInputStyle::Text,  L"Text" },
    { TextInputStyle::Url,  L"Url" },
};

static std::unordered_map<std::wstring, TextInputStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
TextInputStyleNameToEnum = GenerateStringToEnumMap<TextInputStyle>(TextInputStyleEnumToName);

static std::unordered_map<ContainerStyle, std::wstring, EnumHash> ContainerStyleEnumToName =
{
    { ContainerStyle::Emphasis,  L"Emphasis" },
    { ContainerStyle::Normal,  L"Normal" },
};

static std::unordered_map<std::wstring, ContainerStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ContainerStyleNameToEnum = GenerateStringToEnumMap<ContainerStyle>(ContainerStyleEnumToName);

static std::unordered_map<ActionAlignment, std::wstring, EnumHash> ActionAlignmentEnumToName =
{
    { ActionAlignment::Left,  L"Left" },
    { ActionAlignment::Center,  L"Center" },
    { ActionAlignment::Right,  L"Right" },
    { ActionAlignment::Stretch,  L"Stretch" },
};

static std::unordered_map<std::wstring, ActionAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ActionAlignmentNameToEnum = GenerateStringToEnumMap<ActionAlignment>(ActionAlignmentEnumToName);

#define WStringToString(wStr) std::string(wStr.begin(), wStr.end())

const std::wstring AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey type)
{
    if (AdaptiveCardSchemaKeyEnumToName.find(type) == AdaptiveCardSchemaKeyEnumToName.end())
    {
        throw std::out_of_range("Invalid AdaptiveCardSchemaKeys");
    }

    return AdaptiveCardSchemaKeyEnumToName[type];
}

AdaptiveCardSchemaKey AdaptiveCardSchemaKeyFromString(const std::wstring& type)
{
    if (AdaptiveCardSchemaKeyNameToEnum.find(type) == AdaptiveCardSchemaKeyNameToEnum.end())
    {
        throw std::out_of_range("Invalid AdaptiveCardSchemaKey: " + WStringToString(type));
    }

    return AdaptiveCardSchemaKeyNameToEnum[type];
}

const std::wstring CardElementTypeToString(CardElementType elementType)
{
    if (CardElementTypeEnumToName.find(elementType) == CardElementTypeEnumToName.end())
    {
        throw std::out_of_range("Invalid CardElementType");
    }

    return CardElementTypeEnumToName[elementType];
}

CardElementType CardElementTypeFromString(const std::wstring& elementType)
{
    if (CardElementTypeNameToEnum.find(elementType) == CardElementTypeNameToEnum.end())
    {
        throw std::out_of_range("Invalid CardElementType: " + WStringToString(elementType));
    }

    return CardElementTypeNameToEnum[elementType];
}

const std::wstring ActionTypeToString(ActionType actionType)
{
    if (ActionTypeEnumToName.find(actionType) == ActionTypeEnumToName.end())
    {
        throw std::out_of_range("Invalid ActionType");
    }

    return ActionTypeEnumToName[actionType];
}

ActionType ActionTypeFromString(const std::wstring& actionType)
{
    if (ActionTypeNameToEnum.find(actionType) == ActionTypeNameToEnum.end())
    {
        throw std::out_of_range("Invalid ActionType: " + WStringToString(actionType));
    }

    return ActionTypeNameToEnum[actionType];
}

const std::wstring HorizontalAlignmentToString(HorizontalAlignment alignment)
{
    if (HorizontalAlignmentEnumToName.find(alignment) == HorizontalAlignmentEnumToName.end())
    {
        throw std::out_of_range("Invalid HorizontalAlignment type");
    }
    return HorizontalAlignmentEnumToName[alignment];
}

HorizontalAlignment HorizontalAlignmentFromString(const std::wstring& alignment)
{
    if (HorizontalAlignmentNameToEnum.find(alignment) == HorizontalAlignmentNameToEnum.end())
    {
        throw std::out_of_range("Invalid HorizontalAlignment: " + WStringToString(alignment));
    }

    return HorizontalAlignmentNameToEnum[alignment];
}

const std::wstring TextColorToString(TextColor color)
{
    if (TextColorEnumToName.find(color) == TextColorEnumToName.end())
    {
        throw std::out_of_range("Invalid TextColor type");
    }
    return TextColorEnumToName[color];
}

TextColor TextColorFromString(const std::wstring& color)
{
    if (TextColorNameToEnum.find(color) == TextColorNameToEnum.end())
    {
        throw std::out_of_range("Invalid TextColor: " + WStringToString(color));
    }

    return TextColorNameToEnum[color];
}

const std::wstring TextWeightToString(TextWeight weight)
{
    if (TextWeightEnumToName.find(weight) == TextWeightEnumToName.end())
    {
        throw std::out_of_range("Invalid TextWeight type");
    }
    return TextWeightEnumToName[weight];
}

TextWeight TextWeightFromString(const std::wstring& weight)
{
    if (TextWeightNameToEnum.find(weight) == TextWeightNameToEnum.end())
    {
        throw std::out_of_range("Invalid TextWeight: " + WStringToString(weight));
    }

    return TextWeightNameToEnum[weight];
}

const std::wstring TextSizeToString(TextSize size)
{
    if (TextSizeEnumToName.find(size) == TextSizeEnumToName.end())
    {
        throw std::out_of_range("Invalid TextSize type");
    }
    return TextSizeEnumToName[size];
}

TextSize TextSizeFromString(const std::wstring& size)
{
    if (TextSizeNameToEnum.find(size) == TextSizeNameToEnum.end())
    {
        throw std::out_of_range("Invalid TextSize: " + WStringToString(size));
    }

    return TextSizeNameToEnum[size];
}

const std::wstring ImageSizeToString(ImageSize size)
{
    if (ImageSizeEnumToName.find(size) == ImageSizeEnumToName.end())
    {
        throw std::out_of_range("Invalid ImageSize type");
    }
    return ImageSizeEnumToName[size];
}

ImageSize ImageSizeFromString(const std::wstring& size)
{
    if (ImageSizeNameToEnum.find(size) == ImageSizeNameToEnum.end())
    {
        throw std::out_of_range("Invalid ImageSize: " + WStringToString(size));
    }

    return ImageSizeNameToEnum[size];
}

const std::wstring SeparationStyleToString(SeparationStyle type)
{
    if (SeparationStyleEnumToName.find(type) == SeparationStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid SeparationStyle type");
    }
    return SeparationStyleEnumToName[type];
}

SeparationStyle SeparationStyleFromString(const std::wstring& style)
{
    if (SeparationStyleNameToEnum.find(style) == SeparationStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid SeparationStyle: " + WStringToString(style));
    }

    return SeparationStyleNameToEnum[style];
}

const std::wstring ImageStyleToString(ImageStyle style)
{
    if (ImageStyleEnumToName.find(style) == ImageStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid ImageStyle style");
    }
    return ImageStyleEnumToName[style];
}

ImageStyle ImageStyleFromString(const std::wstring& style)
{
    if (ImageStyleNameToEnum.find(style) == ImageStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid ImageStyle: " + WStringToString(style));
    }

    return ImageStyleNameToEnum[style];
}

const std::wstring ActionsOrientationToString(ActionsOrientation orientation)
{
    if (ActionsOrientationEnumToName.find(orientation) == ActionsOrientationEnumToName.end())
    {
        throw std::out_of_range("Invalid ActionsOrientation type");
    }
    return ActionsOrientationEnumToName[orientation];
}

ActionsOrientation ActionsOrientationFromString(const std::wstring& orientation)
{
    if (ActionsOrientationNameToEnum.find(orientation) == ActionsOrientationNameToEnum.end())
    {
        throw std::out_of_range("Invalid ActionsOrientation: " + WStringToString(orientation));
    }
    return ActionsOrientationNameToEnum[orientation];
}

const std::wstring ActionModeToString(ActionMode mode)
{
    if (ActionModeEnumToName.find(mode) == ActionModeEnumToName.end())
    {
        throw std::out_of_range("Invalid ActionMode type");
    }
    return ActionModeEnumToName[mode];
}

ActionMode ActionModeFromString(const std::wstring& mode)
{
    if (ActionModeNameToEnum.find(mode) == ActionModeNameToEnum.end())
    {
        throw std::out_of_range("Invalid ActionMode: " + WStringToString(mode));
    }
    return ActionModeNameToEnum[mode];
}
const std::wstring ChoiceSetStyleToString(ChoiceSetStyle style)
{
    if (ChoiceSetStyleEnumToName.find(style) == ChoiceSetStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid ChoiceSetStyle");
    }
    return ChoiceSetStyleEnumToName[style];
}
ChoiceSetStyle ChoiceSetStyleFromString(const std::wstring & style)
{
    if (ChoiceSetStyleNameToEnum.find(style) == ChoiceSetStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid ChoiceSetStyle: " + WStringToString(style));
    }
    return ChoiceSetStyleNameToEnum[style];
}

const std::wstring TextInputStyleToString(TextInputStyle style)
{
    if (TextInputStyleEnumToName.find(style) == TextInputStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid TextInputStyle");
    }
    return TextInputStyleEnumToName[style];
}
TextInputStyle TextInputStyleFromString(const std::wstring & style)
{
    if (TextInputStyleNameToEnum.find(style) == TextInputStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid TextInputStyle: " + WStringToString(style));
    }
    return TextInputStyleNameToEnum[style];
}

const std::wstring ContainerStyleToString(ContainerStyle style)
{
    if (ContainerStyleEnumToName.find(style) == ContainerStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid ContainerStyle");
    }
    return ContainerStyleEnumToName[style];
}
ContainerStyle ContainerStyleFromString(const std::wstring & style)
{
    if (ContainerStyleNameToEnum.find(style) == ContainerStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid ContainerStyle: " + WStringToString(style));
    }
    return ContainerStyleNameToEnum[style];
}

const std::wstring ActionAlignmentToString(ActionAlignment alignment)
{
    if (ActionAlignmentEnumToName.find(alignment) == ActionAlignmentEnumToName.end())
    {
        throw std::out_of_range("Invalid ActionAlignment");
    }
    return ActionAlignmentEnumToName[alignment];
}
ActionAlignment ActionAlignmentFromString(const std::wstring & alignment)
{
    if (ActionAlignmentNameToEnum.find(alignment) == ActionAlignmentNameToEnum.end())
    {
        throw std::out_of_range("Invalid ActionAlignment: " + WStringToString(alignment));
    }
    return ActionAlignmentNameToEnum[alignment];
}
}
