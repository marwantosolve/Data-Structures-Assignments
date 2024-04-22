#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(T ele);
    T pop();
    T top();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};

template<typename T>
void Stack<T>::push(T ele) {
    elements.push_back(ele);
}

template<typename T>
T Stack<T>::pop() {
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
        return T();
    }
    T topElement = elements.back();
    elements.pop_back();
    return topElement;
}

template<typename T>
T Stack<T>::top() {
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
        return T();
    }
    return elements.back();
}

template<typename T>
bool Stack<T>::isEmpty() {
    return elements.empty();
}

template<typename T>
int Stack<T>::stackSize() {
    return elements.size();
}

template<typename T>
void Stack<T>::clear() {
    elements.clear();
}

template<typename T>
void Stack<T>::print() {
    for(int i = elements.size() - 1; i >= 0; --i)
        cout << elements[i] << " ";
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
