#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Constructor
Character::Character() : 
    m_strength(0),
    m_dexterity(0),
    m_constitution(0),
    m_wisdom(0),
    m_intelligent(0),
    m_charisma(0) {}

void Character::setName(std::string playerName) {
    m_name = playerName;
}

void Character::setAncestry(int ancestryChoice) {
    m_ancestry = getAncestryName(ancestryChoice);
    applyAncestryBonus(ancestryChoice);
}

void Character::setClass(int classChoice) {
    m_playerClass = getClassName(classChoice);
}

void Character::generateStats() {
    m_strength = rand() % 11 + 8;  // Generate stats between 8 and 18
    m_dexterity = rand() % 11 + 8;
    m_constitution = rand() % 11 + 8;
    m_wisdom = rand() % 11 + 8;
    m_intelligent = rand() % 11 + 8;
    m_charisma = rand() % 11 + 8;
}

std::string Character::getAncestryName(int ancestryChoice) const {
    switch (ancestryChoice) {
    case 1: return "Human";
    case 2: return "Elf";
    case 3: return "Half-elf";
    case 4: return "Dwarf";
    case 5: return "Halfling";
    default: return "Unknown";
    }
}

std::string Character::getClassName(int classChoice) const {
    switch (classChoice) {
    case 1: return "Fighter";
    case 2: return "Thief";
    case 3: return "Wizard";
    case 4: return "Cleric";
    case 5: return "Paladin";
    default: return "Unknown";
    }
}

void Character::applyAncestryBonus(int ancestryChoice) {
    switch (ancestryChoice) {
    case 1: // Human: +1 to all stats
        m_strength += 1; m_dexterity += 1; m_constitution += 1; m_wisdom += 1; m_intelligent += 1; m_charisma += 1;
        break;
    case 2: // Elf: +2 Dexterity, -1 con
        m_dexterity += 2; m_constitution -= 1;
        break;
    case 3: // Half-elf: +1 constitution, +1 Dexterity
        m_constitution += 1; m_dexterity += 1;
        break;
    case 4: // Dwarf: +2 constitution, -1 Dexterity
        m_constitution += 2; m_dexterity -= 1;
        break;
    case 5: // Halfling: +2 dex, -1 str
        m_dexterity += 2; m_strength -= 1;
        break;
    }
}

void Character::displayCharacter() const {
    std::cout << "Name: " << m_name << "\n";
    std::cout << "Ancestry: " << m_ancestry << "\n";
    std::cout << "Class: " << m_playerClass << "\n";
    std::cout << "==> Strength: " << m_strength << "   ==> Dexterity: " << m_dexterity << "   ==> Constitution: " << m_constitution << "\n";
    std::cout << "==> Wisdom: " << m_wisdom << "   ==> Intelligent: " << m_intelligent << "   ==> Charisma: " << m_charisma << "\n";
}