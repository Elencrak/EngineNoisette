#pragma once
#include "Action.h"

class Crouch : public Action
{
public:
	Crouch();
	~Crouch();

	//Method
	void Execute() override;
};

