#pragma once
#include "StoreItem.hpp"
#include <vector>


class Store
{
private:
  std::vector<StoreItem*> products;

  StoreItem* cloneProduct(const StoreItem* product);

public:
  
  void printAllProducts() const;

  void addProduct(const StoreItem* product);

  ~Store();
};