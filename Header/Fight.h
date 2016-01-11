#pragma once
#include "AbstractObservable.h"
#include "Arena.h"
#include "GameMode.h"
#include "Character.h"
#include "AbstractObserver.h"
#include <vector>
class Fight : public AbstractObservable
{
public:
	void Update();
	void AddObserver(AbstractObserver o);
	void RemoveObserver(AbstractObserver o);
	void NotifyObserver();
	Fight();
	~Fight();
	Arena* currentArena;
	GameMode* currentGameMode;
	std::vector<Character*> characters;

private:
	std::vector<AbstractObserver*> Observers;

};

