#pragma once
#include "Action.h"

class Punch : public Action
{
public:

	// Constructor
	Punch();
	~Punch();

	//Method
	void Execute() override;
};

