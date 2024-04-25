#include <bits/stdc++.h>
using namespace std;
#define reka                     \
    ios::sync_with_stdio(false); \
    cout.tie(nullptr);           \
    cin.tie(nullptr);
template <typename T>
class node
{
public:
    T data;        // Data stored in the node
    node<T> *next; // Pointer to the next node in the list
    node<T> *prev; // Pointer to the previous node in the list
    // Constructor to initialize node with given data and null next and prev pointers
    node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
template <typename T>
class Doubly_circular_linked_list
{
protected:
    node<T> *head; // Pointer to the head of the list
    node<T> *tail; // Pointer to the tail of the list
    int size;      // Size of the list
public:
    // Constructor to initialize an empty list
    Doubly_circular_linked_list()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    // Destructor to deallocate memory
    ~Doubly_circular_linked_list()
    {
        clear();
    }
    // Function to insert a new node at the head of the list
    void insertAtHead(T element)
    {
        node<T> *newNode = new node<T>(element);
        if (head == nullptr)
        {
            // If the list is empty, set the new node as the head and tail
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            // If the list is not empty, make the new node point to the current head and update the head's previous pointer
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
        size++;
    }
    // Function to insert a new node at the tail of the list
    void insertAtTail(T element)
    {
        node<T> *newNode = new node<T>(element);
        if (tail == nullptr)
        {
            // If the list is empty, set the new node as the head and tail
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            // If the list is not empty, make the current tail point to the new node and update the tail pointer
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        size++;
    }
    // Function to insert a new node at a specific index in the list
    void insertAt(T element, int index)
    {
        if (index < 0 || index > size)
        {
            // If index is out of range, display error message and return
            cout << "Index out of range." << endl;
            return;
        }
        if (index == 0)
        {
            // If index is 0, insert at the head
            insertAtHead(element);
            return;
        }
        if (index == size)
        {
            // If index is equal to size, insert at the tail
            insertAtTail(element);
            return;
        }
        // If index is neither 0 nor size, insert at the specified index
        node<T> *newNode = new node<T>(element);
        node<T> *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
    }
    // Function to remove the node at the head of the list
    void removeAtHead()
    {
        if (head == nullptr)
        {
            // If the list is empty, display error message
            cerr << "List is empty!" << endl;
            return;
        }
        node<T> *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
        size--;
    }
    // Function to remove the node at the tail of the list
    void removeAtTail()
    {
        if (tail == nullptr)
        {
            // If the list is empty, display error message
            cerr << "List is empty!" << endl;
            return;
        }
        node<T> *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        size--;
    }
    // Function to remove the node at a specific index in the list
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            // If index is out of range, display error message and return
            cout << "Index out of range." << endl;
            return;
        }
        if (index == 0)
        {
            // If index is 0, remove from the head
            removeAtHead();
            return;
        }
        if (index == size - 1)
        {
            // If index is equal to size - 1, remove from the tail
            removeAtTail();
            return;
        }
        // If index is neither 0 nor size - 1, remove from the specified index
        node<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }
    // Function to retrieve the data at a specific index in the list
    T retrieveAt(int index)
    {
        if (index < 0 || index >= size)
        {
            // If index is out of range, display error message and return default value of type T
            cout << "Index out of range." << endl;
            return T();
        }
        node<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    // Function to replace the data at a specific index in the list
    void replaceAt(T newElement, int index)
    {
        if (index < 0 || index >= size)
        {
            // If index is out of range, display error message and return
            cout << "Index out of range." << endl;
            return;
        }
        node<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->data = newElement;
    }
    // Function to check if a given element exists in the list
    bool isExist(T element)
    {
        if (head == nullptr || tail == nullptr)
        {
            // If the list is empty, return false
            return false;
        }
        node<T> *temp = head;
        for (int i = 0; i < size; i++)
        {
            if (temp->data == element)
            {
                // If the element is found, return true
                return true;
            }
            temp = temp->next;
        }
        // If the element is not found, return false
        return false;
    }

    // Function to check if the data at a specific index is equal to a given element
    bool isItemAtEqual(T element, int index)
    {
        if (index < 0 || index >= size)
        {
            // If index is out of range, display error message and return false
            cout << "Index out of range." << endl;
            return false;
        }
        // Check if the data at the specified index is equal to the given element
        return retrieveAt(index) == element;
    }

    // Function to swap two nodes in the list without swapping data
    void swap(int firstItemIdx, int secondItemIdx)
    {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size)
        {
            // If either index is out of range, display error message and return
            cout << "Index out of range." << endl;
            return;
        }
        if (firstItemIdx == secondItemIdx)
        {
            // If both indices are the same, no need to swap, return
            return;
        }
        // Traverse the list to find the nodes at the specified indices
        node<T> *firstPrev = nullptr;
        node<T> *first = head;
        for (int i = 0; i < firstItemIdx; i++)
        {
            firstPrev = first;
            first = first->next;
        }
        node<T> *secondPrev = nullptr;
        node<T> *second = head;
        for (int i = 0; i < secondItemIdx; i++)
        {
            secondPrev = second;
            second = second->next;
        }
        // Update next pointers of adjacent nodes
        if (first->next != second)
        {
            first->next->prev = second;
            second->next->prev = first;
        }
        // Update prev pointers of adjacent nodes
        if (firstPrev != nullptr)
        {
            firstPrev->next = second;
        }
        else
        {
            head = second;
        }
        if (secondPrev != nullptr)
        {
            secondPrev->next = first;
        }
        else
        {
            head = first;
        }
        // Swap next pointers of nodes
        node<T> *temp = first->next;
        first->next = second->next;
        second->next = temp;
    }

    // Function to check if the list is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Function to get the size of the list
    int linkedListSize()
    {
        return size;
    }

    // Function to clear the list
    void clear()
    {
        while (!isEmpty())
        {
            // Keep removing nodes from the tail until the list is empty
            removeAtTail();
        }
    }

    // Function to print the elements of the list
    void print()
    {
        if (head == nullptr)
        {
            // If the list is empty, display message
            cout << "List is empty!" << endl;
            return;
        }
        // Traverse the list and print each node's data
        node<T> *temp = head;
        for (int i = 0; i < size; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
// Main function
int main()
{
    // Sample usage
    Doubly_circular_linked_list<int> list;
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
    list.insertAt(10, 6); // Adjusted index
    list.print();
    list.removeAt(5);
    list.print();
    list.replaceAt(9, 3);
    list.print();
    cout << "Size: " << list.linkedListSize() << endl;
    cout << "Element at index 1: " << list.retrieveAt(1) << endl;
    cout << "Is 3 in the list? " << (list.isExist(3) ? "Yes" : "No") << endl;
    cout << "Is element at index 2 equal to 4? " << (list.isItemAtEqual(1, 2) ? "Yes" : "No") << endl;
    list.swap(0, 2);
    list.print();
    list.clear();
    list.print();
    return 0;
}
