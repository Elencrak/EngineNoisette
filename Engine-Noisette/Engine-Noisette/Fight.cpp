#include "stdafx.h"
#include "Fight.h"


void Fight::Update()
{
	m_Arena->Update();
	for (std::vector<Character*>::iterator it = m_Characters.begin(); it != m_Characters.end(); ++it)
	{
		if (m_fightState == FightState::Nothing) {
			Character* tmp = *it;
			tmp->Update();

			for (std::vector<Character*>::iterator it2 = m_Characters.begin(); it2 != m_Characters.end(); ++it2) {
				Character* lifeTest = *it2;
				if (lifeTest->GetCurrentLife() == 0) {
					if (lifeTest->GetPlayerID() == 1) {
						this->m_fightState = FightState::P1Win;
					}
					else if (lifeTest->GetPlayerID() == 2) {
						this->m_fightState = FightState::P2Win;
					}
					this->NotifyObserver();
				}
			}
		}
	}
	// Check si un player à plus de vie ou que le temps est finis
}

void Fight::AddObserver(AbstractObserver* p_Observer)
{
	m_Observers.push_back(p_Observer);
}

void Fight::RemoveObserver(AbstractObserver* p_Observer)
{
	for (std::vector<AbstractObserver*>::iterator it = m_Observers.begin(); it != m_Observers.end(); ++it)
	{
		AbstractObserver* tmp = *it;
		if (tmp == p_Observer)
			m_Observers.erase(it);
	}
}

void Fight::NotifyObserver()
{
	for (std::vector<AbstractObserver*>::iterator it = m_Observers.begin(); it != m_Observers.end(); ++it)
	{
		AbstractObserver* tmp = *it;
		tmp->Notify(this);
	}
	 
}

Fight::Fight(Arena * p_Arene, GameMode * p_GameMode, std::vector<Character*> p_Characters)
{
	m_Arena = p_Arene;
	m_GameMode = p_GameMode;
	m_Characters = p_Characters;
	m_Observers = std::vector<AbstractObserver*>();
	m_fightState = FightState::Nothing;
}

Fight::~Fight()
{
	delete m_Arena;
	delete m_GameMode;
	for (std::vector<Character*>::iterator it = m_Characters.begin(); it != m_Characters.end(); ++it)
	{
		delete *it;
	}
	for (std::vector<AbstractObserver*>::iterator it = m_Observers.begin(); it != m_Observers.end(); ++it)
	{
		delete *it;
	}
}
