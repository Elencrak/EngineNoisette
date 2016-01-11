#pragma once
#include "GameMode.h"
class Tournament : public GameMode
{
public:
	void Notify(AbstractObservable* p_Observable);
	Fight* CreateFight();
	static Tournament* GetInstance();
	Tournament();
	~Tournament();
private:
	VictoryCondition m_VictoryCondition;
	float m_Duration;
	static Tournament* m_Singleton;
	Character* m_winner;
};

