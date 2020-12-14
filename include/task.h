#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool fileExists(string name);
bool addTask(string name, string task);
bool removeTask(string name, int taskNum);
int getTaskAmount(string name);
bool addPerson(string name);
bool addGroup(string group);
bool addPersonToGroup(string name, string group);
void printTasks(string name);
void printAssociations(string group);
