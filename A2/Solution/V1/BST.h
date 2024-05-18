#include "Item.h"

class BSTNode {
 public:
  Item data;
  BSTNode* left;
  BSTNode* right;

  BSTNode(Item val);
};

class BST {
 private:
  BSTNode* root;

  void insert(BSTNode*& node, const Item& val);

  void inOrder(BSTNode* node) const;

 public:
  BST();

  void insert(const Item& val);

  void inOrder() const;
};
