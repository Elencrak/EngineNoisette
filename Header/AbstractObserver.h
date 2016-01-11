#pragma once
#include "AbstractObservable.h"
#include <vector>
class AbstractObserver
{
public:
	virtual void Notify(AbstractObservable* o) = 0;
	AbstractObserver();
	~AbstractObserver();

	std::vector<AbstractObservable*> observables;
};

