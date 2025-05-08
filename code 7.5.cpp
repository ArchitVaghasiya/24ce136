#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

ostream& currency(ostream& os) {
    return os << "₹";
}

void displayReport() {
    string students[] = {"Archit", "Param", "Shrey", "Raj"};
    double marks[] = {94.5, 93.5, 90.4, 81.2};
    double tuitionFees[] = {5000, 4800, 5300, 4900};

    cout << "\n--- Student Marks and Tuition Fees ---\n";

    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(20) << ""
         << setw(10) << ""
         << setw(15) << "" << setfill(' ') << endl;

    for (int i = 0; i < 4; ++i) {
        cout << left << setw(20) << students[i]
             << setw(10) << fixed << setprecision(1) << marks[i]
             << setw(2) << "$" << fixed << setprecision(2) << tuitionFees[i] << endl;
    }
}

int main() {
    displayReport();
    return 0;
}
