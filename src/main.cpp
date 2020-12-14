#include "task.h"
#include <boost/program_options.hpp>



int main(int argc, const char *argv[]){
    string input;
    int intInput;
    if(!fileExists("general.txt")){
        addGroup("general");
    }
        try{
            boost::program_options::options_description desc("options");
            desc.add_options()
            ("ap", boost::program_options::value<string>(), "add person")
            ("ag", boost::program_options::value<string>(),"add group")
            ("atg", boost::program_options::value<string>(), "add a person to a specific group")
            ("at", boost::program_options::value<string>(), "add a task to person or group")
            ("rt", boost::program_options::value<string>(), "remove task from a person or group")
            ("pt", boost::program_options::value<string>(), "print tasks of a person or group")
            ("pa", boost::program_options::value<string>(),"print group members or what groups a person is part of");
            boost::program_options::variables_map vm;
            store(parse_command_line(argc, argv, desc), vm);
            boost::program_options::notify(vm);

            if(vm.count("ap")){
                if(addPerson(vm["ap"].as<string>())){
                    cout << "successfully added " << vm["ap"].as<string>() << endl;
                }
                else{
                    cout << "failed to add " << vm["ap"].as<string>() << endl;
                }
            }
            else if(vm.count("ag")){
                if(addGroup(vm["ag"].as<string>())){
                    cout << "succsessfully added " << vm["ag"].as<string>() << endl;
                }
                else{
                    cout << "failed to add " << vm["ag"].as<string>() << endl;
                }
            }
            else if(vm.count("atg")){
                cout << "please input group you wish to add to\n";
                getline(cin, input);
                if(addPersonToGroup(vm["atg"].as<string>(), input)){
                    cout << "succsessfully added " << input << " to " << vm["atg"].as<string>() << endl;
                }
                else{
                    cout << "failed to add " << input << " to " << vm["atg"].as<string>() << endl;
                }
            }
            else if(vm.count("at")){
                cout << "please input task you wish to add to " << vm["at"].as<string>() << endl;
                getline(cin, input);
                if(addTask(vm["at"].as<string>(), input)){
                    cout << "succsessfully added task\n";
                }
                else{
                    cout << "failed to add task\n";
                }
            }
            else if(vm.count("rt")){
                cout << "please choose which task number to remove\n";
                printTasks(vm["rt"].as<string>());
                cin >> intInput;
                if(removeTask(vm["rt"].as<string>(), intInput)){
                    cout << "succsessfully removed task\n";
                }
                else{
                    cout << "failed to remove task\n";
                }
            }
            else if(vm.count("pt")){
                printTasks(vm["pt"].as<string>());
            }
            else if(vm.count("pa")){
                printAssociations(vm["pa"].as<string>());
            }
        }
        catch (const boost::program_options::error &ex){
            cerr << ex.what() << '\n';
        }

}
