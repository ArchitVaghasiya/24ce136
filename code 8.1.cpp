#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> seq = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Original sequence: ";
    for (int num : seq) {
        cout << num << " ";
    }
    cout << endl;

    reverse(seq.begin(), seq.end());

    cout << "Reversed sequence: ";
    for (int num : seq) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
