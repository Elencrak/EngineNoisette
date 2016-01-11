#pragma once
#include "AbstractObservable.h"
#include "Arena.h"
#include "GameMode.h"
//#include "Character.h"
#include "AbstractObserver.h"
#include <vector>
class Fight : public AbstractObservable
{
public:
	void Update();
	void AddObserver(AbstractObserver* p_Observer);
	void RemoveObserver(AbstractObserver* p_Observer);
	void NotifyObserver();
	Fight();
	~Fight();
	Arena* m_Arena;
	GameMode* m_GameMode;
	//std::vector<Character*> m_Characters;

private:
	std::vector<AbstractObserver*> m_Observers;

};

