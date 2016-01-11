#pragma once
#include "AbstractObserver.h"
#include "Character.h"
#include "FightState.h"

class AbstractObservable
{
public:
	FightState m_fightState = FightState::Nothing;

	AbstractObservable();
	~AbstractObservable();

	virtual void AddObserver(AbstractObserver* p_Observer) = 0;
	virtual void RemoveObserver(AbstractObserver* p_Observer) = 0;
	virtual void NotifyObserver() = 0;
private:
	Character* m_Winner;
};
