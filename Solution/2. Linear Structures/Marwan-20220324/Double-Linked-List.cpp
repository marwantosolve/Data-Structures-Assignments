#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* next;
  Node<T>* prev;
};

template <typename T>
class LinkedList {
 public:
  LinkedList();
  void insertAtHead(T element);
  void insertAtTail(T element);
  void insertAt(T element, int index);
  void removeAtHead();
  void removeAtTail();
  void removeAt(int index);
  T retrieveAt(int index);
  void replaceAt(T element, int index);
  bool isExist(T element);
  bool isItemAtEqual(T element, int index);
  void swap(int firstIndex, int secondIndex);
  bool isEmpty();
  int LinkedListSize();
  void clear();
  void print();
  ~LinkedList();

 private:
  Node<T>* head;
  Node<T>* tail;
  int size;
};

template <typename T>
LinkedList<T>::LinkedList() {
  head = tail = nullptr;
  size = 0;
}

template <typename T>
void LinkedList<T>::insertAtHead(T element) {
  Node<T>* newNode = new Node<T>;
  newNode->data = element;
  newNode->next = head;
  newNode->prev = nullptr;
  if (head != nullptr) {
    head->prev = newNode;
  }
  head = newNode;
  if (tail == nullptr) {
    tail = head;
  }
  size++;
}

template <typename T>
void LinkedList<T>::insertAtTail(T element) {
  if (isEmpty()) {
    insertAtHead(element);
  } else {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = nullptr;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    size++;
  }
}

template <typename T>
void LinkedList<T>::insertAt(T element, int index) {
  if (index < 0 || index > size) {
    cout << "ERROR! : [Out of the Range] \n";
  } else if (index == 0) {
    insertAtHead(element);
  } else if (index == size) {
    insertAtTail(element);
  } else {
    Node<T>* current = head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    size++;
  }
}

template <typename T>
void LinkedList<T>::removeAtHead() {
  if (isEmpty()) {
    cout << "ERROR! : [The list is Empty]\n";
  } else {
    Node<T>* temp = head;
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    }
    delete temp;
    size--;
    if (isEmpty()) {
      tail = nullptr;
    }
  }
}

template <typename T>
void LinkedList<T>::removeAtTail() {
  if (isEmpty()) {
    cout << "ERROR! : [The list is Empty]\n";
  } else if (head == tail) {
    removeAtHead();
  } else {
    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    size--;
  }
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
  if (index < 0 || index >= size) {
    cout << "ERROR! : [Out of the Range]\n";
  } else if (index == 0) {
    removeAtHead();
  } else if (index == size - 1) {
    removeAtTail();
  } else {
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
  }
}

template <typename T>
T LinkedList<T>::retrieveAt(int index) {
  Node<T>* current = head;
  int count = 0;
  while (current != nullptr && count != index) {
    current = current->next;
    count++;
  }
  if (current != nullptr) {
    return current->data;
  } else {
    cout << "ERROR! : [Out of the Range]\n";
    return T();
  }
}

template <typename T>
void LinkedList<T>::replaceAt(T element, int index) {
  Node<T>* current = head;
  int count = 0;
  while (current != nullptr && count != index) {
    current = current->next;
    count++;
  }
  if (current != nullptr) {
    current->data = element;
  } else {
    cout << "ERROR! : [Out of the Range]\n";
  }
}

template <typename T>
bool LinkedList<T>::isExist(T element) {
  Node<T>* current = head;
  while (current != nullptr) {
    if (current->data == element) {
      return true;
    }
    current = current->next;
  }
  return false;
}

template <typename T>
bool LinkedList<T>::isItemAtEqual(T element, int index) {
  Node<T>* current = head;
  int count = 0;
  while (current != nullptr && count != index) {
    current = current->next;
    count++;
  }
  if (current != nullptr && current->data == element) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
void LinkedList<T>::swap(int firstIndex, int secondIndex) {
  if (firstIndex == secondIndex || firstIndex < 0 || secondIndex < 0) {
    cout << "ERROR! : [Enter Invalid Index]\n";
    return;
  }

  Node<T>* prev1 = nullptr;
  Node<T>* curr1 = head;
  int count1 = 0;
  while (curr1 != nullptr && count1 != firstIndex) {
    prev1 = curr1;
    curr1 = curr1->next;
    count1++;
  }

  Node<T>* prev2 = nullptr;
  Node<T>* curr2 = head;
  int count2 = 0;
  while (curr2 != nullptr && count2 != secondIndex) {
    prev2 = curr2;
    curr2 = curr2->next;
    count2++;
  }

  if (curr1 == nullptr || curr2 == nullptr) {
    cout << "ERROR! : [Enter Valid Index]\n";
    return;
  }

  if (prev1 != nullptr) {
    prev1->next = curr2;
  } else {
    head = curr2;
  }
  if (prev2 != nullptr) {
    prev2->next = curr1;
  } else {
    head = curr1;
  }

  Node<T>* temp = curr1->next;
  curr1->next = curr2->next;
  curr2->next = temp;

  temp = curr1->prev;
  curr1->prev = curr2->prev;
  curr2->prev = temp;

  if (curr1->next != nullptr) {
    curr1->next->prev = curr1;
  }
  if (curr2->next != nullptr) {
    curr2->next->prev = curr2;
  }
}

template <typename T>
bool LinkedList<T>::isEmpty() {
  return size == 0;
}

template <typename T>
int LinkedList<T>::LinkedListSize() {
  return size;
}

template <typename T>
void LinkedList<T>::clear() {
  Node<T>* current = head;
  while (current != nullptr) {
    Node<T>* next = current->next;
    delete current;
    current = next;
  }
  head = tail = nullptr;
  size = 0;
}

template <typename T>
void LinkedList<T>::print() {
  Node<T>* current = head;
  if (isEmpty()) {
    cout << "[ ]\n";
  } else {
    cout << "[ ";
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << "]\n";
  }
}

template <typename T>
LinkedList<T>::~LinkedList() {
  clear();
}

int main() {
  LinkedList<int> a;
  cout << boolalpha;
  a.insertAtTail(5);
  a.insertAtTail(7);
  a.insertAtTail(8);
  a.print();
  a.insertAtHead(10);
  a.print();
  a.insertAt(3, 1);
  a.print();
  a.replaceAt(9, 2);
  a.print();
  cout << a.LinkedListSize() << '\n';
  cout << a.retrieveAt(0) << '\n';
  cout << a.isExist(5) << '\n';
  cout << a.isEmpty() << '\n';
  cout << a.isItemAtEqual(7, 3) << '\n';
  a.removeAtTail();
  a.print();
  a.removeAtHead();
  a.print();
  a.removeAt(1);
  a.print();
  a.swap(0, 1);
  a.print();
  a.clear();
  a.print();
  return 0;
}
