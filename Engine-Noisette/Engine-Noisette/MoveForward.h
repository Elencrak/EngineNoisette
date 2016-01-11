#pragma once
#include "Action.h"
class MoveForward : public Action
{
public:
	// Constructor
	MoveForward();
	~MoveForward();

	//Method
	void Execute() override;
};

