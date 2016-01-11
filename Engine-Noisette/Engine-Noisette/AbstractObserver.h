#pragma once

#include <vector>
class AbstractObservable;
class AbstractObserver
{
public:
	virtual void Notify(AbstractObservable* p_Observable) = 0;
	AbstractObserver();
	~AbstractObserver();

	std::vector<AbstractObservable*> m_Observables;
};

