#include "AVL.cpp"
#include "BST.cpp"
#include "Item.cpp"
#include "MaxHeap.cpp"
#include "MinHeap.cpp"

void print(vector<Item> v) {
  for (int i = 0; i < sizeof(v); i++) {
    cout << "Name: " << v[i].itemname << '\n'
         << "Category: " << v[i].category << '\n'
         << "Price: " << v[i].price << "\n====================\n";
  }
}
void readItems(string file_name, string tree) {
  vector<Item> v;
  int size;
  string Tree = tree;
  BST bst;
  MinHeap minHeap;
  MaxHeap maxHeap;
  AVL avl;
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
      v.push_back(Item(name, cat, p));
    }
    infile.close();
  }

  else {
    cout << "ERROR,File not Found" << endl;
    return;
  }

  if (Tree == "bst") {
    for (auto element : v) {
      bst.insert(element);
    }
  } else if (Tree == "Min-Heap") {
    for (auto element : v) {
      minHeap.insert(element);
    }
  } else if (Tree == "Max-Heap") {
    for (auto element : v) {
      maxHeap.insert(element);
    }
  } else if (Tree == "AVL") {
    for (auto element : v) {
      avl.insert(element);
    }
  } else {
    cout << "try again" << endl;
  }
}