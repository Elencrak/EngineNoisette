#include "stdafx.h"
#include "Crouch.h"


Crouch::Crouch()
{
	m_Damage = 0;
}


Crouch::~Crouch()
{
}

void Crouch::Execute()
{
	std::cout << "Exec Crouch" << std::endl;
}
