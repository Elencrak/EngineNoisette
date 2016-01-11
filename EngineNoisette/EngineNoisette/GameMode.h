#pragma once
#include "VictoryCondition.h"
#include "AbstractObservable.h"
//#include "Character.h"
class GameMode : public AbstractObserver
{

public:
	virtual void Notify(AbstractObservable* p_Observable) = 0;
	virtual void CreateFight() = 0;
	virtual GameMode* GetInstance() = 0;
	GameMode();
	~GameMode();

	// attributs
	int m_PlayerNumber;
	bool m_IsFinished;

private:
	VictoryCondition m_VictoryCondition;
	float m_Duration;
	GameMode* m_Singleton;
	//Character* m_winner;
};


