#include "stdafx.h"
#include "State.h"


State::State()
{
}


State::~State()
{
}

std::string State::getStateName()
{
	return m_StateName;
}

void State::TakeDamage(Character* p_Character, float damage)
{
	p_Character->applyDamage(damage);
}