#include "MaxHeap.h"

void MaxHeap::heapifyUp(int index) {
  while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
    std::swap(heap[(index - 1) / 2], heap[index]);
    index = (index - 1) / 2;
  }
}

void MaxHeap::heapifyDown(int index) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int largest = index;

  if (left < heap.size() && heap[largest] < heap[left]) largest = left;
  if (right < heap.size() && heap[largest] < heap[right]) largest = right;
  if (largest != index) {
    std::swap(heap[index], heap[largest]);
    heapifyDown(largest);
  }
}

void MaxHeap::insert(const Item& val) {
  heap.push_back(val);
  heapifyUp(heap.size() - 1);
}

Item MaxHeap::extractMax() {
  if (heap.empty()) throw std::runtime_error("Heap is empty");
  Item maxItem = heap.front();
  heap[0] = heap.back();
  heap.pop_back();
  heapifyDown(0);
  return maxItem;
}

void MaxHeap::print() const {
  for (const auto& it : heap) {
    it.print();
  }
}
void MaxHeap::printItemsByNameAsc() const {
    vector<Item> items = heap;
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname < b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}

void MaxHeap::printItemsByNameDesc() const {
    vector<Item> items = heap;
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname > b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}
// MaxHeap.cpp
