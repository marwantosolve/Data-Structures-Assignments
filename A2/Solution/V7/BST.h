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
    BSTNode* remove(BSTNode*& node, const string& itemName);
    BSTNode* findMin(BSTNode* node) const;
    void inOrder(BSTNode* node, vector<Item>& items) const;

public:
    BST();

    void insert(const Item& val);
    void remove(const string& itemName);
    void inOrder() const;
    vector<Item> collectItems() const;
    void printItemsByNameAsc() const;
    void printItemsByNameDesc() const;
    void printItemsByPriceAsc() const;
    void printItemsByPriceDesc() const;
};