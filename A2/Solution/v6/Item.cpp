#include "Item.h"

Item::Item(std::string name, std::string cat, int p)
    : itemname(name), category(cat), price(p) {}
 Item::Item() : itemname(""), category(""), price(0) {}

bool Item::operator<(const Item& other) const { return price < other.price; }

bool Item::operator>(const Item& other) const { return price > other.price; }

void Item::print() const {
  std::cout << "Item: " << itemname << ", Category: " << category
            << ", Price: " << price << '\n';
}
