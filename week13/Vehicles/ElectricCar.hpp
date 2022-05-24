#pragma once

#include "Vehicle.hpp"

class ElectricCar : virtual public Vehicle
{
  size_t battery_power;
  
public:
  ElectricCar(const std::string&, size_t);
  
  void drive() const override;

  void print() const override;

  void print_direct_members_only() const override;
};
