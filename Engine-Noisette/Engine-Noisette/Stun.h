#pragma once
#include "State.h"

class Stun : public State
{
public:

	// Constructor
	Stun();
	~Stun();

	//Method
	void Update() override;
	void TakeDamage(Character*  p_Character) override;
};

