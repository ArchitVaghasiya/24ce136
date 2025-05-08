
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void printFormattedHeader() {
    cout << left << setw(20) << "Student Name"
         << setw(10) << "Marks"
         << setw(10) << "Grade" << endl;
    cout << string(40, '-') << endl;
}

void generateReport(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "Error: File could not be opened." << endl;
        return;
    }

    string name;
    int marks;
    char grade;

    printFormattedHeader();

    while (file >> name >> marks >> grade) {
        cout << left << setw(20) << name
             << setw(10) << marks
             << setw(10) << grade << endl;
    }

    file.close();
}

int main() {
    string filename = "students.txt";
    generateReport(filename);

    return 0;
}

