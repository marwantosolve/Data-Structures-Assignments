#include "BST.h"

BSTNode::BSTNode(Item val) : data(val), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

void BST::insert(const Item& val) { insert(root, val); }
void BST::remove(const std::string& itemName) { remove(root, itemName); }

void BST::inOrder() const { inOrder(root); }

void BST::insert(BSTNode*& node, const Item& val) {
  if (!node) {
    node = new BSTNode(val);
  } else if (val < node->data) {
    insert(node->left, val);
  } else {
    insert(node->right, val);
  }
}

void BST::remove(BSTNode*& node, const std::string& itemName) {
  if (node == nullptr) {
    std::cout << "Item not found!" << std::endl;
    return;
  }
  if (itemName < node->data.itemname) {
    remove(node->left, itemName);
  } else if (itemName > node->data.itemname) {
    remove(node->right, itemName);
  } else {
    deleteFromTree(node);
  }
}

void BST::deleteFromTree(BSTNode*& node) {
  BSTNode* current;
  BSTNode* trailCurrent;
  BSTNode* temp;

  if (node->left == nullptr && node->right == nullptr) {
    // Case 1: No children
    delete node;
    node = nullptr;
  } else if (node->left == nullptr) {
    // Case 2: Only right child
    temp = node;
    node = node->right;
    delete temp;
  } else if (node->right == nullptr) {
    temp = node;
    node = node->left;
    delete temp;
  } else {
    Item data;
    getPredecessor(node->left, data);
    node->data = data;
    remove(node->left, data.itemname);
  }
}

void BST::getPredecessor(BSTNode* node, Item& data) {
  while (node->right != nullptr) {
    node = node->right;
  }
  data = node->data;
}

void BST::inOrder(BSTNode* node) const {
  if (node) {
    inOrder(node->left);
    node->data.print();
    inOrder(node->right);
  }
}
