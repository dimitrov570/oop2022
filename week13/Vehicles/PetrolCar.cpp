#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(const std::string& model, size_t hp) : Vehicle(model), horsepower(hp) {

}
  
void PetrolCar::drive() const {
  std::cout << "Driving petrol car\n";
}

void PetrolCar::print() const {
  Vehicle::print();
  print_direct_members_only();
}

void PetrolCar::print_direct_members_only() const {
  std::cout << "Horsepower: " << horsepower;
}