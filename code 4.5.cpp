#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Abstract Base Class
class Student {
protected:
    string name;
    int marks;

public:
    Student(const string& name, int marks) : name(name), marks(marks) {}
    virtual void computeGrade() const = 0; // Pure virtual function
    virtual void display() const {
        cout << "Name: " << name << "\nMarks: " << marks << endl;
    }
    virtual ~Student() {}
};

// Derived Class for Undergraduate Students
class Undergraduate : public Student {
public:
    Undergraduate(const string& name, int marks) : Student(name, marks) {}

    void computeGrade() const override {
        cout << "Undergraduate Student - ";
        display();
        if (marks >= 85)
            cout << "Grade: A\n";
        else if (marks >= 70)
            cout << "Grade: B\n";
        else if (marks >= 50)
            cout << "Grade: C\n";
        else
            cout << "Grade: F\n";
        cout << "----------------------\n";
    }
};

// Derived Class for Postgraduate Students
class Postgraduate : public Student {
public:
    Postgraduate(const string& name, int marks) : Student(name, marks) {}

    void computeGrade() const override {
        cout << "Postgraduate Student - ";
        display();
        if (marks >= 90)
            cout << "Grade: A\n";
        else if (marks >= 75)
            cout << "Grade: B\n";
        else if (marks >= 60)
            cout << "Grade: C\n";
        else
            cout << "Grade: F\n";
        cout << "----------------------\n";
    }
};

int main() {
    vector<shared_ptr<Student>> students;
    int choice;

    while (true) {
        cout << "\n1. Add Undergraduate Student\n2. Add Postgraduate Student\n3. Display Grades\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 4) break;

        string name;
        int marks;

        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;

        if (choice == 1) {
            students.push_back(make_shared<Undergraduate>(name, marks));
        } else if (choice == 2) {
            students.push_back(make_shared<Postgraduate>(name, marks));
        } else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "\n--- Student Grades ---\n";
    for (const auto& student : students) {
        student->computeGrade();
    }

    return 0;
}
