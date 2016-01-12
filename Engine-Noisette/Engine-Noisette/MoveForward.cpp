#include "stdafx.h"
#include "MoveForward.h"


MoveForward::MoveForward()
{
	m_Damage = 0;
}


MoveForward::~MoveForward()
{
}

void MoveForward::Execute()
{
	std::cout << "Exec MoveForWard" << std::endl;
}
