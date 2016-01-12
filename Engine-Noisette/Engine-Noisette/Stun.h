#pragma once
#include "State.h"

class Stun : public State
{
public:

	int nbStunRound;

	// Constructor
	Stun(Character* p_Character);
	~Stun();

	//Method
	void Update() override;
	void TakeDamage(Character*  p_Character, float damage) override;
};

