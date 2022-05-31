#include "Fruit.hpp"
#include "Vegetable.hpp"
#include "Store.hpp"
#include <iostream>


int main() {


  Fruit fruit("fruit", 3 ,3 , "red");
  Vegetable vegetable("vegateble", 5, 5, "sort1");

  Store store;

  store.addProduct(&fruit);
  store.addProduct(&vegetable);

  store.printAllProducts();

  return 0;
}