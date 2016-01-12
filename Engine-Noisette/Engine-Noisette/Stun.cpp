#include "stdafx.h"
#include "Stun.h"


Stun::Stun(Character* p_Character): State(p_Character)
{
	this->m_StateName = "Stun";
}


Stun::~Stun()
{
}

void Stun::Update()
{
	if (nbStunRound >= 1) {
		nbStunRound = 0;
	}
	else
	{
		nbStunRound++;
		std::cout << m_linkCharacter->GetName() << " stun je passe un tour" << std::endl;
		m_linkCharacter->SetState(StateEnum::Normal);
	}


	/*std::cout << "Update Stun" << std::endl;
	if (std::rand() % 100 > 90)
		p_Character->SetState(StateEnum::Stun);*/

}

// Dégat x2
void Stun::TakeDamage(Character* p_Character, int damage)
{
	m_linkCharacter->applyDamage(damage*2);
}
