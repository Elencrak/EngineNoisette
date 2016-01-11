#pragma once
#include <string>
class Arena
{
public:
	void Update();
	void Draw();
	Arena();
	~Arena();

	std::string m_Name;
};

