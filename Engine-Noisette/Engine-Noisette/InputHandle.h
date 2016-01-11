#pragma once
#include <iostream>
#include <list>
#include <map>
#include "Action.h"
#include "EnumAction.h"

class InputHandle
{
private:
	std::map<EnumAction,Action*> m_Actions;

public:
	//InputHandle();
	InputHandle(int p_PlayerId);
	~InputHandle();

	Action* HandleInput(EnumAction p_EnumAction);
	void ExcuteCombo();
};

