#pragma once
#include "task.h"
#include <fstream>
#include <algorithm>

class TaskList
{
private:
	vector<Task> tasks;
public:
    void addTask(const Task& task);
    void removeTask(const Task& task);
    void saveToFile(const string& filename);
    Task* findTaskByPriority(int priority);
    Task* findTaskByTag(const string& tag);
    Task* findTaskByDueDate(const string& dueDate);
    void printTasks() const;
};

