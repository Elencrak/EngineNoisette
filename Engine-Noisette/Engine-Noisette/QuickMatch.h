#pragma once
#include "GameMode.h"
class QuickMatch : public GameMode
{
public:
	void Notify(AbstractObservable* p_Observable);
	Fight* CreateFight();
	static QuickMatch* GetInstance();

	QuickMatch();
	~QuickMatch();
private:
	VictoryCondition m_VictoryCondition;
	float m_Duration;
	static QuickMatch* m_Singleton;
	Character* m_winner;
};

