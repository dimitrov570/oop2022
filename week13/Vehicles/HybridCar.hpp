#pragma once
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{

public:
  HybridCar(const std::string&, size_t, size_t);
  
  void drive() const override;

  void print() const override;

  void print_direct_members_only() const override;
};