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
#include <Windows.h>
int main()
{
	Game* NoisetteFighter = new Game("Noisette Fighter");

	std::cout << "Bienvenus sur  "<< NoisetteFighter->m_GameName << std::endl;
	std::cout << "Selection des mode " << std::endl;
	GameMode* NoisetteFighterMode = nullptr;
	std::string lettre = "0";
	
	while (lettre != "1"){
		std::cout << "**********************************************" << std::endl
			<< "Les modes selectionnables sont :  " << std::endl
			<< "1-Quick match" << std::endl
			<< "2-Aventure" << std::endl
			<< "3-Tournoi" << std::endl
			<< "********************************************" << std::endl;
		

		getline(std::cin, lettre);
		switch (lettre[0])
		{
		case '1':
			NoisetteFighterMode = QuickMatch::GetInstance();
			std::cout << std::endl << "Vous avez selectionner le mode quick match" << std::endl;
			std::cout << std::endl;

			std::cout << "Controls : " << std::endl;
			std::cout << std::endl;
			std::cout << "Player 1 " << std::endl;
			std::cout << "------------------------" << std::endl;
			std::cout << "Up : s " << std::endl;
			std::cout << "Down : x" << std::endl;
			std::cout << "Right : c" << std::endl;
			std::cout << "Left : w" << std::endl;
			std::cout << "Action1 : a" << std::endl;
			std::cout << "Action2 : z" << std::endl;
			std::cout << std::endl;
			std::cout << "Player 2 " << std::endl;
			std::cout << "-----------------------" << std::endl;
			std::cout << "Up : 5 " << std::endl;
			std::cout << "Down : 2" << std::endl;
			std::cout << "Right : 3" << std::endl;
			std::cout << "Left : 1" << std::endl;
			std::cout << "Action1 : 7" << std::endl;
			std::cout << "Action2 : 8" << std::endl;
			std::cout << std::endl;
			system("pause");
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
	}
	system("cls");
	std::cout << std::endl << "***********************" << std::endl;
	std::cout << "*   Debut du combat   *" << std::endl;
	std::cout << "***********************" << std::endl;
	std::cout << std::endl;

	if (NoisetteFighterMode == nullptr) 
		return -1;
	
	Fight* NoisetteFighterFight = NoisetteFighterMode->CreateFight();

	while (NoisetteFighterFight->m_fightState == FightState::Nothing)
	{
		NoisetteFighterFight->Update();
	}

	system("pause");
}

