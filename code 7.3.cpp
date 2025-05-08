#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Product {
    char name[50];
    int quantity;
    float price;
};
void addProduct() {
    Product p;
    cout << "Enter product name: ";
    cin.ignore();
    cin.getline(p.name, 50);
    cout << "Enter quantity: ";
    cin >> p.quantity;
    cout << "Enter price: ";
    cin >> p.price;

    ofstream out("inventory.txt", ios::app);
    if (!out) {
        cout << "Error opening file.\n";
        return;
    }
    out << p.name << " " << p.quantity << " " << p.price << "\n";
    out.close();
    cout << "Product added successfully.\n";
}

void viewInventory() {
    ifstream in("inventory.txt");
    if (!in) {
        cout << "Inventory is empty or file not found.\n";
        return;
    }

    Product p;
    cout << "\nInventory:\n";
    while (in >> p.name >> p.quantity >> p.price) {
        cout << "Name: " << p.name
             << ", Quantity: " << p.quantity
             << ", Price: $" << p.price << "\n";
    }
    in.close();
}
int loadInventory(Product*& products) {
    ifstream in("inventory.txt");
    if (!in) {
        cout << "Inventory file not found.\n";
        return 0;
    }

    int capacity = 10;
    int count = 0;
    products = new Product[capacity];

    while (in >> products[count].name >> products[count].quantity >> products[count].price) {
        count++;
        if (count >= capacity) {
            capacity *= 2;
            Product* newArray = new Product[capacity];
            for (int i = 0; i < count; i++)
                newArray[i] = products[i];
            delete[] products;
            products = newArray;
        }
    }

    in.close();
    return count;
}
void searchProduct() {
    Product* products = nullptr;
    int count = loadInventory(products);
    if (count == 0) {
        cout << "No inventory to search.\n";
        return;
    }

    char searchName[50];
    cout << "Enter product name to search: ";
    cin.ignore();
    cin.getline(searchName, 50);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            cout << "Product found: "
                 << "Quantity: " << products[i].quantity
                 << ", Price: $" << products[i].price << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Product not found.\n";

    delete[] products;
}

int main() {
    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: searchProduct(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
