#include "stdafx.h"
#include "Jump.h"


Jump::Jump()
{
	m_Damage = 0;
}


Jump::~Jump()
{
}

void Jump::Execute()
{
	std::cout << "Exec Jump" << std::endl;
}
