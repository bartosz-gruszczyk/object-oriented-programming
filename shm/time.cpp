#include "time.hpp"
#include "iObserver.hpp"
#include <iostream>
#include <list>
#include <memory>

void Time::attachObserver(IObserver* observer)
{
    observerList_.push_back(observer);
}

void Time::detachObserver(IObserver* observer)
{
    observerList_.remove(observer);
}

void Time::onTimeChange()
{
    notifyAll();
}

void Time::notifyAll()
{
    for (auto it = observerList_.begin(); it != observerList_.end(); ++it) {
        (*it)->nextDay();
    }
}
