#pragma once
#include "VictoryCondition.h"
#include "AbstractObservable.h"
#include "Character.h"

class Fight;
class GameMode : public AbstractObserver
{

public:
	virtual void Notify(AbstractObservable* p_Observable) = 0;
	virtual Fight* CreateFight() = 0;
	GameMode();
	~GameMode();

	// attributs
	int m_PlayerNumber;
	bool m_IsFinished;

private:
	VictoryCondition m_VictoryCondition;
	float m_Duration;
	Character* m_winner;
	Fight* currentFight;
};


