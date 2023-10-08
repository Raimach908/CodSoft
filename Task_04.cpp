#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

class ToDoList {
private:
    int noOfTask;
    int id;
    string task;
    string* statusTask;

public:
    ToDoList() 
    {
        statusTask = nullptr; 
        id = 0;
        task = "";
        noOfTask = 0;
    }

    int getNoOfTask();
    void addTask(int ntask);
    void viewTask();
    void removeTask(int idDel);
    void markTask();
    void updateTask(int update);
    ~ToDoList() 
    {
        delete[] statusTask; 
    }
};

int ToDoList::getNoOfTask() 
{
    ifstream f1;
    f1.open("backendfile.txt", ios::in);
    if (f1.fail()) {
        cout << "\n File doesn't found.";
    }
    else {
        noOfTask = 0;
        string line;
        // Read the file line by line and count tasks
        while (getline(f1, line)) 
        {
            noOfTask++;
        }
        f1.close();
    }
    return noOfTask;
}

void ToDoList::addTask(int ntask) 
{
    ofstream f1;
    f1.open("backendfile.txt", ios::app);
    for (int i = 0; i < ntask; i++) 
    {
        cout << "\n\t Enter task id: ";
        cin >> id;
        cin.ignore();
        cout << "\t Enter task description: ";
        getline(cin, task);
        f1 << id << " " << task << "\n";
        cout << "\t Task is added successfully.\n";
    }
    f1.close();
}

void ToDoList::viewTask() 
{
    ifstream f1;
    f1.open("backendfile.txt", ios::in);
    ifstream f2;
    f2.open("mark.txt", ios::in);
    if (f1.fail()) 
    {
        cout << "\n\t File doesn't exist.";
    }
    else 
    {
        if (getNoOfTask() == 0) 
        {
            cout << "\n\t No task is found.";
        }
        else 
        {
            cout << endl;
            for (int i = 0; i < getNoOfTask(); i++) 
            {
                f1 >> id;
                getline(f1, task);
                cout << "\t Task id: " << id;
                cout << "\n\t Task description: " << task;
                if (statusTask != nullptr) 
                {
                    cout << "\n\t Task status: " << statusTask[i];
                }
                cout << endl;
            }
        }
    }
    f1.close();
}

void ToDoList::removeTask(int idDel)
{
    ifstream f1("backendfile.txt");
    ofstream f2("temporary.txt");

    if (!f1.is_open() || !f2.is_open()) 
    {
        cout << "\nFile handling error." << endl;
        return;
    }

    int* arrayID = new int[getNoOfTask()];
    string* arrayTask = new string[getNoOfTask()];

    int noOfTasks = 0;
    bool found = false;
    // Read tasks from the input file
    while (f1 >> arrayID[noOfTasks]) 
    {
        getline(f1, arrayTask[noOfTasks]);
        noOfTasks++;
    }
    f1.close();

    for (int i = 0; i < noOfTasks; i++) 
    {
        if (idDel == arrayID[i]) 
        {
            found = true;
            continue; // Skip the task to be removed
        }
        f2 << arrayID[i] << " " << arrayTask[i] << "\n";
    }
    delete[] arrayID;
    delete[] arrayTask;
    f2.close();

    if (found) 
    {
        if (remove("backendfile.txt") != 0 || rename("temporary.txt", "backendfile.txt") != 0) 
        {
            cout << "\n\t Error updating the file." << endl;
        }
        else 
        {
            cout << "\n\t Task with ID " << idDel << " removed successfully." << endl;
        }
    }
    else 
    {
        cout << "\n\t Task with ID " << idDel << " not found." << endl;
    }
}

void ToDoList::markTask() 
{
    ifstream f1;
    f1.open("backendfile.txt", ios::in);
    ofstream f2;
    f2.open("mark.txt", ios::app);
    if (f1.fail()) 
    {
        cout << "\n\t File doesn't exist.";
    }
    else 
    {
        if (getNoOfTask() == 0) 
        {
            cout << "\n\t No task is found.";
        }
        else 
        {
            if (statusTask != nullptr) 
            {
                delete[] statusTask; // Release previous statusTask if it exists
            }
            statusTask = new string[getNoOfTask()]; // Allocate memory for statusTask
            cout << endl;
            cin.ignore(); // Add this line to clear the newline from previous input
            for (int i = 0; i < getNoOfTask(); i++) 
            {
                f1 >> id;
                getline(f1, task);
                cout << "\n\t Task id: " << id;
                cout << "\n\t Task description: " << task << endl;
                cout << "\t Enter task " << id << " status (completed/pending): ";
                getline(cin, statusTask[i]);
                f2 << statusTask[i] << "\n";
            }
        }
    }
    f1.close();
    f2.close();
}

void ToDoList::updateTask(int update) 
{
    fstream f1;
    f1.open("backendfile.txt", ios::in | ios::out);
    fstream f2;
    f2.open("mark.txt", ios::in | ios::out);

    if (f1.fail()) 
    {
        cout << "\n\t File doesn't exist.";
    }
    else 
    {
        if (getNoOfTask() == 0) 
        {
            cout << "\n\t No task is found.";
        }
        else 
        {
            cout << endl;
            bool found = false;
            for (int i = 0; i < getNoOfTask(); i++) 
            {
                f1 >> id;
                getline(f1, task);
                getline(f2, statusTask[i]);
                if (id == update) {
                    cout << "\n\t Enter updated task id: ";
                    cin >> id;
                    cin.ignore();
                    cout << "\t Enter task description: ";
                    getline(cin, task);
                    cout << "\t Enter task status: ";
                    getline(cin, statusTask[i]);
                    f1 << id << " " << task << "\n";
                    found = true;
                }
            }
            if (found) 
            {
                cout << "\n\t Task is updated successfully.\n";
            }
            else 
            {
                cout << "\n\t Task with ID " << update << " not exist.\n";
            }
        }
    }
    f1.close();
}

int main() 
{
    ToDoList tdlist;
    system("cls");
    system("color F4");
    cout << "\n\t\t ----------- Welcome to TO DO LIST ----------";
    
    // Main menu
    int choice = 0;
    while (choice >= 0 && choice < 7) 
    {
        cout << "\n\n\t 1) Add task";
        cout << "\n\t 2) View Tasks";
        cout << "\n\t 3) Remove task";
        cout << "\n\t 4) Mark task status (completed or pending) ";
        cout << "\n\t 5) Update task";
        cout << "\n\t 6) No of Tasks ";
        cout << "\n\t 7) Exit";
        cout << "\n\t Select one option...";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int noOfTask = 0;
            while (noOfTask <= 0) 
            {
                cout << "\n\t How many tasks do you want to add? ";
                cin >> noOfTask;
            }
            tdlist.addTask(noOfTask);
            break;
        }
        case 2: 
        {
            tdlist.viewTask();
            break;
        }
        case 3: 
        {
            int id = 0;
            while (id <= 0)
            {
                cout << "\n\t Which task (id) do you want to remove? ";
                cin >> id;
            }
            tdlist.removeTask(id);
            break;
        }
        case 4: 
        {
            tdlist.markTask();
            break;
        }
        case 5: 
        {
            int update;
            cout << "\n\t Which task do you need to update (enter task id)? ";
            cin >> update;
            tdlist.updateTask(update);
            break;
        }
        case 6: 
        {
            cout << "\n\t Number of tasks: " << tdlist.getNoOfTask();
            break;
        }
        case 7: 
        {
            cout << "\n\t Press any key to exit...";
            _getch();
            exit(1);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
