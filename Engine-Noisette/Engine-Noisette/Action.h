#pragma once
#include <iostream>
class Action
{
protected:
	std::string m_ActionName;
	int m_Damage;

public:
	//Constructor
	Action();
	~Action();

	//Method
	virtual void Execute() = 0;
};

