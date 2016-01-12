#include "stdafx.h"
#include "InputHandle.h"
#include "Crouch.h"
#include "Jump.h"
#include "Kick.h"
#include "MoveBackward.h"
#include "MoveForward.h"
#include "Protect.h"
#include "Punch.h"

InputHandle::InputHandle(int p_PlayerId)
{
	
	m_Actions = std::map<EnumAction, Action*>();

	m_Actions.insert(std::pair<EnumAction, Action*>(EnumAction::Up, new Jump()));
	m_Actions.insert(std::pair<EnumAction, Action*>(EnumAction::Down, new Crouch()));
	m_Actions.insert(std::pair<EnumAction, Action*>(EnumAction::Right, new MoveForward()));
	m_Actions.insert(std::pair<EnumAction, Action*>(EnumAction::Left, new MoveBackward()));
	m_Actions.insert(std::pair<EnumAction, Action*>(EnumAction::Action1, new Kick()));
	m_Actions.insert(std::pair<EnumAction, Action*>(EnumAction::Action2, new Punch()));
	m_Actions.insert(std::pair<EnumAction, Action*>(EnumAction::Action3, new Protect()));
}


InputHandle::~InputHandle()
{
}

Action * InputHandle::HandleInput(EnumAction p_EnumAction)
{
	return m_Actions.at(p_EnumAction);
}

void InputHandle::ExcuteCombo()
{

}
