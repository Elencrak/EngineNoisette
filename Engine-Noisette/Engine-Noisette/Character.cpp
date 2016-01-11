#include <math.h>
#include "stdafx.h"
#include "Character.h"
//#include "State.h"
#include "Attack.h"
#include "Stun.h"
#include "InAir.h"
#include "Normal.h"


Character::Character(std::string p_CharacterName, int p_PlayerId, int p_MaxLife)
{
	m_CharacterName = p_CharacterName;
	m_PlayerId = p_PlayerId;
	m_MaxLife = p_MaxLife;

	m_PlayerInput = InputHandle();

	m_States = std::map<StateEnum ,State*>();
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Attack, new Attack()));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Stun, new Stun()));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::InAir, new InAir()));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Normal, new Normal()));
	m_CurrentState = m_States.at(StateEnum::Normal);
}

Character::Character()
{

}


Character::~Character()
{

}

void Character::TakeDamage(float p_Damage)
{
	m_CurrentState->TakeDamage(this, p_Damage);
}

void Character::ExecuteAction()
{

}

void Character::SetState(State* p_State)
{
	m_CurrentState = p_State;
}

void Character::applyDamage(float p_amount)
{
	m_currentLife = fmax(currentLife - p_amount, 0);
}

int Character::GetPlayerID()
{
	return m_PlayerId;
}

void Character::Update()
{
	// A chaque tour on mets le valeur à jour
	std::cout << m_CurrentState->getStateName() << std::endl;
}

void Character::Draw()
{
	// Render
}
