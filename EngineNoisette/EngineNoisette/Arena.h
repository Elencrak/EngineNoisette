#pragma once
#include <string>
class Arena
{
public:
	void Update();
	void Draw();
	Arena(std::string p_Name);
	Arena();
	~Arena();

	std::string m_Name;
};

