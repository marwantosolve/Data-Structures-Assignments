#include "BST.h"

BSTNode::BSTNode(Item val) : data(val), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

void BST::insert(const Item &val) { insert(root, val); }

// void BST::inOrder() const { inOrder(root); }
void BST::inOrder() const
{
    vector<Item> items;
    inOrder(root, items);
    for (const auto &item : items)
    {
        item.print();
    }
}

void BST::insert(BSTNode *&node, const Item &val)
{
    if (!node)
    {
        node = new BSTNode(val);
    }
    else if (val < node->data)
    {
        insert(node->left, val);
    }
    else
    {
        insert(node->right, val);
    }
}
void BST::remove(const string &itemName)
{
    root = remove(root, itemName);
}

BSTNode *BST::remove(BSTNode *&node, const string &itemName)
{
    if (!node)
        return nullptr;
    if (itemName < node->data.itemname)
    {
        node->left = remove(node->left, itemName);
    }
    else if (itemName > node->data.itemname)
    {
        node->right = remove(node->right, itemName);
    }
    else
    {
        if (!node->left)
        {
            BSTNode *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            BSTNode *temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            BSTNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data.itemname);
        }
    }
    return node;
}

BSTNode *BST::findMin(BSTNode *node) const
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

// void BST::inOrder(BSTNode* node) const {
//   if (node) {
//     inOrder(node->left);
//     node->data.print();
//     inOrder(node->right);
//   }
// }

void BST::inOrder(BSTNode *node, vector<Item> &items) const
{
    if (node)
    {
        inOrder(node->left, items);
        items.push_back(node->data);
        inOrder(node->right, items);
    }
}

vector<Item> BST::collectItems() const
{
    vector<Item> items;
    inOrder(root, items);
    return items;
}

void BST::printItemsByNameAsc() const
{
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
         { return a.itemname < b.itemname; });
    for (const auto &item : items)
    {
        item.print();
    }
}

void BST::printItemsByNameDesc() const
{
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
         { return a.itemname > b.itemname; });
    for (const auto &item : items)
    {
        item.print();
    }
}

void BST::printItemsByPriceAsc() const
{
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
         { return a.price < b.price; });
    for (const auto &item : items)
    {
        item.print();
    }
}

void BST::printItemsByPriceDesc() const
{
    vector<Item> items = collectItems();
    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
         { return a.price > b.price; });
    for (const auto &item : items)
    {
        item.print();
    }
}