#include "Vegetable.hpp"

Vegetable::Vegetable(const char* name, size_t calories, uint8_t price, const std::string& sort) 
            : StoreItem(name, calories, price), sort(sort) {
}

StoreItem* Vegetable::clone() const {
  return new Vegetable(*this);
}

std::string Vegetable::getSort() const {
  return sort;
}

void Vegetable::setSort(const std::string& new_sort) {
  sort = new_sort;
}

void Vegetable::print() const {
  StoreItem::print();
  std::cout << ", sort: " << sort;
}

void Vegetable::println() const {
  Vegetable::print();
  std::cout << "\n";
}