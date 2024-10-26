#include <iostream>
#include <string>
#include "Character.h"
#include "GameMenu.h"

Character player;
std::string name;
int m_ancestryChoice;
int m_classChoice;
char m_choice;

bool isValidInput(int choice, int min, int max) {
    return choice >= min && choice <= max;
}


int main() {

    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    bool continueGame = true;

    while (continueGame) {
       
        std::cout << "====> RPG Character Creator v1.0 <====\n\n";
        std::cout << "Please enter your character's name \n(max 10 characters): \n";
        std::getline(std::cin, name);
        std::cout << " ===> Welcome: " << name << " <===" << std::endl;

        if (name.length() > 10) {
            name = name.substr(0, 10); // Trim name to 10 characters
        }
        player.setName(name);

        // Ancestry Selection
        std::cout << "Select your ancestry:\n[1] Human\n[2] Elf\n[3] Half-elf\n[4] Dwarf\n[5] Halfling\n";
        std::cin >> m_ancestryChoice;
        while (!isValidInput(m_ancestryChoice, 1, 5)) {
            std::cout << "Invalid choice. Please select a valid ancestry (1-5): ";
            std::cin >> m_ancestryChoice;
        }
        player.setAncestry(m_ancestryChoice);

        // Class Selection
        std::cout << "Select your class:\n[1] Fighter\n[2] Thief\n[3] Wizard\n[4] Cleric\n[5] Paladin\n";
        std::cin >> m_classChoice;
        while (!isValidInput(m_classChoice, 1, 5)) {
            std::cout << "Invalid choice. Please select a valid class (1-5): ";
            std::cin >> m_classChoice;
        }
        player.setClass(m_classChoice);

        // Generate stats and display the character
        player.generateStats();
        player.displayCharacter();

        // Ask if player wants to create another character or exit
        
        std::cout << "Would you like to create another character? (y/n): ";
        std::cin >> m_choice;

        if (m_choice == 'n' || m_choice == 'N') {
            continueGame = false;
        }

        
        std::cin.ignore();
    }

    std::cout << "Thank you for playing!\n";
    return 0;
}
