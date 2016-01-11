#pragma once
#include "State.h"
class Normal : public State
{
public:
	//Constructor
	Normal();
	~Normal();

	//Method
	void Update() override;
};

