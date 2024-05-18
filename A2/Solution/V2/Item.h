#pragma once
#include <bits/stdc++.h>
using namespace std;

class Item {
 public:
  std::string itemname;
  std::string category;
  int price;

  Item(std::string name, std::string cat, int p);
  Item();
  bool operator<(const Item& other) const;
  bool operator>(const Item& other) const;

  void print() const;
};