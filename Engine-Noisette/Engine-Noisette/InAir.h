#pragma once
#include "State.h"

class InAir : public State
{
public:

	// Constructor
	InAir();
	~InAir();

	// Method
	void Update() override;
	void TakeDamage(Character*  p_Character) override;
};

