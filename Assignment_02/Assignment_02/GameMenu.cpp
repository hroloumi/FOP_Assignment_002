#include "GameMenu.h"


GameMenu::GameMenu()
{
	inputPName = 0;
	m_playing = false;
}



void GameMenu::menuOptions()
{
	std::cout << "this is test\n";
	std::cout << "1 -2\n";
	std::cin >> inputPName;
	
	switch (inputPName) 
	{
	case 1:
		std::cout << "this is test\n";
		break;

	case 2:
		m_playing = false;
		std::cout << "this is the end\n";
		break;
	default:
		break;
	}
	
}

void GameMenu::SetPlaying(bool& sPlaying)
{
	m_playing = sPlaying;

}
