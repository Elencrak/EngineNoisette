#include "stdafx.h"
#include "Tournament.h"



void Tournament::Notify(AbstractObservable * p_Observable)
{
}

Fight* Tournament::CreateFight()
{
	return nullptr;
}

GameMode * Tournament::GetInstance()
{
	return nullptr;
}

Tournament::Tournament()
{
}


Tournament::~Tournament()
{
}
