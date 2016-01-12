#pragma once
#include "State.h"

class Attack : public State
{
public:

	//Contructor
	Attack(Character* p_Character);
	~Attack();

	// Method
	void Update() override;
};

