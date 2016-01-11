#pragma once
#include "Action.h"

class Protect : public Action
{
public:
	// Constructor
	Protect();
	~Protect();

	//Method
	void Execute() override;
};

