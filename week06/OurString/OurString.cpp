#include "OurString.hpp"
#include <cstring>
#include <iostream>

void OurString::allocate(const char* str) {
  data_array = new char[strlen(str) + 1];
  strcpy(data_array, str);
  length = strlen(data_array);
}

OurString::OurString(const char* str)
{
  allocate(str);
}

OurString::OurString(const OurString& rhs) {
  allocate(rhs.data_array);
}

OurString& OurString::operator=(const OurString& rhs) {
  if(this != &rhs) {
    clear();
    allocate(rhs.data_array);
  }
  return *this;
}
  

char OurString::at(size_t pos) const {
  if(pos > length) {
    std::cerr << "Invalid position: " << pos << '\n';
    return 0;
  }

  return data_array[pos];
}

char OurString::front() const {
  if(length > 0) {
    return data_array[0];
  }

  return 0;
}

char OurString::back() const {
  if(length > 0) {
    return data_array[length - 1];
  }

  return 0;
}

const char* OurString::data() const {
  return data_array;
}

bool OurString::empty() const {
  return length == 0;
}

size_t OurString::size() const {
  return length;
}

void OurString::clear() {
  delete[] data_array;
  data_array = nullptr;
  length = 0;
}

void OurString::print(std::ostream& os) const {
  os << data_array;
}

void OurString::setString(const char* str) {
  clear();
  allocate(str);
}

OurString::~OurString()
{
  clear();
}
