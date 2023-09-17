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
            file << "����: " << task.getDescription() << "\n";
            file << "��������: " << task.getPriority() << "\n";
            file << "���������: " << task.getTag() << "\n";
            file << "����� ���������: " << task.getDueDate() << "\n";
            file << "\n";
        }
        file.close();
        cout << "�������� ��������� � ����: " << filename << endl;
    }
    else 
    {
        cout << "�������: ��������� ������� ���� ��� ������." << endl;
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
    cout << "������ �����:" << endl;
    for (const Task& task : tasks)
    {        
        cout << "����: " << task.getDescription() << "\n";
        cout << "��������: " << task.getPriority() << "\n";
        cout << "���������: " << task.getTag() << "\n";
        cout << "����� ���������: " << task.getDueDate() << "\n";
        cout << "\n";
    }
}
