#pragma once
#include "AbstractObserver.h"
#include "Character.h"
class AbstractObservable
{
public:
	virtual void AddObserver(AbstractObserver o) = 0;
	virtual void RemoveObserver(AbstractObserver o) = 0;
	virtual void NotifyObserver() = 0;
	AbstractObservable();
	~AbstractObservable();

private:
	Character* winner;
};

