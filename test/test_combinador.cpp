#undef NDEBUG

#include <iostream>
#include <cassert>

#include "lotopp/types.hpp"
#include "lotopp/combinador.hpp"

#define TAMANHO_CART 15
#define QTDE_DEZENAS 25

int main(const int argc, const char **argv)
{
  dezena_t dezenas[TAMANHO_CART];

  lotopp::combinador c(QTDE_DEZENAS, TAMANHO_CART);

  c.next(dezenas);
  int counter = 1;

  for (int i = 0; i < TAMANHO_CART; i++)
  {
    assert(dezenas[i] == (i + 1));
  }

  while (c.next(dezenas) == 0)
  {
    counter++;
  }

  for (int i = 0; i < TAMANHO_CART; i++)
  {
    assert(dezenas[i] == (i + (QTDE_DEZENAS - TAMANHO_CART + 1)));
  }

  assert(counter == c.num_combinacoes());

  std::cerr << "Done! All tests passed..." << std::endl;

  return 0;
}
