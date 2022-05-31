#include "StoreItem.hpp"


StoreItem::StoreItem(const char* name, size_t calories, uint8_t price) : name(name), calories(calories), price(price) {
}

std::string StoreItem::getName() const {
  return name;
}

size_t StoreItem::getCalories() const {
  return calories;
}

uint8_t StoreItem::getPrice() const {
  return price;
}

void StoreItem::setName(const std::string& new_name) {
  name = new_name;
}

void StoreItem::setCalories(size_t new_calories) {
  calories = new_calories;
}

void StoreItem::setPrice(uint8_t new_price) {
  price = new_price;
}

void StoreItem::print() const {
  std::cout << "Name: " << name << ", calories: " << calories << ", price: " << price;
}

void StoreItem::println() const {
  print();
  std::cout << '\n';  
}

StoreItem::~StoreItem() {
  
}