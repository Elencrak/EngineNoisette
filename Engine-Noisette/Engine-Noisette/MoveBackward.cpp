#include "stdafx.h"
#include "MoveBackward.h"
#include <iostream>

MoveBackward::MoveBackward()
{
	m_Damage = 0;
}


MoveBackward::~MoveBackward()
{
}

void MoveBackward::Execute()
{
	std::cout << "Exec MoveBackWard" << std::endl;
}
