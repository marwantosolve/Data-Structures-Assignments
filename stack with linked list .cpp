#include <bits/stdc++.h>
using namespace std;

template <typename t>
struct Node {
    t data;
    Node* next;
    Node(t ele) : data(ele), next(nullptr) {}
};

template<typename t>
class Stack {
private:
    Node<t>* topNode;
    int size;
public:
    Stack();
    void push(t ele);
    t pop();
    t top();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};

template<typename t>
Stack<t>::Stack() : topNode(nullptr), size(0) {}

template<typename t>
void Stack<t>::push(t ele) {
    Node<t>* newnode = new Node<t>(ele);
    newnode->next = topNode;
    topNode = newnode;
    size++;
}

template<typename t>
t Stack<t>::pop() {
    if(isEmpty())
        cout << "Stack is empty" << endl;
    else {
        t popele = topNode->data;
        Node<t>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
        return popele;
    }
}

template<typename t>
t Stack<t>::top() {
    if(isEmpty())
        cout << "Stack is empty" << endl;
    else {
        return topNode->data;
    }
}

template<typename t>
bool Stack<t>::isEmpty() {
    return topNode == nullptr;
}

template<typename t>
int Stack<t>::stackSize() {
    return size;
}

template<typename t>
void Stack<t>::clear() {
    while(!isEmpty())
        pop();
}

template<typename t>
void Stack<t>::print() {
    Node<t>* current = topNode;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    Stack<int> ob;
    ob.push(10);
    ob.push(20);
    ob.push(40);

    cout << "Top element : " << ob.top() << endl;
    cout << "Stack Size : " << ob.stackSize() << endl;

    cout << "Stack elements : ";
    ob.print();

    cout << "Popped element : " << ob.pop() << endl;
    cout << "Stack Size : " << ob.stackSize() << endl;

    ob.clear();
    cout << "Stack size after clear : " << ob.stackSize() << endl;

    return 0;
}
