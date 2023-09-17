#include "task.h"
#include "tasklist.h"
#include "observer.h"
#include "consoleobserver.h"
#include <windows.h>

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TaskList taskList;
    ConsoleObserver consoleObserver;

    Task task1("Завдання 1", 1, "Робота", "2023-09-15");
    task1.addObserver(&consoleObserver);

    Task task2("Завдання 2", 2, "Дім", "2023-09-17");
    task2.addObserver(&consoleObserver);

    taskList.addTask(task1);
    taskList.addTask(task2);

    taskList.printTasks();

    task2.setDescription("Оновлено завдання 2");
    task2.setPriority(5);

    taskList.addTask(task2);

    Task* foundTask = taskList.findTaskByTag("Дім");
    if (foundTask) 
    {
        cout << "Знайдено завдання: " << foundTask->getDescription() << endl;
    }
    else
    {
        cout << "Завдання не знайдено." << endl;
    }

    taskList.printTasks();

    taskList.saveToFile("tasks.txt");

    return 0;
}