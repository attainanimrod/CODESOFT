#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

struct Task
{
    string strTitle;
    string strDescription;
    bool blnCompleted;
};

class ToDo
{
public:
    ToDo();
    void viewTasks();
    void AddTask(Task stcTask);
    void markCompleted(Task stcTask);
    void deleteTask(Task stcTask);

    ~ToDo();

private:

    Task* arrList;

    //Helper functions
    void writeToBinaryFine(string strFilePath);
    Task* readFromBinaryFilr(string strFilePath);

};

#endif
