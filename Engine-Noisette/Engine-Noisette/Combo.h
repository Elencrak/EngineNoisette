#pragma once
#include "Action.h"
#include <list>
class Combo : public Action
{
private:
	std::list<Action*> m_comboAction;
public:
	// Constructor
	Combo();
	~Combo();

	//Method
	void Execute();
	void Add(Action* p_action);
	void Remove(Action* p_action);
	void Clear();
	int GetLength();
	int GetDamage();
	
};

