#pragma once
#include "VictoryCondition.h"
#include "AbstractObservable.h"
#include "Character.h"

class Fight;
class GameMode : public AbstractObserver
{
private:
	float m_Duration;
	VictoryCondition m_VictoryCondition;
	Fight* currentFight;

public:
	// attributs
	int m_PlayerNumber;
	bool m_IsFinished;

	// Constructor
	GameMode();
	~GameMode();

	// Method
	virtual void Notify(AbstractObservable* p_Observable) = 0;
	virtual Fight* CreateFight() = 0;
};


