

#include "Item.h"
#include <vector>

class Heap {
public:
    Heap();
    ~Heap();

    void insert(const Item& newItem);
    void remove(const std::string& itemName);
    void display() const;

private:
    vector<Item> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    int findIndex(const std::string& itemName) const;
};

