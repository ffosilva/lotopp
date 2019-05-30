#include <iostream>
#include <cassert>

#include "lotopp/Utils.hpp"

int main(const int argc, const char **argv)
{
  unsigned int dezenas[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  assert(lotopp::ordx(dezenas, 15) == 0);

  lotopp::xord(3268759, dezenas, 15);

  for (int i = 0; i < 15; i++)
  {
    assert(dezenas[i] == (11 + i));
  }

  std::cout << "Done! All tests passed..." << std::endl;

  return 0;
}
