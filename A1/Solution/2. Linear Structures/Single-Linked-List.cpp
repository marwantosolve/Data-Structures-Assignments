#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* next;
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
  if (size == 0) {
    head = tail = newNode;
    newNode->next = nullptr;
  } else {
    newNode->next = head;
    head = newNode;
  }
  size++;
}

template <typename T>
void LinkedList<T>::insertAtTail(T element) {
  Node<T>* newNode = new Node<T>;
  newNode->data = element;
  if (size == 0) {
    head = tail = newNode;
    newNode->next = nullptr;
  } else {
    tail->next = newNode;
    newNode->next = nullptr;
    tail = newNode;
  }
  size++;
}

template <typename T>
void LinkedList<T>::insertAt(T element, int index) {
  if (index < 0 || index > size) {
    cout << "ERROR! : [Out of the Range] \n";
  } else {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    if (index == 0) {
      insertAtHead(element);
    } else if (index == size) {
      insertAtTail(element);
    } else {
      Node<T>* current = head;
      for (int i = 1; i < index; i++) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
      size++;
    }
  }
}

template <typename T>
void LinkedList<T>::removeAtHead() {
  if (size == 0) {
    cout << "ERROR! : [The list is Empty]\n";
  } else if (size == 1) {
    delete head;
    tail = head = nullptr;
    size--;
  } else {
    Node<T>* current = head;
    head = head->next;
    delete current;
    size--;
  }
}

template <typename T>
void LinkedList<T>::removeAtTail() {
  if (size == 0) {
    cout << "ERROR! : [The list is Empty]\n";
  } else if (size == 1) {
    delete head;
    tail = head = nullptr;
    size--;
  } else {
    Node<T>* current = head->next;
    Node<T>* trailCurrent = head;
    while (current != tail) {
      trailCurrent = current;
      current = current->next;
    }
    delete current;
    trailCurrent->next = nullptr;
    tail = trailCurrent;
    size--;
  }
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
  if (index < 0 || index >= size) {
    cout << "ERROR! : [Out of the Range]\n";
  } else {
    Node<T>*current, *trailCurrent;
    if (index == 0) {
      current = head;
      head = head->next;
      delete current;
      size--;
      if (size == 0) {
        tail = nullptr;
      }
    } else {
      current = head->next;
      trailCurrent = head;
      for (int i = 1; i < index; i++) {
        trailCurrent = current;
        current = current->next;
      }

      trailCurrent->next = current->next;
      if (tail == current) {
        tail = trailCurrent;
      }
      delete current;
      size--;
    }
  }
}

template <typename T>
T LinkedList<T>::retrieveAt(int index) {
  Node<T>* current = head;
  int count = 0;
  while (current != nullptr) {
    if (count == index) {
      return current->data;
    }
    count++;
    current = current->next;
  }
  return T();
}

template <typename T>
void LinkedList<T>::replaceAt(T element, int index) {
  Node<T>* current = head;
  int count = 0;
  if (index < 0 || index > size) {
    cout << "ERROR! : [Out of the Range]" << '\n';
    return;
  }
  while (current != nullptr) {
    if (count == index) {
      current->data = element;
      return;
    }
    count++;
    current = current->next;
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
  while (current != nullptr) {
    if (count == index && current->data == element) {
      return true;
    }
    count++;
    current = current->next;
  }
  return false;
}

template <typename T>
void LinkedList<T>::swap(int firstIndex, int secondIndex) {
  if (firstIndex == secondIndex) {
    return;
  }
  if (firstIndex < 0 || secondIndex < 0) {
    cout << "ERROR! : [Enter Invalid Index]\n";
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
}

template <typename T>
bool LinkedList<T>::isEmpty() {
  return (size == 0);
}

template <typename T>
int LinkedList<T>::LinkedListSize() {
  return size;
}

template <typename T>
void LinkedList<T>::clear() {
  Node<T>* current;
  while (head != nullptr) {
    current = head;
    head = head->next;
    delete current;
  }
  tail = nullptr;
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
