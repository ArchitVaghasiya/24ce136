#include <iostream>
using namespace std;

struct Product
{
    int id;
    string name;
    int quantity;
    double price;
};

Product inventory[100];
int productCount = 0;

void addProduct(int id, string name, int quantity, double price)
{
    inventory[productCount].id = id;
    inventory[productCount].name = name;
    inventory[productCount].quantity = quantity;
    inventory[productCount].price = price;
    productCount++;
    cout << "Product added successfully!" << endl;
}

void updateQuantity(int id, int newQuantity)
{
    for (int i = 0; i < productCount; i++)
    {
        if (inventory[i].id == id)
        {
            inventory[i].quantity = newQuantity;
            cout << "Quantity updated successfully!" << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

double calculateTotalValue()
{
    double total = 0;
    for (int i = 0; i < productCount; i++)
    {
        total += inventory[i].quantity * inventory[i].price;
    }
    return total;
}

int main()
{
    int choice;
    while (true)
    {
        cout << "Inventory Management System\n";
        cout << "1. Add a new product\n";
        cout << "2. Update product quantity\n";
        cout << "3. Calculate total value\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            int id, quantity;
            string name;
            double price;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product quantity: ";
            cin >> quantity;
            cout << "Enter product price: ";
            cin >> price;
            addProduct(id, name, quantity, price);
        }

        else if (choice == 2)
        {
            int id, quantity;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter new quantity: ";
            cin >> quantity;
            updateQuantity(id, quantity);
        }

        else if (choice == 3)
        {
            double total = calculateTotalValue();
            cout << "Total value of all products: " << total << endl;
        }

        else if (choice == 4)
        {
            cout << "Exiting...\n";
            break;
        }

        else
        {
            cout << "Invalid choice! Try again.\n";
        }
        cout << endl;
    }
    return 0;
}
