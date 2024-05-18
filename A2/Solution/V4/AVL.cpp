#include "AVL.h"

AVLNode::AVLNode(Item val)
    : data(val), left(nullptr), right(nullptr), height(1) {}

AVLNode* AVL::rightRotate(AVLNode* y) {
  AVLNode* x = y->left;
  AVLNode* T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

AVLNode* AVL::leftRotate(AVLNode* x) {
  AVLNode* y = x->right;
  AVLNode* T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}

AVLNode* AVL::insert(AVLNode* node, const Item& val) {
  if (!node) return new AVLNode(val);
  if (val < node->data)
    node->left = insert(node->left, val);
  else
    node->right = insert(node->right, val);

  node->height = 1 + max(height(node->left), height(node->right));

  int balance = getBalance(node);

  if (balance > 1 && val < node->left->data) return rightRotate(node);
  if (balance < -1 && val > node->right->data) return leftRotate(node);
  if (balance > 1 && val > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && val < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

//void AVL::inOrder(AVLNode* node) const {
//  if (node) {
//    inOrder(node->left);
//    node->data.print();
//    inOrder(node->right);
//  }
//}
void AVL::inOrder(AVLNode* node, std::vector<Item>& items) const {
    if (node) {
        inOrder(node->left, items);
        items.push_back(node->data);
        inOrder(node->right, items);
    }
}
void AVL::inOrder() const {
    vector<Item> items;
    inOrder(root, items);  // Call the private inOrder method
    for (const auto& item : items) {
        item.print();
    }
}
vector<Item> AVL::collectItems() const {
    vector<Item> items;
    inOrder(root, items);
    return items;
}

void AVL::printItemsByNameAsc() const {
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname < b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}

void AVL::printItemsByNameDesc() const {
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname > b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}