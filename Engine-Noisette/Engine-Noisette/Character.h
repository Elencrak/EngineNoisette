#pragma once
#include <list>
#include "InputHandle.h"

class State;
class Character
{
private:
	int m_PlayerId;
	std::list<State*> m_States;
	State* m_CurrentState;
	int m_MaxLife;
	InputHandle m_PlayerInput;

public:
	int currentLife;

	//Constructor
	Character();
	~Character();
	
	//Method
	virtual void TakeDamage() = 0;
	virtual void ExecuteAction() = 0;
	virtual void SetState() = 0;

	void Update();
	void Draw();
};

