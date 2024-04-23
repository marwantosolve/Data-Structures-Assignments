s#include <bits/stdc++.h>
using namespace std;

template <typename t>
struct Node {
  t data;
  Node* next;
  Node(t ele) : data(ele), next(nullptr) {}
};

template <typename t>
class Queue {
 private:
  Node<t>* frontNode;
  Node<t>* rearNode;
  int size;

 public:
  Queue();
  void enqueue(t ele);
  t dequeue();
  t first();
  bool isEmpty();
  int QueueSize();
  void clear();
  void print();
};

template <typename t>
Queue<t>::Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

template <typename t>
void Queue<t>::enqueue(t ele) {
  Node<t>* newnode = new Node<t>(ele);
  if (isEmpty()) {
    frontNode = newnode;
    rearNode = newnode;
  } else {
    rearNode->next = newnode;
    rearNode = newnode;
  }
  size++;
}

template <typename t>
t Queue<t>::dequeue() {
  if (isEmpty())
    cout << "Queue is empty" << endl;
  else {
    t popele = frontNode->data;
    Node<t>* temp = frontNode;
    frontNode = frontNode->next;
    if (frontNode == nullptr) rearNode = nullptr;
    delete temp;
    size--;
    return popele;
  }
}

template <typename t>
t Queue<t>::first() {
  if (isEmpty())
    cout << "Queue is empty" << endl;
  else {
    return frontNode->data;
  }
}

template <typename t>
bool Queue<t>::isEmpty() {
  return frontNode == nullptr;
}

template <typename t>
int Queue<t>::QueueSize() {
  return size;
}

template <typename t>
void Queue<t>::clear() {
  while (!isEmpty()) dequeue();
}

template <typename t>
void Queue<t>::print() {
  Node<t>* current = frontNode;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  Queue<int> ob;
  ob.enqueue(10);
  ob.enqueue(20);
  ob.enqueue(40);

  cout << "Top element : " << ob.first() << endl;
  cout << "Queue Size : " << ob.QueueSize() << endl;

  cout << "Queue elements : ";
  ob.print();

  cout << "Popped element : " << ob.dequeue() << endl;
  cout << "Queue Size : " << ob.QueueSize() << endl;

  ob.clear();
  cout << "Queue size after clear : " << ob.QueueSize() << endl;

  return 0;
}
