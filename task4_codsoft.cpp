#include <bits/stdc++.h>

// Function to add a task to the to-do list
void addTask(const string& task, ofstream& file) {
    file << task << endl;
    cout << "Task added: " << task << endl;
}
// Function to view all tasks in the to-do list
void viewTasks(ifstream& file) {
    string task;
    int taskNumber = 1;
    cout << "To-Do List:" << endl;
    while (getline(file, task)) {
        cout << taskNumber << ". " << task << endl;
        taskNumber++;
    }

    file.clear(); // Clear any error flags on the file
    file.seekg(0); // Reset the file pointer to the beginning
}

// Function to delete a task from the to-do list
void deleteTask(int taskNumber, vector<string>& tasks, ofstream& file) {
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    
    tasks.erase(tasks.begin() + taskNumber - 1);
    
    file.close();
    file.open("todo.txt", ofstream::out | ofstream::trunc);
    
    for (const string& task : tasks)
     { file << task << endl; }
    cout << "Task " << taskNumber << " deleted." << endl;
}

int main() {
    ifstream inputFile("todo.txt");
    ofstream outputFile("todo.txt", ios::app);

    if (!inputFile.is_open() || !outputFile.is_open())
     {
        cout << "Error: Unable to open the to-do list file." << endl;
        return 1;
     }

    vector<string> tasks;
    string task;

    // Read existing tasks from the file into the vector
    while (getline(inputFile, task)) {
        tasks.push_back(task);
    }

    inputFile.close();

    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                cin.ignore(); // Consume the newline character
                getline(cin, task);
                addTask(task, outputFile);
                tasks.push_back(task);
                inputFile.close(); // Close and reopen input file
                inputFile.open("todo.txt");
                break;
            case 2:
                viewTasks(inputFile);
                break;
            case 3:
                int taskNumber;
                cout << "Enter the task number to delete: ";
                cin >> taskNumber;
                deleteTask(taskNumber, tasks, outputFile);
                inputFile.close(); // Close and reopen input file
                inputFile.open("todo.txt");
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    outputFile.close();

    return 0;
}
