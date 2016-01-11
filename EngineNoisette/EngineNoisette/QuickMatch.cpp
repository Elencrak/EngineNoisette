#include "stdafx.h"
#include "QuickMatch.h"



void QuickMatch::Notify(AbstractObservable * p_Observable)
{
}

Fight* QuickMatch::CreateFight()
{

}

GameMode* QuickMatch::GetInstance()
{
	return m_Singleton;
}

QuickMatch::QuickMatch()
{
}


QuickMatch::~QuickMatch()
{
}
