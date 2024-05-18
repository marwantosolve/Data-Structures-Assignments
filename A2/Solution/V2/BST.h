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
  void remove(BSTNode*& node, const string& itemName);
  void deleteFromTree(BSTNode*& node);
  void getPredecessor(BSTNode* node, Item& data);

  void inOrder(BSTNode* node) const;

 public:
  BST();

  void insert(const Item& val);
  void remove(const std::string& itemName);

  void inOrder() const;
};
