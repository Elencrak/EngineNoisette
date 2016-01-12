#include "stdafx.h"
#include "Action.h"

Action::Action()
{
	m_Damage = 0;
}


Action::~Action()
{
}

int Action::GetDamage()
{
	return m_Damage;
}
