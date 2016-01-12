#pragma once
#include "State.h"

class InAir : public State
{
public:

	// Constructor
	InAir(Character* p_Character);
	~InAir();

	// Method
	void Update() override;
	void TakeDamage(Character*  p_Character, float damage) override;
};

