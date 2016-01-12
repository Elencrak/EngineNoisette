#pragma once
#include "AbstractObserver.h"
#include "Character.h"
#include "FightState.h"

class AbstractObservable
{
public:	
	// Attribs
	FightState m_fightState = FightState::Nothing;

	// Constructor
	AbstractObservable();
	~AbstractObservable();

	// Method
	virtual void AddObserver(AbstractObserver* p_Observer) = 0;
	virtual void RemoveObserver(AbstractObserver* p_Observer) = 0;
	virtual void NotifyObserver() = 0;
};

