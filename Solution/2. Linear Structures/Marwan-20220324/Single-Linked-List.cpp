#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList {
 public:
  LinkedList();
  void insertAtHead(int element);
  void insertAtTail(int element);
  void insertAt(int element, int index);
  void removeAtHead();
  void removeAtTail();
  void removeAt(int index);
  int retrieveAt(int index);
  void replaceAt(int element, int index);
  bool isExist(int element);
  bool isItemAtEqual(int element, int index);
  void swap(int firstIndex, int secondIndex);
  bool isEmpty();
  int LinkedListSize();
  void clear();
  void print();
  ~LinkedList();

 private:
  Node *head, *tail;
  int size;
};

LinkedList::LinkedList() {
  head = tail = NULL;
  size = 0;
}

void LinkedList::insertAtHead(int element) {
  Node *newNode = new Node;
  newNode->data = element;
  if (size == 0) {
    head = tail = newNode;
    newNode->next = NULL;
  } else {
    newNode->next = head;
    head = newNode;
  }
  size++;
}

void LinkedList::insertAtTail(int element) {
  Node *newNode = new Node;
  newNode->data = element;
  if (size == 0) {
    head = tail = newNode;
    newNode->next = NULL;
  } else {
    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
  }
  size++;
}

void LinkedList::insertAt(int element, int index) {
  if (index < 0 || index > size) {
    cout << "ERROR! : [Out of the Range] \n";
  } else {
    Node *newNode = new Node;
    newNode->data = element;
    if (index == 0) {
      insertAtHead(element);
    } else if (index == size) {
      insertAtTail(element);
    } else {
      Node *current = head;
      for (int i = 1; i < index; i++) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
      size++;
    }
  }
}

void LinkedList::removeAtHead() {
  if (size == 0) {
    cout << "ERROR! : [The list is Empty]\n";
  } else if (size == 1) {
    delete head;
    tail = head = NULL;
    size--;
  } else {
    Node *current = head;
    head = head->next;
    delete current;
    size--;
  }
}

void LinkedList::removeAtTail() {
  if (size == 0) {
    cout << "ERROR! : [The list is Empty]\n";
  } else if (size == 1) {
    delete head;
    tail = head = NULL;
    size--;
  } else {
    Node *current = head->next;
    Node *trailCurrent = head;
    while (current != tail) {
      trailCurrent = current;
      current = current->next;
    }
    delete current;
    trailCurrent->next = NULL;
    tail = trailCurrent;
    size--;
  }
}

void LinkedList::removeAt(int index) {
  if (index < 0 || index >= size) {
    cout << "ERROR! : [Out of the Range]\n";
  } else {
    Node *current, *trailCurrent;
    if (index == 0) {
      current = head;
      head = head->next;
      delete current;
      size--;
      if (size == 0) {
        tail = NULL;
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

int LinkedList::retrieveAt(int index) {
  Node *current = head;
  int count = 0;
  while (current != NULL) {
    if (count == index) {
      return current->data;
    }
    count++;
    current = current->next;
  }
  return -1;
}

void LinkedList::replaceAt(int element, int index) {
  Node *current = head;
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

bool LinkedList::isExist(int element) {
  Node *current = head;
  while (current != nullptr) {
    if (current->data == element) {
      return true;
    }
    current = current->next;
  }
  return false;
}

bool LinkedList::isItemAtEqual(int element, int index) {
  Node *current = head;
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

void LinkedList::swap(int firstIndex, int secondIndex) {
  if (firstIndex == secondIndex) {
    return;
  }
  if (firstIndex < 0 || secondIndex < 0) {
    cout << "ERROR! : [Enter Invalid Index]\n";
  }
  Node *prev1 = NULL;
  Node *curr1 = head;
  int count1 = 0;
  while (curr1 != NULL && count1 != firstIndex) {
    prev1 = curr1;
    curr1 = curr1->next;
    count1++;
  }
  Node *prev2 = NULL;
  Node *curr2 = head;
  int count2 = 0;
  while (curr2 != NULL && count2 != secondIndex) {
    prev2 = curr2;
    curr2 = curr2->next;
    count2++;
  }
  if (curr1 == NULL || curr2 == NULL) {
    return;
  }
  if (prev1 != NULL) {
    prev1->next = curr2;
  } else {
    head = curr2;
  }
  if (prev2 != NULL) {
    prev2->next = curr1;
  } else {
    head = curr1;
  }
  Node *temp = curr1->next;
  curr1->next = curr2->next;
  curr2->next = temp;
}

bool LinkedList::isEmpty() { return (size == 0); }

int LinkedList::LinkedListSize() { return size; }

void LinkedList::clear() {
  Node *current;
  while (head != NULL) {
    current = head;
    head = head->next;
    delete current;
  }
  tail = NULL;
  size = 0;
}

void LinkedList::print() {
  Node *current = head;
  cout << "[ ";
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << "]";
}

LinkedList::~LinkedList() { clear(); }

int main() {
  LinkedList a;
  return 0;
}