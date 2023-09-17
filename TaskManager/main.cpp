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

    Task task1("�������� 1", 1, "������", "2023-09-15");
    task1.addObserver(&consoleObserver);

    Task task2("�������� 2", 2, "ĳ�", "2023-09-17");
    task2.addObserver(&consoleObserver);

    taskList.addTask(task1);
    taskList.addTask(task2);

    taskList.printTasks();

    task2.setDescription("�������� �������� 2");
    task2.setPriority(5);

    taskList.addTask(task2);

    Task* foundTask = taskList.findTaskByTag("ĳ�");
    if (foundTask) 
    {
        cout << "�������� ��������: " << foundTask->getDescription() << endl;
    }
    else
    {
        cout << "�������� �� ��������." << endl;
    }

    taskList.printTasks();

    taskList.saveToFile("tasks.txt");

    return 0;
}