
#include "Heap.h"

Heap::Heap() {}

Heap::~Heap() {}

void Heap::insert(const Item& newItem) {
  heap.push_back(newItem);
  heapifyUp(heap.size() - 1);
}

void Heap::remove(const std::string& itemName) {
  int index = findIndex(itemName);
  if (index == -1) {
    std::cout << "Item not found!" << std::endl;
    return;
  }
  heap[index] = heap.back();
  heap.pop_back();
  heapifyDown(index);
}

void Heap::display() const {
  for (const auto& it : heap) {
    it.print();
  }
}

void Heap::heapifyUp(int index) {
  while (index != 0 && heap[(index - 1) / 2] < heap[index]) {
    std::swap(heap[index], heap[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void Heap::heapifyDown(int index) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heap.size() && heap[left] < heap[largest]) largest = left;

  if (right < heap.size() && heap[right] < heap[largest]) largest = right;

  if (largest != index) {
    std::swap(heap[index], heap[largest]);
    heapifyDown(largest);
  }
}

int Heap::findIndex(const std::string& itemName) const {
  for (int i = 0; i < heap.size(); ++i) {
    if (heap[i].itemname == itemName) return i;
  }
  return -1;
}
