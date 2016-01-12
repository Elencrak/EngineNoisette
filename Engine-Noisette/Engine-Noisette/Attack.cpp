#include "stdafx.h"
#include "Attack.h"


Attack::Attack(Character* p_Character): State(p_Character)
{
	this->m_StateName = "Attack";
}


Attack::~Attack()
{
}

void Attack::Update()
{
	std::cout << "Update Attack" << std::endl;
}
