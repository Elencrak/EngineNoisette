#pragma once
#include "AbstractObservable.h"
#include "Arena.h"
#include "GameMode.h"
//#include "Character.h"
#include "AbstractObserver.h"
#include <vector>
class Fight : public AbstractObservable
{
private:
	std::vector<AbstractObserver*> m_Observers;	

	Arena* m_Arena;
	GameMode* m_GameMode;
	std::vector<Character*> m_Characters;

public:
	Fight(Arena* p_Arene, GameMode* p_GameMode, std::vector<Character*> m_Characters);
	~Fight();

	void Update();
	void AddObserver(AbstractObserver* p_Observer);
	void RemoveObserver(AbstractObserver* p_Observer);
	void NotifyObserver();

};

