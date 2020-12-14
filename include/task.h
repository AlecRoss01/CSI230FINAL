#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool fileExists(string name); // done
bool addTask(string name, string task); // done
bool removeTask(string name, int taskNum); //done
int getTaskAmount(string name); // done
bool addPerson(string name); // done
bool addGroup(string group); //done
bool addPersonToGroup(string name, string group); //done
void printTasks(string name); //done
void printAssociations(string group); //done
