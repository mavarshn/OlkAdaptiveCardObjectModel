#pragma once
#include "stdafx.h"

#ifdef _WIN32
#define strncasecmp wcsncmp
#endif // _WIN32

namespace AdaptiveCards
{

struct EnumHash
{
    template <typename T>
    size_t operator()(T t) const
    {
        return static_cast<size_t>(t);
    }
};

struct CaseInsensitiveEqualTo {
    bool operator() (const std::wstring& lhs, const std::wstring& rhs) const {
        return strncasecmp(lhs.c_str(), rhs.c_str(), CHAR_MAX) == 0;
    }
};

struct CaseInsensitiveHash {
    size_t operator() (const std::wstring& keyval) const {
        return std::accumulate(keyval.begin(), keyval.end(), size_t{ 0 }, [](size_t acc, char c) { return acc + static_cast<size_t>(std::tolower(c)); });
    }
};

enum class AdaptiveCardSchemaKey
{
    Accent = 0,
    ActionAlignment,
    ActionMode,
    ActionOrientation,
    Actions,
    ActionSetConfig,
    ActionsOrientation,
    AdaptiveCard,
    AltText,
    Attention,
    BackgroundColor,
    BackgroundImageUrl,
    BaseCardElement,
    Body,
    BorderColor,
    BorderThickness,
    Bottom,
    ButtonSpacing,
    Card,
    Center,
    Choices,
    ChoiceSet,
    Color,
    ColorConfig,
    Colors,
    Column,
    Columns,
    ColumnSet,
    Container,
    ContainerStyleConfig,
    Dark,
    Data,
    DateInput,
    Default,
    Emphasis,
    ExtraLarge,
    Facts,
    FactSet,
    FallbackText,
    FontFamily,
    FontSizes,
    Good,
    HorizontalAlignment,
    Id,
    Image,
    Images,
    ImageSet,
    ImageSize,
    ImageSizes,
    InlineTopMargin,
    IsMultiline,
    IsMultiSelect,
    IsRequired,
    IsSelected,
    IsSubtle,
    Items,
    Large,
    Left,
    Light,
    LineColor,
    LineThickness,
    Max,
    MaxActions,
    MaxLength,
    MaxLines,
    Medium,
    Method,
    Min,
    MinVersion,
    Normal,
    NumberInput,
    Padding,
    Placeholder,
    Right,
    SelectAction,
    Separation,
    ShowActionMode,
    ShowCard,
    ShowCardActionConfig,
    Size,
    Small,
    Spacing,
    SpacingDefinition,
    Speak,
    Stretch,
    StrongSeparation,
    Style,
    Subtle,
    SupportsInteractivity,
    Text,
    TextBlock,
    TextConfig,
    TextInput,
    TextWeight,
    TimeInput,
    Title,
    ToggleInput,
    Top,
    Type,
    Url,
    Value,
    ValueOff,
    ValueOn,
    Version,
    Warning,
    Weight,
    Wrap,
};

enum class TextSize
{
    Small = 0,
    Normal,
    Medium,
    Large,
    ExtraLarge
};

enum class TextWeight {
    Lighter = 0,
    Normal,
    Bolder
};

enum class TextColor {
    Default = 0,
    Dark,
    Light,
    Accent,
    Good,
    Warning,
    Attention
};

enum class HorizontalAlignment {
    Left = 0,
    Center,
    Right
};

enum class ImageStyle {
    Normal = 0,
    Person
};

enum class ImageSize {
    Default = 0,
    Auto,
    Stretch,
    Small,
    Medium,
    Large
};

enum class TextInputStyle {
    Text = 0,
    Tel,
    Url,
    Email,
};

enum class CardElementType
{
    Unsupported = 0,
    AdaptiveCard,
    TextBlock,
    Image,
    Container,
    Column,
    ColumnSet,
    FactSet,
    Fact,
    ImageSet,
    DateInput,
    NumberInput,
    TextInput,
    TimeInput,
    ToggleInput,
    ChoiceSetInput,
};

enum class ActionType
{
    Unsupported = 0, 
    ShowCard,
    Submit,
    Http,
    OpenUrl,
};

enum class ActionAlignment
{
    Left = 0,
    Center,
    Right,
    Stretch,
};

enum class ChoiceSetStyle
{
    Compact = 0,
    Expanded
};

enum class SeparationStyle {
    Default = 0,
    None,
    Strong,
};

enum class ActionsOrientation {
    Vertical = 0,
    Horizontal
};

enum class ActionMode {
    InlineEdgeToEdge = 0,
    Inline,
    Popup
};

enum class ContainerStyle {
    Normal = 0,
    Emphasis
};

const std::wstring AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey type);
AdaptiveCardSchemaKey AdaptiveCardSchemaKeyFromString(const std::wstring& type);

const std::wstring CardElementTypeToString(CardElementType elementType);
CardElementType CardElementTypeFromString(const std::wstring& elementType);

const std::wstring ActionTypeToString(ActionType actionType);
ActionType ActionTypeFromString(const std::wstring& actionType);

const std::wstring HorizontalAlignmentToString(HorizontalAlignment alignment);
HorizontalAlignment HorizontalAlignmentFromString(const std::wstring& alignment);

const std::wstring TextColorToString(TextColor type);
TextColor TextColorFromString(const std::wstring& type);

const std::wstring TextWeightToString(TextWeight type);
TextWeight TextWeightFromString(const std::wstring& type);

const std::wstring TextSizeToString(TextSize size);
TextSize TextSizeFromString(const std::wstring& size);

const std::wstring ImageSizeToString(ImageSize size);
ImageSize ImageSizeFromString(const std::wstring& size);

const std::wstring SeparationStyleToString(SeparationStyle style);
SeparationStyle SeparationStyleFromString(const std::wstring& style);

const std::wstring ImageStyleToString(ImageStyle style);
ImageStyle ImageStyleFromString(const std::wstring& style);

const std::wstring ActionsOrientationToString(ActionsOrientation orientation);
ActionsOrientation ActionsOrientationFromString(const std::wstring& orientation);

const std::wstring ActionModeToString(ActionMode mode);
ActionMode ActionModeFromString(const std::wstring& mode);

const std::wstring ChoiceSetStyleToString(ChoiceSetStyle style);
ChoiceSetStyle ChoiceSetStyleFromString(const std::wstring& style);

const std::wstring TextInputStyleToString(TextInputStyle style);
TextInputStyle TextInputStyleFromString(const std::wstring& style);

const std::wstring ContainerStyleToString(ContainerStyle style);
ContainerStyle ContainerStyleFromString(const std::wstring& style);

const std::wstring ActionAlignmentToString(ActionAlignment alignment);
ActionAlignment ActionAlignmentFromString(const std::wstring& alignment);

template <typename T>
const std::unordered_map<std::wstring, T, CaseInsensitiveHash, CaseInsensitiveEqualTo>
GenerateStringToEnumMap(const std::unordered_map<T, std::wstring, EnumHash>& keyToStringMap)
{
    std::unordered_map<std::wstring, T, CaseInsensitiveHash, CaseInsensitiveEqualTo> result;
    for (auto& kv : keyToStringMap)
    {
        result[kv.second] = kv.first;
    }
    return result;
}
}
