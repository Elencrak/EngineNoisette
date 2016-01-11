#include "stdafx.h"
#include "Adventure.h"


Adventure* Adventure::m_Singleton = nullptr;
void Adventure::Notify(AbstractObservable * p_Observable)
{
}

Fight* Adventure::CreateFight()
{
	return nullptr;
}

Adventure* Adventure::GetInstance()
{
	return nullptr;
}

Adventure::Adventure()
{
}


Adventure::~Adventure()
{
}
