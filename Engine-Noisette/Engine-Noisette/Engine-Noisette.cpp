// Engine-Noisette.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "GameMode.h"
#include "QuickMatch.h"
#include "Tournament.h"
#include "Adventure.h"
#include "Fight.h"
#include <iostream>


int main()
{
	Game* NoisetteFighter = new Game("Noisette Fighter");

	std::cout << "Bienvenus sur  "<< NoisetteFighter->m_GameName << std::endl;
	std::cout << "Selection des mode " << std::endl;
	GameMode* NoisetteFighterMode = nullptr;
	char lettre;
	do{
		std::cout << "**********************************************" << std::endl
			<< "Les modes selectionnables sont :  " << std::endl
			<< "Quick match tappez 1 pour le selectionner " << std::endl
			<< "Aventure match tappez 2 pour le selectionner " << std::endl
			<< "Tournoi match tappez 3 pour le selectionner " << std::endl
			<< "********************************************" << std::endl;
		std::cin >> lettre;
		switch (lettre)
		{
		case '1':
			NoisetteFighterMode = QuickMatch::GetInstance();
			std::cout << std::endl << "Vous avez selectionner le mode quick match" << std::endl;

			break;
		case '2':
			std::cout << std::endl << "Ce mode est en cours de developpement" << std::endl;
			break;
		case '3':
			std::cout << std::endl << "Ce mode est en cours de developpement" << std::endl;
			break;
		default:
			std::cout << std::endl << "Vous n'avez pas selectionner un mode existant" << std::endl;
			break;
		}
	}while (lettre != '1');
	
	if (NoisetteFighterMode == nullptr) 
		return -1;
	
	Fight* NoisetteFighterFight = NoisetteFighterMode->CreateFight();

	while (true)
	{

		NoisetteFighterFight->Update();
		/*std::cin >> lettre;
		if (lettre != 'q')
			std::cout << "Vous avez tapez " << lettre << std::endl;
		else
			return 0;*/
	}
}

