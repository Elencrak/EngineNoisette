#include "stdafx.h"
#include "InAir.h"


InAir::InAir()
{
	this->m_StateName = "InAir";
}


InAir::~InAir()
{
}

void InAir::Update()
{
}
//Degat /2
void InAir::TakeDamage(Character * p_Character, float damage)
{
	p_Character->applyDamage(damage / 2);
}

