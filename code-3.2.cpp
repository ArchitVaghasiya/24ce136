#include <iostream>
#include <vector>
using namespace std;

int recursiveSum(const vector<int>& arr, int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> array(size);
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];

    cout << "Recursive Sum: " << recursiveSum(array, size) << endl;
    cout << "Iterative Sum: " << iterativeSum(array) << endl;

    return 0;
}

