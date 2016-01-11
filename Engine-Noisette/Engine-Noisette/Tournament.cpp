#include "stdafx.h"
#include "Tournament.h"


Tournament* Tournament::m_Singleton = nullptr;
void Tournament::Notify(AbstractObservable * p_Observable)
{
}

Fight* Tournament::CreateFight()
{
	return nullptr;
}

Tournament* Tournament::GetInstance()
{
	return nullptr;
}

Tournament::Tournament()
{
}


Tournament::~Tournament()
{
}
