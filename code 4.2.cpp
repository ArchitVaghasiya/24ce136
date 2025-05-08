
#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    char name[50];
    int age;

public:
    Person(const char* n = "Unknown", int a = 0) {
        strncpy(name, n, 49);
        name[49] = '\0';
        age = a;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;

public:
    Employee(const char* n = "Unknown", int a = 0, int id = 0)
        : Person(n, a), employeeID(id) {}

    void display() const override {
        Person::display();
        cout << "Employee ID: " << employeeID << endl;
    }

    int getID() const {
        return employeeID;
    }
};

class Manager : public Employee {
    char department[50];

public:
    Manager(const char* n = "Unknown", int a = 0, int id = 0, const char* dept = "General")
        : Employee(n, a, id) {
        strncpy(department, dept, 49);
        department[49] = '\0';
    }

    void display() const override {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

void staticManagerHandling() {
    cout << "\n--- Static Manager Handling ---" << endl;
    const int SIZE = 2;
    Manager managers[SIZE] = {
        Manager("Archit", 25, 102, "CR"),
        Manager("Shrey", 62, 42, "IT")
    };

    for (int i = 0; i < SIZE; ++i) {
        cout << "Manager " << i + 1 << ":\n";
        managers[i].display();
        cout << endl;
    }
}

void retrievalManagerHandling() {
    cout << "\n--- Efficient Retrieval Handling ---" << endl;

    int size;
    cout << "Enter number of managers: ";
    cin >> size;

    Manager** managers = new Manager*[size];

    for (int i = 0; i < size; ++i) {
        char name[50], dept[50];
        int age, id;

        cout << "\nEnter name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter department: ";
        cin.ignore();
        cin.getline(dept, 50);

        managers[i] = new Manager(name, age, id, dept);
    }

    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (managers[i]->getID() == searchID) {
            cout << "\nManager Found:\n";
            managers[i]->display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Manager with ID " << searchID << " not found.\n";
    }

    for (int i = 0; i < size; ++i) {
        delete managers[i];
    }
    delete[] managers;
}

int main() {
    staticManagerHandling();
    retrievalManagerHandling();

    return 0;
}
