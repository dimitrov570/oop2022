#include "Fruit.hpp"

Fruit::Fruit(const char* name, size_t calories, uint8_t price, const std::string& color) 
            : StoreItem(name, calories, price), color(color) {
}

StoreItem* Fruit::clone() const {
  return new Fruit(*this);
}

std::string Fruit::getColor() const {
  return color;
}

void Fruit::setColor(const std::string& new_color) {
  color = new_color;
}

void Fruit::print() const {
  StoreItem::print();
  std::cout << ", color: " << color;
}

void Fruit::println() const {
  Fruit::print();
  std::cout << "\n";
}