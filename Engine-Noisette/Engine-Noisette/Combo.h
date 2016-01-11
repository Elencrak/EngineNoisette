#pragma once
#include "Action.h"
#include <list>
class Combo : public Action
{
protected:
	std::list<Action*> m_comboAction;
public:
	// Constructor
	Combo();
	~Combo();

	//Method
	virtual void Execute() = 0;
	virtual void Add() = 0;
	virtual void Remove()= 0;
	
};

