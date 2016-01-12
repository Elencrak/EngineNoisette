#include "stdafx.h"
#include "InAir.h"


InAir::InAir(Character* p_Character): State(p_Character)
{
	this->m_StateName = "InAir";
}


InAir::~InAir()
{
}

void InAir::Update()
{
	std::cout << "Update InAir" << std::endl;

}
//Degat /2
void InAir::TakeDamage(Character * p_Character, int damage)
{
	m_linkCharacter->applyDamage(damage / 2);
}

