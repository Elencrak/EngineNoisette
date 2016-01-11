#pragma once
#include "Action.h"
class MoveLeft : public Action
{
public:
	// Constructor
	MoveLeft();
	~MoveLeft();

	//Method
	void Execute() override;
};

