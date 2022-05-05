#pragma once
#include <ostream>

template<typename T, typename K>
class Pair;

template<typename T, typename K>
std::ostream& operator<<(std::ostream& o, Pair<T, K>& obj);

template <typename T = int, typename K = int>
class Pair
{
private:
  T first;
  K second;

public:

  Pair(T fst, K snd) : first(fst), second(snd) {}


  T getFirst() const {
    return first;
  }

  K getSecond() const {
    return second;
  }

  friend std::ostream& operator<< <> (std::ostream& o, Pair& obj);

  void setFirst(T fst);
  void setSecond(K snd);

};


template <typename T, typename K>
void Pair<T, K>::setFirst(T fst) {
  first = fst;
}

template <typename T, typename K>
void Pair<T, K>::setSecond(K snd) {
  second = snd;
}


template <typename T, typename K>
std::ostream& operator<<(std::ostream& o, Pair<T, K>& obj) {
  return o << obj.first << " : " << obj.second;
}
