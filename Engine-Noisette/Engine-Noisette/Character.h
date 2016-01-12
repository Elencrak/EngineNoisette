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
	int m_MaxLife;
	float m_currentLife;
	std::string m_CharacterName;

	State* m_CurrentState;
	InputHandle m_PlayerInput;
	Combo* m_Combo;
	Character* m_targetCharacter;

	std::map<StateEnum, State*> m_States;
	std::map<char, EnumAction> m_CorrespondanceMap;
public:

	//Constructor
	Character(std::string p_CharacterName,int p_PlayerId,int p_MaxLife);
	~Character();
	
	//Method
	void TakeDamage(float p_Damage);
	void ExecuteAction();
	void SetState(StateEnum p_State);
	void applyDamage(float p_amount);

	//Getter
	int GetPlayerID();
	int GetCurrentLife();
	std::string GetName();	
	Character* GetCharacterTarget();

	// Setter
	void SetTargetCharacter(Character* p_TargetCharacter);

	void Update();
	void Draw();
};

