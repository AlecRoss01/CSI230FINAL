#include "task.h"


bool fileExists(string file){
    string fileName = file + ".txt";
    ifstream fin;
    fin.open(fileName);
    if(fin.fail()){
        fin.close();
        return false;
    }
    else{
        if(file == "task" || file == "task_driver"){
            return false;
        }
        fin.close();
        return true;
    }
}

/*int GetTaskAmount(string name){
    string fileName = name + ".txt";
    fstream fin;
    string input;
    int amount = 0;
    if(fileExists(name)){
        fin.open(fileName);
        while(fin.eof() == false){
            getline(fin, input);
            if(input == "TaskStart"){
                while(fin.eof() == false){
                    getline(fin, input);
                    amount++;
                }
                fin.close();
                return amount;
            }
        }
        fin.close();
    }
    return 0;
}*/


bool removeTask(string name, int taskNum){
    int taskAmount;
    string fileName = name + ".txt";
    int amount = 0;
    string input;
    ifstream fin;
    ofstream fout;
    if(fileExists(name)){
        fin.open(fileName);
        while(fin.eof() == false){
            getline(fin, input);
            if(input == "TaskStart"){
                while(fin.eof() == false){
                    getline(fin, input);
                    amount++;
                }
                fin.close();
            }
        }
        if(fin.is_open()){
            fin.close();
        }
        if(taskNum <= taskAmount){
            vector<string> fileVector;
            fin.open(fileName);
            while(fin.eof() == false){
                getline(fin, input);
                fileVector.push_back(input);
            }
            fin.close();
            for(long unsigned int i = 0; i < fileVector.size(); i++){
                if(fileVector[i] == "TaskStart"){
                    fileVector.erase(fileVector.begin()+i+taskNum);
                }
            }
            fout.open(fileName, fstream::trunc);
            while(fileVector.size() > 0){
            fout << fileVector[0] << endl;
            fileVector.erase(fileVector.begin());
        }
        fout.close();
        return true;
        }
    }
    else{
        return false;
    }
    return false;
}

bool addPersonToGroup(string name, string group){
    vector<string> fileStorage;
    string groupFile = group + ".txt";
    string personFile = name + ".txt";
    string input;
    ifstream fin;
    ofstream fout;
    if(fileExists(name) && fileExists(group)){
        //person file storage
        fin.open(personFile);
        while(fin.eof() == false){
            getline(fin, input);
            fileStorage.push_back(input);
        }
        fin.close();
        //person file editing
        fout.open(personFile);
        for(long unsigned int i = 0; i < fileStorage.size(); i++){
            if(fileStorage[i] == "TaskStart"){
                fout << group << endl;
            }
            fout << fileStorage[i] << endl;
        }
        fout.close();
        fileStorage.clear();
        //group file storage
        fin.open(groupFile);
        while(fin.eof() == false){
            getline(fin, input);
            fileStorage.push_back(input);
        }
        fin.close();
        //group file editing
        fout.open(groupFile);
        for(long unsigned int i = 0; i < fileStorage.size(); i++){
            if(fileStorage[i] == "TaskStart"){
                fout << name << endl;
            }
            fout << fileStorage[i] << endl;
        }
        fout.close();
        return true;
    }
    else{
        return false;
    }
    return false;
}


bool addTask(string name, string task){
    string fileName = name + ".txt";
    ofstream fout;
    if(fileExists(name)){
        fout.open(fileName, fstream::app);
        fout << task << endl;
        fout.close();
        return true;
    }
    else{
        return false;
    }
}


bool addPerson(string name){
    ofstream fout;
    string fileName = name + ".txt";
    if(!fileExists(name)){
        fout.open(fileName);
        fout << "person" << endl << "TaskStart" << endl;
        fout.close();
        //fout.open("general.txt", fstream::app);
        //fout << name << endl;
        //fout.close();
        addPersonToGroup(name, "general");
        return true;
    }
    return false;
}

bool addGroup(string group){
    ofstream fout;
    string fileName = group + ".txt";
    if(!fileExists(group)){
        fout.open(fileName);
        fout << "group" << endl << "TaskStart" << endl;
        fout.close();
        return true;
    }
    return false;
}


void printTasks(string name){
    int amount = 0;
    ifstream fin;
    string input;
    string fileName = name + ".txt";
    if(fileExists(name)){
        fin.open(fileName);
        while(fin.eof() == false){
            getline(fin, input);
            if(input == "TaskStart"){
                cout << name <<" Task List\n";
                while(fin.eof() == false){
                    getline(fin, input);
                    if(!(input == "")){
                        amount++;
                        cout << amount << ". " << input << endl;
                    }
                    
                }
                cout << "End of task list\n";
                fin.close();
            }
        }
        fin.close();
    }
}

void printAssociations(string name){
    string fileName = name + ".txt";
    ifstream fin;
    string input;
    bool taskstart = false;
    string association;
    if(fileExists(name)){
        fin.open(fileName);
        getline(fin, association);
        cout << "List of associations" << endl;
        while(fin.eof() == false){
            getline(fin, input);
            if(taskstart || input == "TaskStart"){
                taskstart = true;
            }
            else{
                if(!(input == "")){ 
                    cout << input << endl;
                }
            }
        }
        cout << "End of List\n";
    }
    
}
