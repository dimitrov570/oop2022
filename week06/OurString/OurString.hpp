#pragma once
#include <stdio.h>
#include <ostream>

class OurString
{
private:
  char* data_array;
  size_t length;

public:
  OurString(const char* str);

  OurString(const OurString&);

  OurString& operator=(const OurString&);

  char at(size_t pos) const;

  char front() const;
  char back() const;
  const char* data() const;
  bool empty() const;
  size_t size() const;
  void clear();

  void print(std::ostream&) const;

  void setString(const char*);

  ~OurString();

private:

  void allocate(const char*);

};
