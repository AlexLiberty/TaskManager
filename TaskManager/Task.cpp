#include "Task.h"

Task::Task(const string& description, int priority, const string& tag, const string& dueDate)
	: description(description), priority(priority), tag(tag), dueDate(dueDate) {}

void Task::addObserver(Observer* observer)
{
	observers.push_back(observer);
}

void Task::removeObserver(Observer* observer)
{
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Task::notifyObservers(const string& message)
{
	for (Observer* observer : observers) 
	{
		observer->update(message);
	}
}

void Task::setDescription(const string& description)
{
	this->description = description;
	notifyObservers("Опис оновлено\n");
}

void Task::setPriority(int priority)
{
	this->priority = priority;
	notifyObservers("Пріоритет оновлено\n");
}

void Task::setDueDate(const string& dueDate)
{
	this->dueDate = dueDate;
	notifyObservers("Термін виконання оновлено\n");
}

void Task::setTag(const string& tag)
{
	this->tag = tag;
	notifyObservers("Заголовок оновлено\n");
}

const string& Task::getDescription() const
{
	return description;
}

int Task::getPriority() const
{
	return priority;
}

const string& Task::getDueDate() const
{
	return dueDate;
}

const string& Task::getTag() const
{
	return tag;
}

bool Task::operator==(const Task& other) const
{
	return description == other.description && priority == other.priority &&
		tag == other.tag && dueDate == other.dueDate;
}
