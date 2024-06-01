#include <bits/stdc++.h>
using namespace std;
#define reka                   \
  ios::sync_with_stdio(false); \
  cout.tie(nullptr);           \
  cin.tie(nullptr);

template <typename T>
class node {
 public:
  T data;         // Data stored in the node
  node<T> *next;  // Pointer to the next node in the list
  // Constructor to initialize node with given data and null next pointer
  node(T value) {
    data = value;
    next = nullptr;
  }
};
template <typename T>
class Singular_circular_linked_list {
 protected:
  node<T> *head;  // Pointer to the head of the list
  int size;       // Size of the list
 public:
  // Constructor to initialize an empty list
  Singular_circular_linked_list() {
    head = nullptr;
    size = 0;
  }
  // Destructor to deallocate memory
  ~Singular_circular_linked_list() { clear(); }
  // Function to insert a new node at the head of the list
  void insertAtHead(T element) {
    node<T> *newNode = new node<T>(element);
    if (head == nullptr) {
      // If the list is empty, set the new node as the head and point it to
      // itself
      head = newNode;
      newNode->next = head;
    } else {
      // If the list is not empty, make the new node point to the head, update
      // the last node's next pointer, and set the head to the new node
      newNode->next = head;
      node<T> *temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = newNode;
      head = newNode;
    }
    size++;
  }
  // Function to insert a new node at the tail of the list
  void insertAtTail(T element) {
    node<T> *newNode = new node<T>(element);
    if (head == nullptr) {
      // If the list is empty, set the new node as the head and point it to
      // itself
      head = newNode;
      newNode->next = head;
    } else {
      // If the list is not empty, find the last node and update its next
      // pointer to the new node
      newNode->next = head;
      node<T> *temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    size++;
  }
  // Function to insert a new node at a specific index in the list
  void insertAt(T element, int index) {
    if (index < 0 || index > size) {
      // If index is out of range, display error message and return
      cout << "Index out of range." << endl;
      return;
    }
    if (index == 0) {
      // If index is 0, insert at the head
      insertAtHead(element);
      return;
    }
    if (index == size) {
      // If index is equal to size, insert at the tail
      insertAtTail(element);
      return;
    }
    // If index is neither 0 nor size, insert at the specified index
    node<T> *newNode = new node<T>(element);
    node<T> *temp = head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
  }
  // Function to remove the node at the head of the list
  void removeAtHead() {
    if (head == nullptr) {
      // If the list is empty, display error message
      cerr << "List is empty!" << endl;
      return;
    }
    node<T> *temp = head->next;
    if (head == temp) {
      // If there's only one node in the list, delete it and set head to nullptr
      delete head;
      head = nullptr;
    } else {
      // If there are more than one node, find the last node, update its next
      // pointer to head->next, then delete the head node and update head
      node<T> *lastNode = head;
      while (lastNode->next != head) {
        lastNode = lastNode->next;
      }
      lastNode->next = temp;
      delete head;
      head = temp;
    }
    size--;
  }
  // Function to remove the node at the tail of the list
  void removeAtTail() {
    if (head == nullptr) {
      // If the list is empty, display error message
      cerr << "List is empty!" << endl;
      return;
    }
    node<T> *temp = head->next;
    if (head == temp) {
      // If there's only one node in the list, delete it and set head to nullptr
      delete head;
      head = nullptr;
    } else {
      // If there are more than one node, find the second last node, update its
      // next pointer to head, then delete the last node
      node<T> *previousNode = nullptr;
      while (temp->next != head) {
        previousNode = temp;
        temp = temp->next;
      }
      previousNode->next = head;
      delete temp;
    }
    size--;
  }
  // Function to remove the node at a specific index in the list
  void removeAt(int index) {
    if (index < 0 || index >= size) {
      // If index is out of range, display error message and return
      cout << "Index out of range." << endl;
      return;
    }
    if (index == 0) {
      // If index is 0, remove from the head
      removeAtHead();
      return;
    }
    if (index == size - 1) {
      // If index is equal to size - 1, remove from the tail
      removeAtTail();
      return;
    }
    // If index is neither 0 nor size - 1, remove from the specified index
    node<T> *temp = head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    node<T> *deletedNode = temp->next;
    temp->next = deletedNode->next;
    delete deletedNode;
    size--;
  }
  // Function to retrieve the data at a specific index in the list
  T retrieveAt(int index) {
    if (index < 0 || index >= size) {
      // If index is out of range, display error message and return default
      // value of type T
      cout << "Index out of range." << endl;
      return T();
    }
    node<T> *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp->data;
  }
  // Function to replace the data at a specific index in the list
  void replaceAt(T newElement, int index) {
    if (index < 0 || index >= size) {
      // If index is out of range, display error message and return
      cout << "Index out of range." << endl;
      return;
    }
    node<T> *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    temp->data = newElement;
  }
  // Function to check if a given element exists in the list
  bool isExist(T element) {
    if (head == nullptr) {
      // If the list is empty, return false
      return false;
    }
    node<T> *temp = head;
    do {
      if (temp->data == element) {
        // If the element is found, return true
        return true;
      }
      temp = temp->next;
    } while (temp != head);
    // If the element is not found, return false
    return false;
  }

  // Function to check if the data at a specific index is equal to a given
  // element
  bool isItemAtEqual(T element, int index) {
    if (index < 0 || index >= size) {
      // If index is out of range, display error message and return false
      cout << "Index out of range." << endl;
      return false;
    }
    // Check if the data at the specified index is equal to the given element
    return retrieveAt(index) == element;
  }
  // Function to swap two nodes in the list without swapping data
  void swap(int firstItemIdx, int secondItemIdx) {
    // Check if indices are out of range
    if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 ||
        secondItemIdx >= size) {
      // If either index is out of range, display error message and return
      cout << "Index out of range." << endl;
      return;
    }

    // If both indices are the same, no need to swap
    if (firstItemIdx == secondItemIdx) {
      // If both indices are the same, no need to swap, return
      return;
    }
    // Initialize pointers to traverse the list
    node<T> *firstPrev = head, *secondPrev = head, *current = head;
    // Ensure firstItemIdx is less than secondItemIdx
    if (firstItemIdx > secondItemIdx) {
      // Swap indices if needed
      int temp = firstItemIdx;
      firstItemIdx = secondItemIdx;
      secondItemIdx = temp;
    }
    // Traverse the list
    while (current->next != head) {
      // Update pointers until reaching the desired positions
      if (firstItemIdx == 1) {
        firstPrev = current;
        firstItemIdx = -1;
      } else if (firstItemIdx > 1) {
        firstItemIdx--;
      }
      if (secondItemIdx == 1) {
        secondPrev = current;
        secondItemIdx = -1;
      } else if (secondItemIdx > 1) {
        secondItemIdx--;
      }
      current = current->next;
    }
    // Handle special cases where indices are at head or tail of the list
    if (firstItemIdx == 0) {
      // Get the tail node
      node<T> *tail = head;
      for (int i = 0; i < size - 1; i++) {
        tail = tail->next;
      }
      node<T> *current = secondPrev->next;
      if (current == tail) {
        // If the second node is the tail, swap it with the head node
        secondPrev->next = head;
        tail->next = head->next;
        head->next = tail;
        swap_n(head, tail);  // Swap the head node with the tail
        return;
      }
      // Swap the head node with a node in the middle of the list
      swap_n(current->next, head->next);
      secondPrev->next = head;
      head = current;
      tail->next = current;
      return;
    } else if (firstPrev->next == secondPrev) {
      // If the nodes to be swapped are adjacent, swap them directly
      node<T> *current = secondPrev->next;
      secondPrev->next = current->next;
      current->next = secondPrev;
      firstPrev->next = current;
      return;
    }
    // Swap nodes that are not adjacent
    swap_n(firstPrev->next->next, secondPrev->next->next);
    swap_n(firstPrev->next, secondPrev->next);
  }

  // Function to swap nodes.
  void swap_n(node<T> *&n1, node<T> *&n2) {
    node<T> *temp = n1;
    n1 = n2;
    n2 = temp;
  }
  // Function to check if the list is empty
  bool isEmpty() { return size == 0; }

  // Function to get the size of the list
  int linkedListSize() { return size; }

  // Function to clear the list
  void clear() {
    while (!isEmpty()) {
      // Keep removing nodes from the tail until the list is empty
      removeAtTail();
    }
  }

  // Function to print the elements of the list
  void print() {
    if (head == nullptr) {
      // If the list is empty, display message
      cout << "List is empty!" << endl;
      return;
    }
    // Traverse the list and print each node's data
    node<T> *temp = head;
    do {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;
  }
};

// Main function
int main() {
  // Sample usage
  Singular_circular_linked_list<int> list;
  list.insertAtHead(1);
  list.print();
  list.insertAtHead(3);
  list.print();
  list.insertAtTail(4);
  list.print();
  list.insertAtTail(7);
  list.print();
  list.insertAtHead(5);
  list.print();
  list.insertAtTail(6);
  list.print();
  list.insertAt(10, 6);  // Adjusted index
  list.print();
  list.removeAt(5);
  list.print();
  list.replaceAt(9, 3);
  list.print();
  cout << "Size: " << list.linkedListSize() << endl;
  cout << "Element at index 1: " << list.retrieveAt(1) << endl;
  cout << "Is 3 in the list? " << (list.isExist(3) ? "Yes" : "No") << endl;
  cout << "Is element at index 2 equal to 4? "
       << (list.isItemAtEqual(1, 2) ? "Yes" : "No") << endl;
  list.swap(0, 2);
  list.print();
  list.clear();
  list.print();
  return 0;
}
