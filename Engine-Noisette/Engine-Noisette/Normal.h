#pragma once
#include "State.h"
class Normal : public State
{
public:
	//Constructor
	Normal(Character* p_Character);
	~Normal();

	//Method
	void Update() override;
};

