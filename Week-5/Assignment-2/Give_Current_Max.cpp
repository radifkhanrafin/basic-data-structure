#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Student {
    string Name;
    int Roll;
    int Marks;
    
    Student(string n, int r, int m) : Name(n), Roll(r), Marks(m) {}
    
    // Custom comparator for sorting by Marks (descending) and Roll (ascending)
    bool operator<(const Student& other) const {
        if (Marks == other.Marks)
            return Roll < other.Roll;
        return Marks > other.Marks;
    }
};

class StudentManager {
private:
    multiset<Student> students;

public:
    // Insert a student and print the maximum
    void insertStudent(const string& name, int roll, int marks) {
        students.emplace(name, roll, marks);
        printMaxStudent();
    }

    // Print the current maximum student
    void printMaxStudent() const {
        if (students.empty()) {
            cout << "Empty" << endl;
        } else {
            const Student& top = *students.begin();
            cout << top.Name << " " << top.Roll << " " << top.Marks << endl;
        }
    }

    // Delete the current maximum student and print the new maximum
    void deleteMaxStudent() {
        if (students.empty()) {
            cout << "Empty" << endl;
        } else {
            students.erase(students.begin());
            printMaxStudent();
        }
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore newline after integer input

    StudentManager manager;

    // Reading the initial list of students
    for (int i = 0; i < N; ++i) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        cin.ignore(); // Ignore the newline character
        manager.insertStudent(name, roll, marks);
    }

    int Q;
    cin >> Q;
    cin.ignore(); // Ignore newline after integer input

    // Processing commands
    for (int i = 0; i < Q; ++i) {
        int command;
        cin >> command;
        cin.ignore(); // Ignore the newline character

        if (command == 0) {  // Insert student
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            cin.ignore(); // Ignore the newline character
            manager.insertStudent(name, roll, marks);
        } else if (command == 1) {  // Print max student
            manager.printMaxStudent();
        } else if (command == 2) {  // Delete max student
            manager.deleteMaxStudent();
        }
    }

    return 0;
}
