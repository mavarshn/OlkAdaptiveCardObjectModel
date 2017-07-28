#pragma once

#include "stdafx.h"
#include "Enums.h"
#include "Fact.h"
#include "BaseCardElement.h"

namespace AdaptiveCards
{
class BaseCardElement;
class FactSet : public BaseCardElement
{
public:
    FactSet();
    FactSet(SeparationStyle separation, std::wstring speak);
    FactSet(SeparationStyle separation, std::wstring speak, std::vector<std::shared_ptr<Fact>>& facts);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

    std::vector<std::shared_ptr<Fact>>& GetFacts();
    const std::vector<std::shared_ptr<Fact>>& GetFacts() const;
    static std::shared_ptr<FactSet> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<FactSet> DeserializeFromString(const std::wstring& jsonString);

private:
    std::vector<std::shared_ptr<Fact>> m_facts; 
};
}