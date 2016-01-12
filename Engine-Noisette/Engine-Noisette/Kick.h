#pragma once
#include "Action.h"
class Kick : public Action
{
public:

	Kick();
	~Kick();

	//Method
	void Execute() override;
};

