#include "Item.h"

class MaxHeap
{
private:
  vector<Item> heap;

  void heapifyUp(int index);
  void heapifyDown(int index);

public:
  void insert(const Item &val);
  void remove(const string &itemName);
  Item extractMax();
  void print() const;

  void printItemsByNameAsc() const;
  void printItemsByNameDesc() const;

  void printItemsByPriceAsc() const;
  void printItemsByPriceDesc() const;
};