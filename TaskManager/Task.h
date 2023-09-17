#pragma once
#include "observer.h"

class Task
{
private:
    string description;
    int priority;
    string tag;
    string dueDate;
    vector<Observer*> observers;
public:
    Task(const string& description, int priority, const string& tag, const string& dueDate);

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers(const string& message);
    void setDescription(const string& description);
    void setPriority(int priority);
    void setDueDate(const string& dueDate);
    void setTag(const string& tag);
    const string& getDescription() const;
    int getPriority() const;
    const string& getDueDate() const;
    const string& getTag() const;
    bool operator==(const Task& other) const;            
};

