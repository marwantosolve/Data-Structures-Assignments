#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Queue {
private:
    vector<T> elements;
public:
    void enqueue(T ele);
    T dequeue();
    T first();
    bool isEmpty();
    int size();
    void clear();
    void print();
};

template<typename T>
void Queue<T>::enqueue(T ele) {
    elements.push_back(ele);
}

template<typename T>
T Queue<T>::dequeue() {
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
        return T();
    }
    T front = elements.front();
    elements.erase(elements.begin());
    return front;
}

template<typename T>
T Queue<T>::first() {
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
        return T();
    }
    return elements.front();
}

template<typename T>
bool Queue<T>::isEmpty() {
    return elements.empty();
}

template<typename T>
int Queue<T>::size() {
    return elements.size();
}

template<typename T>
void Queue<T>::clear() {
    elements.clear();
}

template<typename T>
void Queue<T>::print() {
    for(const auto& ele : elements)
        cout << ele << " ";
    cout << endl;
}

int main() {

    Queue<int> ob;
    ob.enqueue(10);
    ob.enqueue(20);
    ob.enqueue(40);

    cout << "Top element : " << ob.first() << endl;
    cout << "Queue Size : " << ob.size() << endl;

    cout << "Queue elements : ";
    ob.print();

    cout << "Popped element : " << ob.dequeue() << endl;
    cout << "Queue Size : " << ob.size() << endl;

    ob.clear();
    cout << "Queue size after clear : " << ob.size() << endl;

    return 0;
}
