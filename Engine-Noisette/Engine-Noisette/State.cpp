#include "stdafx.h"
#include "State.h"
#include <stdlib.h> 


State::State(Character* p_Character): m_linkCharacter(p_Character)
{
}


State::~State()
{
}

std::string State::getStateName()
{
	return m_StateName;
}

void State::TakeDamage(Character* p_SelfCharacter, float damage)
{
	p_SelfCharacter->applyDamage(damage);
	if (damage > 0)
	{
		int rand = std::rand() % 100;
		if (rand > 75)
			p_SelfCharacter->SetState(StateEnum::Stun);
	

	}
}