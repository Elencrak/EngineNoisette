#include "stdafx.h"
#include "Stun.h"


Stun::Stun()
{
	this->m_StateName = "Stun";
}


Stun::~Stun()
{
}

void Stun::Update()
{
}

// Dégat x2
void Stun::TakeDamage(Character* p_Character, float damage)
{
	p_Character->applyDamage(damage);
}
