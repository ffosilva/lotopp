#include <iostream>
#include <cassert>

#include "lotopp/utils.hpp"

int main(const int argc, const char **argv)
{
  // Execute the function with known values
  assert(lotopp::comb(1, 2) == 0);
  assert(lotopp::comb(5, 3) == 10);
  assert(lotopp::comb(100, 2) == 4950);
  assert(lotopp::comb(33, 17) == 1166803110);
  assert(lotopp::comb(25, 15) == 3268760);

  std::cout << "Done! All tests passed..." << std::endl;

  return 0;
}
