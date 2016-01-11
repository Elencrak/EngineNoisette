#pragma once
#include "Action.h"
class Jump : public Action
{
public:
	Jump();
	~Jump();

	//Method
	void Execute() override;
};

