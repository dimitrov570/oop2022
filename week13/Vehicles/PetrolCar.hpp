#pragma once
#include "Vehicle.hpp"

class PetrolCar : virtual public Vehicle
{
private:
  size_t horsepower;
  
public:
  
  PetrolCar(const std::string&, size_t);
  
  void drive() const override;

  void print() const override;

  void print_direct_members_only() const override;

};