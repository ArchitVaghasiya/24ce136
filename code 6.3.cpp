#include <iostream>

using namespace std;

int* mergeSortedArrays(int* ptr1, int size1, int* ptr2, int size2, int* mergedSizePtr) {
    *mergedSizePtr = size1 + size2;

    int* mergedPtr = new int[*mergedSizePtr];

    int* p1 = ptr1;
    int* p2 = ptr2;
    int* pm = mergedPtr;

    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (*p1 < *p2) {
            *pm = *p1;
            p1++;
            i++;
        } else {
            *pm = *p2;
            p2++;
            j++;
        }
        pm++;
    }

    while (i < size1) {
        *pm = *p1;
        pm++;
        p1++;
        i++;
    }

    while (j < size2) {
        *pm = *p2;
        pm++;
        p2++;
        j++;
    }

    return mergedPtr;
}

int main() {
    int size1, size2;

    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int* arr1 = new int[size1];

    cout << "Enter " << size1 << " sorted elements for array 1:\n";
    for (int i = 0; i < size1; ++i)
        cin >> *(arr1 + i);

    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int* arr2 = new int[size2];

    cout << "Enter " << size2 << " sorted elements for array 2:\n";
    for (int i = 0; i < size2; ++i)
        cin >> *(arr2 + i);

    int mergedSize = 0;
    int* mergedArr = mergeSortedArrays(arr1, size1, arr2, size2, &mergedSize);

    cout << "Merged Sorted Array:\n";
    for (int i = 0; i < mergedSize; ++i)
        cout << *(mergedArr + i) << " ";
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;

    return 0;
}
