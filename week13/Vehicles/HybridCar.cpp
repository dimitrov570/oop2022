#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(const std::string& model, size_t hp, size_t bp) : Vehicle(model), PetrolCar(model, hp), ElectricCar(model, bp) {

}
  
void HybridCar::drive() const {
  std::cout << "Driving hybrid car\n";
}

void HybridCar:: print() const {

  std::cout << "HybridCar:  ";
  Vehicle::print_direct_members_only();
  std::cout << " ";
  PetrolCar::print_direct_members_only();
  std::cout << " ";
  ElectricCar::print_direct_members_only();

}

void HybridCar::print_direct_members_only() const {

}