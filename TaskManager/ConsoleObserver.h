#pragma once
#include "observer.h"

class ConsoleObserver : public Observer
{
public:
    void update(const string& message) override;
};

