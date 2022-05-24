#pragma once
#include "Printable.hpp"
#include "Driveable.hpp"

#include <string>

class Vehicle : public Printable, public Driveable
{
private:
  std::string model;
  
public:
  Vehicle(const std::string&);
  
  virtual ~Vehicle() {};

  virtual void print() const override;

  virtual void print_direct_members_only() const override;

  virtual void drive() const = 0;

  std::string getModel() const;
};
