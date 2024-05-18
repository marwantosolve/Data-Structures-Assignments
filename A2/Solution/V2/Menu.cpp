#include "AVL.cpp"
#include "BST.cpp"
#include "Heap.cpp"
#include "Item.cpp"

void menu() {
  BST bst;
  AVL avl;
  Heap heap;
  int choice, structureChoice;
  string name, category;
  int price;

  while (true) {
    cout << "\nSelect structure:\n1. BST\n2. AVL Tree\n3. Heap\n4. "
            "Exit\nChoose an option: ";
    cin >> structureChoice;

    if (structureChoice == 4) break;

    cout << "\n1. Add item\n2. Remove item\n3. Display items\n4. Exit\nChoose "
            "an option: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter category: ";
        cin >> category;
        cout << "Enter price: ";
        cin >> price;
        if (structureChoice == 1) {
          bst.insert(Item(name, category, price));
        } else if (structureChoice == 2) {
          avl.insert(Item(name, category, price));
        } else if (structureChoice == 3) {
          heap.insert(Item(name, category, price));
        }
        break;
      case 2:
        cout << "Enter item name to remove: ";
        cin >> name;
        if (structureChoice == 1) {
          bst.remove(name);
        } else if (structureChoice == 2) {
          avl.remove(name);
        } else if (structureChoice == 3) {
          heap.remove(name);
        }
        break;
      case 3:
        if (structureChoice == 1) {
          cout << "Items in BST (in-order traversal):\n";
          bst.inOrder();
        } else if (structureChoice == 2) {
          cout << "Items in AVL Tree (in-order traversal):\n";
          avl.inOrder();
        } else if (structureChoice == 3) {
          cout << "Items in Heap:\n";
          heap.display();
        }
        break;
      case 4:
        return;
      default:
        cout << "Invalid choice. Please try again.\n";
    }
  }
}