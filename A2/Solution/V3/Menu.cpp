#include "readitem.cpp"



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

      cout << "Choose type of insertion:\n";
      cout << "1. Read from a file\n";
      cout << "2. manually\n";
      int c;
      cin >> c;
      string file_name;
      if (c == 1) {
          cout << "enter file name " << endl;
          cin >> file_name;
          switch (choice) {
              case 1:
                  readItems(file_name, "bst");
                  break;
              case 2:
                  readItems(file_name, "Min-Heap");
                  break;
              case 3:
                  readItems(file_name, "Max-Heap");
                  break;
              case 4:
                  readItems(file_name, "AVL");
                  break;
              default:
                  cout << "Invalid choice. Try again.\n";
                  break;
          }
      } else {
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
}
