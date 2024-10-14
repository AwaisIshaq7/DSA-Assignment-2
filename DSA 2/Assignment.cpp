#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_SIZE 100

struct Queue {        // Queue structure
    string items[MAX_SIZE];
    int front, rear;

    Queue() : front(-1), rear(-1) {}

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(const string& name) {
        if (isFull()) {
            cerr << "Queue is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        items[++rear] = name;
    }

    void display(const string& label) const {
        if (isEmpty()) return;
        for (int i = front; i <= rear; ++i) {
            cout << label << ": " << items[i] << endl;
        }
    }    
};

void readFromFile(const string& filename, Queue& parentsQueue, Queue& teachersQueue, Queue& studentsQueue) {
    ifstream inputFile("C:Assign2.txt");
    if (!inputFile) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    string line;
    string currentLevel;
        // Read the file and display the content
    cout << "Random arrangement of people:" << endl;

    while (getline(inputFile, line)) {
        if (line == "Parent" || line == "Teacher" || line == "Student") {
            currentLevel = line;        // Update current level
        }
        else {
            cout << currentLevel << ": " << line << endl;
            if (currentLevel == "Parent") {
                parentsQueue.enqueue(line);
            }
            else if (currentLevel == "Teacher") {
                teachersQueue.enqueue(line);
            }
            else if (currentLevel == "Student") {
                studentsQueue.enqueue(line);
            }
        }
    }

    inputFile.close();
}
                     //In Main function
int main() {
    Queue parentsQueue, teachersQueue, studentsQueue;
     // Reading from file
    readFromFile("C:\\Assign2.txt", parentsQueue, teachersQueue, studentsQueue);
    //display on output
    cout << "\n***************************************\n";
    cout << "Priority based arrangement:\n";
    cout << "\nPriority 1. Parent, 2. Teacher, 3. Student:\n";

    parentsQueue.display("Parent");
    teachersQueue.display("Teacher");
    studentsQueue.display("Student");

    return 0;
}
