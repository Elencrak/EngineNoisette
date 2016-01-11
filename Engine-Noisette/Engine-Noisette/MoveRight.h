#pragma once
#include "Action.h"
class MoveRight : public Action
{
public:
	//Constructor
	MoveRight();
	~MoveRight();

	//Method
	void Execute() override;
};

