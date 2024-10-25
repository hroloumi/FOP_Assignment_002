#pragma once
#include <string>

class Character
{
public:
    Character(); // Constructor
    void setName(std::string playerName);
    void setAncestry(int ancestryChoice);
    void setClass(int classChoice);
    void displayCharacter() const;
    void generateStats();
    std::string getAncestryName(int ancestryChoice) const;
    std::string getClassName(int classChoice) const;

private:
    std::string m_name;
    std::string m_ancestry;
    std::string m_playerClass;
    int m_strength, m_dexterity, m_constitution, m_wisdom, m_intelligent, m_charisma;
    void applyAncestryBonus(int ancestryChoice);


};

