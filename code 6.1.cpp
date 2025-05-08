#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 4) {
        size = 0;
        capacity = initialCapacity;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void append(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds.\n";
            return;
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds.\n";
            return -1;
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void print() const {
        std::cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    DynamicArray arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);

    arr.print();
    arr.removeAt(1);
    arr.print();

    std::cout << "Element at index 1: " << arr.get(1) << "\n";
    std::cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << "\n";

    return 0;
}
