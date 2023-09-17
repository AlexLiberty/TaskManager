#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer abstract
{
public:
	virtual void update(const string& message) = 0;
};

