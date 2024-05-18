
#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST bst;
    int choice;
    string name, category;
    int price;

    while (true) {
        cout << "\n1. Add item\n2. Remove item\n3. Display items\n4. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter price: ";
                cin >> price;
                bst.insert(Item(name, category, price));
                break;
            case 2:
                cout << "Enter item name to remove: ";
                cin >> name;
                bst.remove(name);
                break;
            case 3:
                cout << "Items in BST (in-order traversal):\n";
                bst.inOrder();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}


