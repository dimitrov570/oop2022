#include "Store.hpp"

StoreItem* Store::cloneProduct(const StoreItem* product) {
    StoreItem* to_return;
    
    /* VARIANT WITH STATIC_CAST
    if(typeid(*product) == typeid(Fruit)) {
      const Fruit* ptr = static_cast<const Fruit*>(product);
      to_return = new Fruit(*ptr);
    } else if(typeid(*product) == typeid(Vegetable)) {
      const Vegetable* ptr = static_cast<const Vegetable*>(product);
      to_return = new Vegetable(*ptr);
    }
    */

    /* VARIANT WITH DYNAMIC_CAST
    const Fruit* fruit_ptr = dynamic_cast<const Fruit*>(product);
    if(fruit_ptr != nullptr) {
      to_return = new Fruit(*fruit_ptr);
    }
    
    const Vegetable* vegetable_ptr = dynamic_cast<const Vegetable*>(product);
    if(vegetable_ptr != nullptr) {
      to_return = new Vegetable(*vegetable_ptr);
    }
    */

    to_return = product->clone();

    return to_return;
  }

void Store::printAllProducts() const {
  for(StoreItem* ptr : products) {
    ptr->println();
  }
}

void Store::addProduct(const StoreItem* product) {
  products.push_back(cloneProduct(product));
}

Store::~Store() {
  for(StoreItem* ptr : products) {
    delete ptr;
  }
}