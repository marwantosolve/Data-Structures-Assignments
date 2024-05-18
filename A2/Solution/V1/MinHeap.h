#include "Item.h"
class MinHeap {
 private:
  std::vector<Item> heap;

  void heapifyUp(int index);
  void heapifyDown(int index);

 public:
  void insert(const Item& val);
  Item extractMin();
  void print() const;
};