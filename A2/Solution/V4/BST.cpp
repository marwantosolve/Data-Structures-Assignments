#include "BST.h"

BSTNode::BSTNode(Item val) : data(val), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

void BST::insert(const Item& val) { insert(root, val); }

//void BST::inOrder() const { inOrder(root); }
void BST::inOrder() const {
    vector<Item> items;
    inOrder(root, items);
    for (const auto& item : items) {
        item.print();
    }
}

void BST::insert(BSTNode*& node, const Item& val) {
  if (!node) {
    node = new BSTNode(val);
  } else if (val < node->data) {
    insert(node->left, val);
  } else {
    insert(node->right, val);
  }
}

//void BST::inOrder(BSTNode* node) const {
//  if (node) {
//    inOrder(node->left);
//    node->data.print();
//    inOrder(node->right);
//  }
//}


void BST::inOrder(BSTNode* node, std::vector<Item>& items) const {
    if (node) {
        inOrder(node->left, items);
        items.push_back(node->data);
        inOrder(node->right, items);
    }
}

vector<Item> BST::collectItems() const {
    vector<Item> items;
    inOrder(root, items);
    return items;
}

void BST::printItemsByNameAsc() const {
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname < b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}

void BST::printItemsByNameDesc() const {
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.itemname > b.itemname;
    });
    for (const auto& item : items) {
        item.print();
    }
}
