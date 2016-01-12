#pragma once
#include "Character.h"
#include <iostream>

class State
{
protected:
	std::string m_StateName;
	Character* m_linkCharacter;
public:

	// Constructor
	State(Character* p_Character);
	~State();

	//Method
	std::string getStateName();
	virtual void Update() = 0;
	virtual void TakeDamage(Character*  p_Character, float damage);
};

