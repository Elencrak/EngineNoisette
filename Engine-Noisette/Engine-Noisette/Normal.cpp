#include "stdafx.h"
#include "Normal.h"


Normal::Normal(Character* p_Character) : State(p_Character)
{
	this->m_StateName = "Normal";
}


Normal::~Normal()
{
}

void Normal::Update()
{
	std::cout << "Update Normal" << std::endl;
}
