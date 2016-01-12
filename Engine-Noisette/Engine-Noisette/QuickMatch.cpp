#include "stdafx.h"
#include <vector>
#include "QuickMatch.h"
#include "Fight.h"

QuickMatch* QuickMatch::m_Singleton = nullptr;

QuickMatch::QuickMatch()
{
	m_Singleton = this;
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
		break;
	case FightState::P1Win:
		std::cout << "P1Win" << std::endl;
		break;
	case FightState::P2Win:
		std::cout << "P2Win" << std::endl;
		break;
	case FightState::Tie:
		std::cout << "Tie";
		break;
	}
}

Fight* QuickMatch::CreateFight()
{
	std::vector<Character*> players;
	
	Character* player1 = new Character("Michel", 1, 100);
	Character* player2 = new Character("Roger", 2, 150);

	player1->SetTargetCharacter(player2);
	player2->SetTargetCharacter(player1);

	players.push_back(player1);
	players.push_back(player2);

	m_Duration = -1;
	m_VictoryCondition = VictoryCondition::NoHealth;
	Fight* tmp = new Fight(new Arena("La tour de feuuuu"), GetInstance(), players);
	tmp->AddObserver(this);
	return tmp;
}

QuickMatch* QuickMatch::GetInstance()
{
	if (m_Singleton == nullptr)
		new QuickMatch();
	return m_Singleton;
}
