// Engine-Noisette.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	char lettre;
	while (true)
	{
		std::cin >> lettre;
		if (lettre != 'q')
			std::cout << "Vous avez tapez " << lettre << std::endl;
		else
			return 0;

	}
}

