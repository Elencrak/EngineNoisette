#pragma once
#include <string>
class Game
{
public:
	void Update();
	Game();
	~Game();

	int GameVersion;
	std::string GameName;
};

