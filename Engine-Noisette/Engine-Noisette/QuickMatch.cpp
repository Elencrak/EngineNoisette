#include "stdafx.h"
#include <vector>
#include "QuickMatch.h"
#include "Fight.h"

QuickMatch* QuickMatch::m_Singleton = nullptr;

QuickMatch::QuickMatch()
{
	m_Singleton = this;
	//this->CreateFight();
}

QuickMatch::~QuickMatch()
{
	for (std::vector<AbstractObservable*>::iterator it = m_Observables.begin(); it != m_Observables.end(); ++it)
	{
		delete *it;
	}
}

void QuickMatch::Notify(AbstractObservable * p_Observable)
{
	switch (p_Observable->m_fightState)
	{
	case FightState::Nothing:
		std::cout << "Nothing";
		break;
	case FightState::P1Win:
		std::cout << "P1Win";
		break;
	case FightState::P2Win:
		std::cout << "P2Win";
		break;
	case FightState::Tie:
		std::cout << "Tie";
		break;
	default:
		std::cout << "Default";
		break;
	}
}

Fight* QuickMatch::CreateFight()
{
	std::vector<Character*> players;
	
	players.push_back(new Character("Michel", 1, 100));
	players.push_back(new Character("Roger", 1, 150));

	m_Duration = -1;
	m_VictoryCondition = VictoryCondition::NoHealth;
	return new Fight(new Arena("La tour de feuuuu"),GetInstance(),players);
}

QuickMatch* QuickMatch::GetInstance()
{
	if (m_Singleton == nullptr)
		new QuickMatch();
	return m_Singleton;
}
