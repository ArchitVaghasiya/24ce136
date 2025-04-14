
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];
public:
    Student() {
        rollNumber = 0;
        name = "Default";
        for (int i = 0; i < 3; i++)
            marks[i] = 0.0;
    }

    Student(int roll, string n, float m1, float m2, float m3) {
        rollNumber = roll;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float getAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void display() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average: " << getAverage() << endl;
    }
};

int main() {
    vector<Student> students;
    students.push_back(Student());
    students.push_back(Student(101, "Alice", 85.5, 90.0, 88.0));
    students.push_back(Student(102, "Bob", 78.0, 82.5, 80.0));
    students.push_back(Student(103, "Charlie", 92.0, 88.5, 91.0));

    for (int i = 0; i < students.size(); i++) {
        cout << "Student " << i + 1 << " Details:" << endl;
        students[i].display();
        cout << endl;
    }

    return 0;
}
