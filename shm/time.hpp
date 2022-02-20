#pragma once
#include "iObserver.hpp"
#include <list>
#include <memory>

class IObserver;

class Time {
public:
    Time();
    ~Time() = default;

    void attachObserver(IObserver*);

    void detachObserver(IObserver*);

    void onTimeChange();

private:
    std::list<IObserver*> observerList_;

    void notifyAll();
};