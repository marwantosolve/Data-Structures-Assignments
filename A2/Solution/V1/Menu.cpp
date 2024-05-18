#include "AVL.cpp"
#include "BST.cpp"
#include "Item.cpp"
#include "MaxHeap.cpp"
#include "MinHeap.cpp"

void menu() {
  BST bst;
  MinHeap minHeap;
  MaxHeap maxHeap;
  AVL avl;

  while (true) {
    cout << "Choose a tree structure:\n";
    cout << "1. Binary Search Tree\n";
    cout << "2. Min-Heap\n";
    cout << "3. Max-Heap\n";
    cout << "4. AVL Tree\n";
    cout << "5. Exit\n";
    int choice;
    cin >> choice;

    if (choice == 5) break;

    string name, category;
    int price;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter category: ";
    cin >> category;
    cout << "Enter price: ";
    cin >> price;

    Item newItem(name, category, price);

    switch (choice) {
      case 1:
        bst.insert(newItem);
        bst.inOrder();
        break;
      case 2:
        minHeap.insert(newItem);
        minHeap.print();
        break;
      case 3:
        maxHeap.insert(newItem);
        maxHeap.print();
        break;
      case 4:
        avl.insert(newItem);
        avl.inOrder();
        break;
      default:
        cout << "Invalid choice. Try again.\n";
        break;
    }
  }
}
