#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(const std::string& model, size_t bp) : Vehicle(model), battery_power(bp) {

}
  
void ElectricCar::drive() const {
  std::cout << "Driving electric car\n";
}

void ElectricCar::print() const {
  Vehicle::print();
  print_direct_members_only();
}

void ElectricCar::print_direct_members_only() const {
  std::cout << "Horsepower: " << battery_power;
}