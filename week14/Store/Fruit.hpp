#pragma once
#include "StoreItem.hpp"


class Fruit : public StoreItem
{
private:
  std::string color;

public:
  Fruit(const char*, size_t, uint8_t, const std::string&);

  StoreItem* clone() const;
  
  std::string getColor() const;
  virtual void print() const override;
  virtual void println() const override;

  void setColor(const std::string& new_color);
};
