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

//  void inOrder(BSTNode* node) const;

    void inOrder(BSTNode* node, vector<Item>& items) const;


public:
  BST();

  void insert(const Item& val);

  void inOrder() const;

    vector<Item> collectItems() const;

    void printItemsByNameAsc() const;

    void printItemsByNameDesc() const;


    void printItemsByPriceAsc() const;

    void printItemsByPriceDesc() const;
};
