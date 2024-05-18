#include "AVL.cpp"
#include "BST.cpp"
#include "Item.cpp"
#include "MaxHeap.cpp"
#include "MinHeap.cpp"

void displayMenu() {
  cout << "========================\n";
  cout << "      Tree Menu\n";
  cout << "========================\n";
  cout << "1. Binary Search Tree\n";
  cout << "2. Min-Heap\n";
  cout << "3. Max-Heap\n";
  cout << "4. AVL Tree\n";
  cout << "0. Exit\n";
  cout << "========================\n";
  cout << "Enter your choice: ";
}
void displayInsertionMenu() {
  cout << "========================\n";
  cout << "1. Read from a file\n";
  cout << "2. Manually\n";
  cout << "========================\n";
  cout << "Enter your choice: ";
}
void displayOperationsMenu() {
  cout << "========================\n";
  cout << "1. Add item data\n";
  cout << "2. Remove item data\n";
  cout << "3. Display the item data normally\n";
  cout << "4. Display all the items sorted by their name ascending\n";
  cout << "5. Display all the items sorted by their name descending\n";
  cout << "6. Display all the items sorted by their prices ascending\n";
  cout << "7. Display all the items sorted by their prices descending\n";
  cout << "0. Back to main menu\n";
  cout << "========================\n";
  cout << "Enter your choice: ";
}

void menu() {
  try {
    BST bst;
    MinHeap minHeap;
    MaxHeap maxHeap;
    AVL avl;
    while (true) {
      displayMenu();
      int choice;
      cin >> choice;
      if (choice == 0) break;
      if (choice < 1 || choice > 5) {
        cout << "Invalid choice. Please try again.\n";
        continue;
      }
      displayInsertionMenu();
      int c;
      cin >> c;
      if (c < 1 || c > 2) {
        cout << "Invalid choice. Please try again.\n\n";
        continue;
      }

      if (c == 1) {
        string file_name;
        cout << "Enter file name: ";
        cin >> file_name;
        int size;
        ifstream infile(file_name);
        bool file_exists = infile.is_open();
        if (file_exists) {
          string line;
          getline(infile, line);
          size = stoi(line);
          for (int i = 0; i < size; i++) {
            getline(infile, line);
            string name = line;
            getline(infile, line);
            string cat = line;
            getline(infile, line);
            int p = stoi(line);
            switch (choice) {
              case 1:
                bst.insert(Item(name, cat, p));
                break;
              case 2:
                minHeap.insert(Item(name, cat, p));
                break;
              case 3:
                maxHeap.insert(Item(name, cat, p));
                break;
              case 4:
                avl.insert(Item(name, cat, p));
                break;
              default:
                break;
            }
          }
          infile.close();
        } else {
          cout << "ERROR,File not Found" << endl;
        }
      } else if (c == 2) {
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
            break;
          case 2:
            minHeap.insert(newItem);
            break;
          case 3:
            maxHeap.insert(newItem);
            break;
          case 4:
            avl.insert(newItem);
            break;
          default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
      }
      while (true) {
        displayOperationsMenu();
        int op;
        cin >> op;
        if (op == 0) break;
        string name, category;
        int price;
        switch (choice) {
          case 1:
            switch (op) {
              case 1:
              case 2:
                cout << "Enter item name: ";
                cin >> name;
                if (op == 1) {
                  cout << "Enter category: ";
                  cin >> category;
                  cout << "Enter price: ";
                  cin >> price;
                  bst.insert(Item(name, category, price));
                } else
                  bst.remove(name);
                break;
              case 3:
                bst.inOrder();
                break;
              case 4:
                bst.printItemsByNameAsc();
                break;
              case 5:
                bst.printItemsByNameDesc();
                break;
              case 6:
                bst.printItemsByPriceAsc();
                break;
              case 7:
                bst.printItemsByPriceDesc();
                break;
            }
            break;
          case 2:
            switch (op) {
              case 1:
              case 2:
                cout << "Enter item name: ";
                cin >> name;
                if (op == 1) {
                  cout << "Enter category: ";
                  cin >> category;
                  cout << "Enter price: ";
                  cin >> price;
                  minHeap.insert(Item(name, category, price));
                } else
                  minHeap.remove(name);
                break;
              case 3:
                minHeap.print();
                break;
              case 4:
                minHeap.printItemsByNameAsc();
                break;
              case 5:
                minHeap.printItemsByNameDesc();
                break;
              case 6:
                minHeap.printItemsByPriceAsc();
                break;
              case 7:
                minHeap.printItemsByPriceDesc();
                break;
            }
            break;
          case 3:
            switch (op) {
              case 1:
              case 2:
                cout << "Enter item name: ";
                cin >> name;
                if (op == 1) {
                  cout << "Enter category: ";
                  cin >> category;
                  cout << "Enter price: ";
                  cin >> price;
                  maxHeap.insert(Item(name, category, price));
                } else
                  maxHeap.remove(name);
                break;
              case 3:
                maxHeap.print();
                break;
              case 4:
                maxHeap.printItemsByNameAsc();
                break;
              case 5:
                maxHeap.printItemsByNameDesc();
                break;
              case 6:
                maxHeap.printItemsByPriceAsc();
                break;
              case 7:
                maxHeap.printItemsByPriceDesc();
                break;
            }
            break;
          case 4:
            switch (op) {
              case 1:
              case 2:
                cout << "Enter item name: ";
                cin >> name;
                if (op == 1) {
                  cout << "Enter category: ";
                  cin >> category;
                  cout << "Enter price: ";
                  cin >> price;
                  avl.insert(Item(name, category, price));
                } else
                  avl.remove(name);
                break;
              case 3:
                avl.inOrder();
                break;
              case 4:
                avl.printItemsByNameAsc();
                break;
              case 5:
                avl.printItemsByNameDesc();
                break;
              case 6:
                avl.printItemsByPriceAsc();
                break;
              case 7:
                avl.printItemsByPriceDesc();
                break;
            }
            break;
        }
        cout << "\n";
      }
    }
  } catch (const std::exception& e) {
    { std::cerr << "Error: " << e.what() << std::endl; }
  }
}