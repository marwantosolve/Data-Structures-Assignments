#include "Item.h"

class AVLNode {
 public:
  Item data;
  AVLNode* left;
  AVLNode* right;
  int height;

  AVLNode(Item val);
};

class AVL {
 private:
  AVLNode* root;

  int height(AVLNode* node) { return node ? node->height : 0; }

  int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
  }

  AVLNode* rightRotate(AVLNode* y);

  AVLNode* leftRotate(AVLNode* x);

  AVLNode* insert(AVLNode* node, const Item& val);

  void inOrder(AVLNode* node, std::vector<Item>& items) const;



public:
  AVL() : root(nullptr) {}

  void insert(const Item& val) { root = insert(root, val); }

//  void inOrder() const { inOrder(root); }
    void inOrder() const;

  vector<Item> collectItems() const;

  void printItemsByNameAsc() const;

  void printItemsByNameDesc() const;


    void printItemsByPriceAsc() const;

    void printItemsByPriceDesc() const;
};