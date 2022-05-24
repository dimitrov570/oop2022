#include <iostream>
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

int main() {

 // Vehicle vehicle("vw"); abstract

  Vehicle *first_vehicle = new PetrolCar("vw", 90);

  Vehicle *second_vehicle = new ElectricCar("tesla", 120);

  first_vehicle->print();
  std::cout << '\n';  

  second_vehicle->print();
  std::cout << '\n';

  PetrolCar petrol_car("bmw", 116);

  std::cout << petrol_car.getModel();

  HybridCar hybric_car("vw_hybrid", 116, 120);

  std::cout << "\n";
  hybric_car.print();

  delete first_vehicle; // Деструктора трябва да е виртуален, за да се извика правилно тук
  delete second_vehicle;

  return 0;
}