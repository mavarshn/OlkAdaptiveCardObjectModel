#include "stdafx.h"
#include "FactSet.h"
#include "ParseUtil.h"
#include "Fact.h"

using namespace AdaptiveCards;

FactSet::FactSet() : BaseCardElement(CardElementType::FactSet)
{
}

FactSet::FactSet(
    SeparationStyle separation,
    std::wstring speak,
    std::vector<std::shared_ptr<Fact>>& facts) :
    BaseCardElement(CardElementType::FactSet, separation, speak),
    m_facts(facts)
{
}

FactSet::FactSet(
    SeparationStyle separation,
    std::wstring speak) :
    BaseCardElement(CardElementType::FactSet, separation, speak)
{
}

const std::vector<std::shared_ptr<Fact>>& FactSet::GetFacts() const
{
    return m_facts;
}

std::vector<std::shared_ptr<Fact>>& FactSet::GetFacts()
{
    return m_facts;
}

std::wstring FactSet::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value FactSet::SerializeToJsonValue()
{
    Mso::Json::value root = BaseCardElement::SerializeToJsonValue();

    std::wstring factsPropertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Facts);
    root[factsPropertyName] = Mso::Json::value::array();

    int i = 0;
    for (const auto& fact : GetFacts())
    {
        root[factsPropertyName][i++] = fact->SerializeToJsonValue();
    }

    return root;
}

std::shared_ptr<FactSet> FactSet::Deserialize(const Mso::Json::value& value)
{
    ParseUtil::ExpectTypeString(value, CardElementType::FactSet);

    auto factSet = BaseCardElement::Deserialize<FactSet>(value);

    // Parse Facts
    auto factsArray = ParseUtil::GetArray(value, AdaptiveCardSchemaKey::Facts, true);
    std::vector<std::shared_ptr<Fact>> facts;

    // Deserialize every fact in the array
    for (auto & element : factsArray)
    {
        auto fact = Fact::Deserialize(element.second);
        if (fact != nullptr)
        {
            facts.push_back(fact);
        }
    }

    factSet->m_facts = std::move(facts);
    return factSet;
}

std::shared_ptr<FactSet> FactSet::DeserializeFromString(const std::wstring& jsonString)
{
    return FactSet::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}