#pragma once
#include <list>
#include <string>
#include <map>
#include "InputHandle.h"
#include "StateEnum.h"
#include "Combo.h"

class State;
class Character
{
private:
	int m_PlayerId;
	std::map<StateEnum,State*> m_States;
	State* m_CurrentState;
	int m_MaxLife;
	float m_currentLife;
	InputHandle m_PlayerInput;
	std::string m_CharacterName;

	char m_up;
	char m_down;
	char m_right;
	char m_left;
	char m_action1;
	char m_action2;
	char m_action3;

	Combo* combo;

public:
	int currentLife;

	//Constructor
	Character(std::string p_CharacterName,int p_PlayerId,int p_MaxLife);
	~Character();
	
	//Method
	void TakeDamage(float p_Damage);
	void ExecuteAction();
	void SetState(State* p_State);
	void applyDamage(float p_amount);

	//Getter
	int GetPlayerID();

	void Update();
	void Draw();
};

