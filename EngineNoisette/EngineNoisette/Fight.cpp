#include "stdafx.h"
#include "Fight.h"


void Fight::Update()
{
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

/*Fight::Fight(Arena * p_Arene, GameMode * p_GameMode, std::vector<Character*> m_Characters)
{
	m_Arena = p_Arene;
	m_GameMode = p_GameMode;
	m_Characters = p_Characters;
	m_Observers = std::vector<Character*>();
}*/





Fight::~Fight()
{
	delete m_Arena;
	delete m_GameMode;
	//delete m_Characters;
}
