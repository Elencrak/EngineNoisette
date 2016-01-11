#include <math.h>
#include "stdafx.h"
#include "Character.h"
//#include "State.h"
#include "Attack.h"
#include "Stun.h"
#include "InAir.h"
#include "Normal.h"
#include <string>


Character::Character(std::string p_CharacterName, int p_PlayerId, int p_MaxLife) : m_PlayerInput(p_PlayerId)
{
	m_CharacterName = p_CharacterName;
	m_PlayerId = p_PlayerId;
	m_MaxLife = p_MaxLife;

	//m_PlayerInput = InputHandle(p_PlayerId);

	m_States = std::map<StateEnum ,State*>();
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Attack, new Attack()));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Stun, new Stun()));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::InAir, new InAir()));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Normal, new Normal()));
	m_CurrentState = m_States.at(StateEnum::Normal);

	// Création des input
	if (p_PlayerId == 1)
	{
		m_up = 'z';
		m_down = 's';
		m_right = 'd';
		m_left = 'q';
		m_action1 = '&';
		m_action2 = 'é';
		m_action3 = '"';
	}
	else
	{
		m_up = '5';
		m_down = '2';
		m_right = '3';
		m_left = '1';
		m_action1 = '7';
		m_action2 = '8';
		m_action3 = '9';
	}

	// ON cree no combo
}



Character::~Character()
{

}

void Character::TakeDamage(float p_Damage)
{
	m_CurrentState->TakeDamage(this, p_Damage);
}

void Character::ExecuteAction()
{
	combo->Execute();
}

void Character::SetState(State* p_State)
{
	m_CurrentState = p_State;
}

void Character::applyDamage(float p_amount)
{
	m_currentLife = fmax(currentLife - p_amount, 0);
}

int Character::GetPlayerID()
{
	return m_PlayerId;
}

void Character::Update()
{
	// A chaque tour on mets le valeur à jour
	std::cout << m_CurrentState->getStateName() << std::endl;
	std::string input;
	//std::cin >> input;
	std::getline(std::cin, input);
	
	if (input.size() == 1) {
		//Attaque simple
	} else if(input.size() > 1) {
		//Attaque multiple
		combo = new Combo();		
		for (int i = 0; i <  input.size(); i++) {
			if (input[i] == m_up) {
				combo->Add(m_PlayerInput.HandleInput(EnumAction::Up));
			}
			else if (input[i] == m_down)
			{
				combo->Add(m_PlayerInput.HandleInput(EnumAction::Down));
			}
			else if (input[i] == m_right)
			{
				combo->Add(m_PlayerInput.HandleInput(EnumAction::Right));
			}
			else if (input[i] = m_left)
			{
				combo->Add(m_PlayerInput.HandleInput(EnumAction::Left));
			}
			else if (input[i] = m_action1)
			{
				combo->Add(m_PlayerInput.HandleInput(EnumAction::Action1));
			}
			else if (input[i] = m_action2)
			{
				combo->Add(m_PlayerInput.HandleInput(EnumAction::Action2));
			}
			else if (input[i] = m_action3)
			{
				combo->Add(m_PlayerInput.HandleInput(EnumAction::Action3));
			}	
		}
	}

	//
	if (combo != nullptr) {
		this->ExecuteAction();
	}
}

void Character::Draw()
{
	// Render
}
