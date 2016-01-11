#pragma once
#include "Character.h"
#include <iostream>

class State
{
protected:
	std::string m_StateName;

public:

	// Constructor
	State();
	~State();

	//Method
	virtual void Update() = 0;
	virtual void TakeDamage(Character  p_Character);
};

