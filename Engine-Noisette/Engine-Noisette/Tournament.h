#pragma once
#include "GameMode.h"
class Tournament : public GameMode
{
public:
	void Notify(AbstractObservable* p_Observable);
	Fight* CreateFight();
	static GameMode* GetInstance();
	Tournament();
	~Tournament();
private:
	VictoryCondition m_VictoryCondition;
	float m_Duration;
	GameMode* m_Singleton;
	//Character* m_winner;
};

