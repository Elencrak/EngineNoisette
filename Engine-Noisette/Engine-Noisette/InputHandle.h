#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Action.h"
class InputHandle
{
private:
	std::string m_up;
	std::string m_down;
	std::string m_right;
	std::string m_action1;
	std::string m_action2;
	std::string m_action3;

	std::list<Action*> m_Actions;
public:
	InputHandle();
	~InputHandle();

	void HandleInput();
	void ExcuteCombo();
};

