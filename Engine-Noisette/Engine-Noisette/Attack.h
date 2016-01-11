#pragma once
#include "State.h"

class Attack : public State
{
public:

	//Contructor
	Attack();
	~Attack();

	// Method
	void Update() override;
};

