#include <iostream>
using namespace std;
#define reka                     \
    ios::sync_with_stdio(false); \
    cout.tie(nullptr);           \
    cin.tie(nullptr);
// Node class for the circular linked list
template <typename T>
class node
{
public:
    T data;        // Data stored in the node
    node<T> *next; // Pointer to the next node in the list
    // Constructor to initialize node with given data and null next pointer
    node(T value)
    {
        data = value;
        next = nullptr;
    }
};
// Circular Linked List class
template <typename T>
class Circular_linked_list
{
protected:
    node<T> *head; // Pointer to the head of the list
    int size;      // Size of the list
public:
    // Constructor to initialize an empty list
    Circular_linked_list()
    {
        head = nullptr;
        size = 0;
    }
    // Function to insert a new node at the head of the list
    void insertAtHead(T element)
    {
        node<T> *newNode = new node<T>(element);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
        size++;
    }
    // Function to insert a new node at the tail of the list
    void insertAtTail(T element)
    {
        node<T> *newNode = new node<T>(element);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        size++;
    }
    // Function to insert a new node at a specific index in the list
    void insertAt(T element, int index)
    {
        if (index == 0)
        {
            insertAtHead(element);
            return;
        }
        else if (index == size)
        {
            insertAtTail(element);
            return;
        }
        node<T> *newNode = new node<T>(element);
        node<T> *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    // Function to remove the node at the head of the list
    void removeAtHead()
    {
        if (head == nullptr)
        {
            cerr << "List is empty!\n";
            return;
        }
        node<T> *temp = head->next;
        if (head == temp)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            node<T> *lastNode = head;
            while (lastNode->next != head)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = temp;
            delete head;
            head = temp;
        }
        size--;
    }
    // Function to remove the node at the tail of the list
    void removeAtTail()
    {
        if (head == nullptr)
        {
            cerr << "List is empty!\n";
            return;
        }
        node<T> *temp = head->next;
        if (head == temp)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            node<T> *previousNode = nullptr;
            while (temp->next != head)
            {
                previousNode = temp;
                temp = temp->next;
            }
            previousNode->next = head;
            delete temp;
        }
        size--;
    }
    // Function to remove the node at a specific index in the list
    void removeAt(int index)
    {
        if (index == 0)
        {
            removeAtHead();
            return;
        }
        else if (index == size - 1)
        {
            removeAtTail();
            return;
        }
        node<T> *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        node<T> *deletedNode = temp->next;
        temp->next = deletedNode->next;
        delete deletedNode;
        size--;
    }
    // Function to retrieve the data at a specific index in the list
    T retrieveAt(int index)
    {
        if (index < 0 || index >= size)
        {
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
        if (head == nullptr)
        {
            return false;
        }
        node<T> *temp = head;
        do
        {
            if (temp->data == element)
            {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    // Function to check if the data at a specific index is equal to a given element
    bool isItemAtEqual(T element, int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of range." << endl;
            return false;
        }
        return retrieveAt(index) == element;
    }
    // Function to swap the data at two given indices in the list
    void swap(int firstItemIdx, int secondItemIdx)
    {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size)
        {
            cout << "Index out of range." << endl;
            return;
        }
        if (firstItemIdx == secondItemIdx)
        {
            return;
        }
        node<T> *first = head;
        node<T> *second = head;
        for (int i = 0; i < firstItemIdx; i++)
        {
            first = first->next;
        }
        for (int i = 0; i < secondItemIdx; i++)
        {
            second = second->next;
        }
        T temp = first->data;
        first->data = second->data;
        second->data = temp;
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
            removeAtTail();
        }
    }
    // Function to print the elements of the list
    void print()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        node<T> *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main()
{
    reka;
    // Sample usage
    Circular_linked_list<int> list;
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
    list.insertAt(4, 1);
    list.print();
    list.removeAt(5);
    list.print();
    list.replaceAt(9, 1);
    list.print();
    cout << "Size: " << list.linkedListSize() << endl;
    cout << "Element at index 1: " << list.retrieveAt(1) << endl;
    cout << "Is 3 in the list? " << (list.isExist(3) ? "Yes" : "No") << endl;
    cout << "Is element at index 2 equal to 4? " << (list.isItemAtEqual(4, 2) ? "Yes" : "No") << endl;
    list.swap(0, 2);
    list.print();
    list.clear();
    list.print();
    return 0;
}
