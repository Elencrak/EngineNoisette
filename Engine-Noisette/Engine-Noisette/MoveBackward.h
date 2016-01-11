#pragma once
#include "Action.h"
class MoveBackward : public Action
{
public:
	//Constructor
	MoveBackward();
	~MoveBackward();

	//Method
	void Execute() override;
};

