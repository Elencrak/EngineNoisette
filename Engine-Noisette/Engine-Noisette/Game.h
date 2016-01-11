#pragma once
#include <string>
class Game
{
public:
	void Update();
	Game(std::string p_Name);
	Game();
	~Game();

	int m_GameVersion;
	std::string m_GameName;
};

