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

  AVLNode* remove(AVLNode* node, const std::string& itemName);
  AVLNode* minValueNode(AVLNode* node);
  void inOrder(AVLNode* node) const;

 public:
  AVL() : root(nullptr) {}

  void insert(const Item& val) { root = insert(root, val); }
  void remove(const std::string& itemName) {
        root = remove(root, itemName);
    }

  void inOrder() const { inOrder(root); }
};