#include "BST.h"

BSTNode::BSTNode(Item val) : data(val), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

void BST::insert(const Item& val) { insert(root, val); }

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

void BST::inOrder(BSTNode* node) const {
  if (node) {
    inOrder(node->left);
    node->data.print();
    inOrder(node->right);
  }
}
