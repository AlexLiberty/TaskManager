#include "TaskList.h"

void TaskList::addTask(const Task& task)
{
	tasks.push_back(task);
}

void TaskList::removeTask(const Task& task)
{
	tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());
}

void TaskList::saveToFile(const string& filename)
{
	ofstream file(filename, ios::app);
    if (file.is_open())
    {
        for (const Task& task : tasks) 
        {
            file << "Опис: " << task.getDescription() << "\n";
            file << "Пріоритет: " << task.getPriority() << "\n";
            file << "Заголовок: " << task.getTag() << "\n";
            file << "Термін виконання: " << task.getDueDate() << "\n";
            file << "\n";
        }
        file.close();
        cout << "Завдання збережено у файл: " << filename << endl;
    }
    else 
    {
        cout << "Помилка: неможливо відкрити файл для запису." << endl;
    }
}

Task* TaskList::findTaskByPriority(int priority)
{
    for (Task& task : tasks) 
    {
        if (task.getPriority() == priority) 
        {
            return &task;
        }
    }
	return nullptr;
}

Task* TaskList::findTaskByTag(const string& tag)
{
    for (Task& task : tasks) 
    {
        if (task.getTag() == tag)
        {
            return &task;
        }
    }
	return nullptr;
}

Task* TaskList::findTaskByDueDate(const string& dueDate)
{
    for (Task& task : tasks) 
    {
        if (task.getDueDate() == dueDate) 
        {
            return &task;
        }
    }
	return nullptr;
}

void TaskList::printTasks() const
{
    cout << "Перелік задач:" << endl;
    for (const Task& task : tasks)
    {        
        cout << "Опис: " << task.getDescription() << "\n";
        cout << "Пріоритет: " << task.getPriority() << "\n";
        cout << "Заголовок: " << task.getTag() << "\n";
        cout << "Термін виконання: " << task.getDueDate() << "\n";
        cout << "\n";
    }
}
