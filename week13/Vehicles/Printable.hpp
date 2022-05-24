#pragma once

class Printable
{
public:

  virtual void print() const = 0;
  virtual void print_direct_members_only() const = 0;
};
