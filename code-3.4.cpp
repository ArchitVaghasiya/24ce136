#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T findMax(const vector<T>& collection) {
    T maxVal = collection[0];
    for (int i = 1; i < collection.size(); i++) {
        if (collection[i] > maxVal)
            maxVal = collection[i];
    }
    return maxVal;
}

template <typename T>
void reverseCollection(vector<T>& collection) {
    int start = 0, end = collection.size() - 1;
    while (start < end) {
        swap(collection[start], collection[end]);
        start++;
        end--;
    }
}

template <typename T>
void displayCollection(const vector<T>& collection) {
    for (int i = 0; i < collection.size(); i++) {
        cout << collection[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> intCollection = {5, 2, 9, 1, 7};
    vector<float> floatCollection = {3.5f, 2.1f, 6.8f, 1.2f};
    vector<char> charCollection = {'x', 'b', 'z', 'a'};

    cout << "Integer Collection:" << endl;
    displayCollection(intCollection);
    cout << "Max: " << findMax(intCollection) << endl;
    reverseCollection(intCollection);
    cout << "Reversed: ";
    displayCollection(intCollection);
    cout << endl;

    cout << "Float Collection:" << endl;
    displayCollection(floatCollection);
    cout << "Max: " << findMax(floatCollection) << endl;
    reverseCollection(floatCollection);
    cout << "Reversed: ";
    displayCollection(floatCollection);
    cout << endl;

    cout << "Character Collection:" << endl;
    displayCollection(charCollection);
    cout << "Max: " << findMax(charCollection) << endl;
    reverseCollection(charCollection);
    cout << "Reversed: ";
    displayCollection(charCollection);
    cout << endl;

    return 0;
}

