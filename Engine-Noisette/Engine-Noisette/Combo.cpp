#include "stdafx.h"
#include "Combo.h"


Combo::Combo()
{
}


Combo::~Combo()
{
}

void Combo::Execute()
{
	std::list<Action*>::iterator it;
	for (it = m_comboAction.begin(); it != m_comboAction.end(); ++it) {
		Action* tmp = *it;
		tmp->Execute();
	}
}

void Combo::Add(Action* p_action)
{
	m_comboAction.push_back(p_action);
}

void Combo::Remove(Action* p_action)
{
	std::list<Action*>::iterator it;
	for (it = m_comboAction.begin(); it != m_comboAction.end(); ++it) {
		Action* tmp = *it;
		if (tmp == p_action) {
			m_comboAction.erase(it);
		}
	}
	
}
