#pragma once
#include <iostream>
#include <string>


using std::string;
using std::cout;

class GameMenu
{
private:

	int menuChoice;

	bool m_playing;
	

public:
	int inputPName;
	GameMenu();

	void menuOptions();
	void SetPlaying(bool& sPlaying);

	bool GetPlaying()
	{
		return m_playing;
	}

};

