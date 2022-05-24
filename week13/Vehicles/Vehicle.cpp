#include "Vehicle.hpp"
#include <iostream>

Vehicle::Vehicle(const std::string& _model) : model(_model) {
}
  
void Vehicle::print() const {
  print_direct_members_only();
}

void Vehicle::print_direct_members_only() const {
  std::cout << "Model: " << model;
}

std::string Vehicle::getModel() const {
  return model;
}