#pragma once
#include "VictoryCondition.h"
#include "AbstractObservable.h"
#include "Character.h"
class GameMode : public AbstractObserver
{

public:
	virtual void Notify(AbstractObservable* o) = 0;
	virtual void CreateFight() = 0;
	virtual GameMode* GetInstance() = 0;
	GameMode();
	~GameMode();

	// attributs
	int playerNumber;
	bool isFinished;

private:
	VictoryCondition victoryCondition;
	float duration;
	GameMode* singleton;
	Character* winner;
};


