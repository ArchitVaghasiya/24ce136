
#include <iostream>
#include <cstring>
using namespace std;

class FuelType {
protected:
    char fuel[30];

public:
    FuelType(const char* f = "Unknown") {
        strncpy(fuel, f, 29);
        fuel[29] = '\0';
    }

    void displayFuel() const {
        cout << "Fuel Type: " << fuel << endl;
    }
};

class Brand {
protected:
    char brand[30];

public:
    Brand(const char* b = "Generic") {
        strncpy(brand, b, 29);
        brand[29] = '\0';
    }

    void displayBrand() const {
        cout << "Brand: " << brand << endl;
    }
};

class Car : public FuelType, public Brand {
public:
    Car(const char* f = "Unknown", const char* b = "Generic")
        : FuelType(f), Brand(b) {}

    void display() const {
        displayBrand();
        displayFuel();
    }
};

void staticCarQueue() {
    cout << "\n--- Static Car Service Queue ---" << endl;

    const int QUEUE_SIZE = 3;
    Car queue[QUEUE_SIZE] = {
        Car("Petrol", "Toyota"),
        Car("Diesel", "Ford"),
        Car("Electric", "Tesla")
    };

    for (int i = 0; i < QUEUE_SIZE; ++i) {
        cout << "\nCar " << i + 1 << " in queue:\n";
        queue[i].display();
    }
}

void dynamicCarQueue() {
    cout << "\n--- Dynamic Car Service Queue ---" << endl;

    int n;
    cout << "Enter number of cars in service queue: ";
    cin >> n;

    Car** queue = new Car*[n];

    for (int i = 0; i < n; ++i) {
        char fuel[30], brand[30];
        cout << "\nEnter fuel type for car " << i + 1 << ": ";
        cin.ignore();
        cin.getline(fuel, 30);
        cout << "Enter brand for car " << i + 1 << ": ";
        cin.getline(brand, 30);

        queue[i] = new Car(fuel, brand);
    }

    for (int i = 0; i < n; ++i) {
        cout << "\nCar " << i + 1 << " in queue:\n";
        queue[i]->display();
    }
    for (int i = 0; i < n; ++i)
        delete queue[i];
    delete[] queue;
}

int main() {
    staticCarQueue();
    dynamicCarQueue();

    return 0;
}
