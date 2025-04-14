#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;
public:
    Employee(string n, double bSalary, double b = 1000.0) {
        name = n;
        basicSalary = bSalary;
        bonus = b;
    }

    inline double totalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Salary: $" << totalSalary() << endl;
    }
};

int main() {
    vector<Employee> employees;
    employees.push_back(Employee("Alice", 5000));
    employees.push_back(Employee("Bob", 6200, 1200));
    employees.push_back(Employee("Charlie", 5800));
    employees.push_back(Employee("Diana", 7000, 2000));

    for (int i = 0; i < employees.size(); i++) {
        cout << "Employee " << i + 1 << " Details:" << endl;
        employees[i].display();
        cout << endl;
    }

    return 0;
}

