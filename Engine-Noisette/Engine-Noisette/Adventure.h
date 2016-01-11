#pragma once
#include "GameMode.h"
class Adventure : public GameMode
{
public:
	void Notify(AbstractObservable* p_Observable);
	Fight* CreateFight();
	static Adventure* GetInstance();
	Adventure();
	~Adventure();
private:
	VictoryCondition m_VictoryCondition;
	float m_Duration;
	static Adventure* m_Singleton;
	Character* m_winner;
};

