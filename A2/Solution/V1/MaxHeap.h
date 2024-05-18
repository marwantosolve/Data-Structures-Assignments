#include "Item.h"

class MaxHeap {
 private:
  std::vector<Item> heap;

  void heapifyUp(int index);
  void heapifyDown(int index);

 public:
  void insert(const Item& val);
  Item extractMax();
  void print() const;
};