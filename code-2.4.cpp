#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;
public:
    Item() {
        itemID = 0;
        itemName = "Default";
        price = 0.0;
        quantity = 0;
    }

    Item(int id, string name, double p, int q) {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    void addStock(int amount) {
        if (amount > 0)
            quantity += amount;
    }

    void sellItem(int amount) {
        if (amount > 0 && amount <= quantity)
            quantity -= amount;
    }

    void display() {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity in Stock: " << quantity << endl;
    }
};

int main() {
    vector<Item> inventory;
    inventory.push_back(Item());
    inventory.push_back(Item(101, "Notebook", 2.5, 100));
    inventory.push_back(Item(102, "Pen", 1.0, 200));
    inventory.push_back(Item(103, "Eraser", 0.5, 150));

    inventory[1].addStock(50);
    inventory[2].sellItem(30);
    inventory[3].sellItem(160);
    inventory[0].addStock(20);

    for (int i = 0; i < inventory.size(); i++) {
        cout << "Item " << i + 1 << " Details:" << endl;
        inventory[i].display();
        cout << endl;
    }

    return 0;
}
