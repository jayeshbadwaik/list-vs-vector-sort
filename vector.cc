#include "largeobject.hh"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <vector>

int main()
{
  using AType = A<SIZE>;
  std::size_t nelem = NELEM;

  std::random_device rd;
  std::mt19937_64 prng(rd());
  std::uniform_int_distribution<std::size_t> indexgen(
    0, std::numeric_limits<std::size_t>::max());

  // Generate a big list of random objects of Type AType
  std::vector<AType> random_vector;
  for (std::size_t elem = 0; elem < nelem; ++elem) {
    AType a{};
    a.index = indexgen(prng);
    random_vector.push_back(a);
  }

  auto const start = std::chrono::high_resolution_clock::now();
  std::sort(random_vector.begin(),
            random_vector.end(),
            [](auto const& a, auto const& b) { return a.index < b.index; });

  auto const stop = std::chrono::high_resolution_clock::now();

  auto const elapsed = stop - start;

  std::cout
    << "Time Elapsed = "
    << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
    << std::endl;

  std::cout << "First Element = " << random_vector[0].index << std::endl;

  return EXIT_SUCCESS;
}
