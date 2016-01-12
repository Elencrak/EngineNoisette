#include <math.h>
#include "stdafx.h"
#include "Character.h"
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
	m_currentLife = m_MaxLife;	

	m_States = std::map<StateEnum ,State*>();
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Normal, new Normal(this)));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Attack, new Attack(this)));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::Stun, new Stun(this)));
	m_States.insert(std::pair<StateEnum, State*>(StateEnum::InAir, new InAir(this)));
	m_CurrentState = m_States.at(StateEnum::Normal);

	m_CorrespondanceMap = std::map<char, EnumAction>();
	// Création des input
	if (p_PlayerId == 1)
	{
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('s', EnumAction::Up));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('x', EnumAction::Down));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('c', EnumAction::Right));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('w', EnumAction::Left));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('a', EnumAction::Action1));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('z', EnumAction::Action2));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('e', EnumAction::Action3));
	}
	else
	{
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('5', EnumAction::Up));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('2', EnumAction::Down));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('3', EnumAction::Right));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('1', EnumAction::Left));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('7', EnumAction::Action1));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('8', EnumAction::Action2));
		m_CorrespondanceMap.insert(std::pair<char, EnumAction>('9', EnumAction::Action3));
	}
	m_Combo = new Combo();
}

Character::~Character()
{
	for (std::map<StateEnum, State*>::iterator it = m_States.begin(); it != m_States.end(); it++) {
		State* tmp = it->second;
		delete tmp;
	}

	delete m_CurrentState;
	delete m_Combo;

}

void Character::TakeDamage(float p_Damage)
{
	m_CurrentState->TakeDamage(this, p_Damage);
}

void Character::ExecuteAction()
{
	m_Combo->Execute();	
	m_targetCharacter->TakeDamage(m_Combo->GetDamage());
	m_Combo->Clear();
}

void Character::SetState(StateEnum p_State)
{
	std::map<StateEnum, State*>::iterator it = m_States.find(p_State);
	if (it != m_States.end())
		m_CurrentState = it->second;
}

void Character::applyDamage(float p_amount)
{
	m_currentLife = fmax(m_currentLife - p_amount, 0);
}

Character * Character::GetCharacterTarget()
{
	return m_targetCharacter;
}

std::string Character::GetName()
{
	return m_CharacterName;
}

int Character::GetCurrentLife()
{
	return m_currentLife;
}

int Character::GetPlayerID()
{
	return m_PlayerId;
}

void Character::SetTargetCharacter(Character * p_TargetCharacter)
{
	m_targetCharacter = p_TargetCharacter;
}

void Character::Update()
{	
	if (m_CurrentState->getStateName() == "Stun")
	{
		m_CurrentState->Update();
			return;
	}
	// A chaque tour on mets le valeur à jour
	std::cout << "************************" << std::endl;

	std::cout << "C'est le tour de P" << m_PlayerId << " ";
	std::cout << GetName() << std::endl;
	std::cout << "PV: " << m_currentLife << " " << "Action: " << "  ";

	std::string input;
	getline(std::cin, input);

	m_CurrentState->Update();
	if (m_CurrentState->getStateName() == "Stun")
		return;

	//Attaque multiple
	for (int i = 0; i < 3; i++) {
		std::map<char, EnumAction>::iterator it = m_CorrespondanceMap.find(input[i]);
		if (it != m_CorrespondanceMap.end())
			m_Combo->Add(m_PlayerInput.HandleInput(it->second));
	}

	// si notre dernier input haut = inAir
	// si notre dernier input action = attack (si on est contact quand on géra la position)
	// si nos denière sont 3 attaque = stun
	// Normal si on fait rien

	if (input.size() != 0) {
		std::map<char, EnumAction>::iterator it = m_CorrespondanceMap.find(input[input.size() - 1]);
		if (it != m_CorrespondanceMap.end())
		{
			if (it->second == EnumAction::Up) {
				m_CurrentState = m_States[StateEnum::InAir];

			}
			else if (it->second == EnumAction::Action1 || it->second == EnumAction::Action2 || it->second == EnumAction::Action3) {
				m_CurrentState = m_States.at(StateEnum::Attack);
			}
		}
	}
	else {
		m_CurrentState = m_States.at(StateEnum::Normal);
	}		

	if (m_Combo->GetLength() > 0) {
		this->ExecuteAction();
	}
	std::cout << "************************" << std::endl;
}

void Character::Draw()
{
	// Render
}
