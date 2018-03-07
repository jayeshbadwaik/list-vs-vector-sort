#ifndef LARGEOBJECT_HH
#define LARGEOBJECT_HH

#include <array>
#include <random>

template <std::size_t N>
struct A {
  std::array<double, N> data{0};
  std::size_t index;
};


#endif // LARGEOBJECT_HH
