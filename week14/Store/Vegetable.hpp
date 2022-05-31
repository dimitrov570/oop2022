#pragma once
#include "StoreItem.hpp"


class Vegetable : public StoreItem
{
private:
  std::string sort;

public:
  Vegetable(const char*, size_t, uint8_t, const std::string&);

  StoreItem* clone() const;

  std::string getSort() const;
  virtual void print() const override;
  virtual void println() const override;

  void setSort(const std::string& new_sort);
  
};
