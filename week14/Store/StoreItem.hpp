#pragma once
#include "Printable.hpp"
#include <iostream>
#include <string>


class StoreItem : public Printable
{
private:

  std::string name;
  size_t calories;
  uint16_t price;

public:
  StoreItem(const char*, size_t, uint8_t);

  virtual StoreItem* clone() const = 0;

  std::string getName() const;
  size_t getCalories() const;
  uint8_t getPrice() const;
  virtual void print() const override;
  virtual void println() const override;
  
  void setName(const std::string& new_name);
  void setCalories(size_t new_calories);
  void setPrice(uint8_t new_price);

  virtual ~StoreItem() = 0;

};