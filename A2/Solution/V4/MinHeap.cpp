
#include "MinHeap.h"

void MinHeap::heapifyUp(int index) {
  while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
    std::swap(heap[(index - 1) / 2], heap[index]);
    index = (index - 1) / 2;
  }
}

void MinHeap::heapifyDown(int index) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int smallest = index;

  if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
  if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;
  if (smallest != index) {
    std::swap(heap[index], heap[smallest]);
    heapifyDown(smallest);
  }
}

void MinHeap::insert(const Item& val) {
  heap.push_back(val);
  heapifyUp(heap.size() - 1);
}

Item MinHeap::extractMin() {
  if (heap.empty()) throw std::runtime_error("Heap is empty");
  Item minItem = heap.front();
  heap[0] = heap.back();
  heap.pop_back();
  heapifyDown(0);
  return minItem;
}

void MinHeap::print() const {
  for (const auto& it : heap) {
    it.print();
  }
}
void MinHeap::printItemsByNameAsc() const {
    vector<Item> items = heap; // Copy the heap
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname < b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}

void MinHeap::printItemsByNameDesc() const {
    vector<Item> items = heap; // Copy the heap
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname > b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}