#include <iostream>
#include <cassert>

#include "lotopp/cartao.hpp"
#include "lotopp/combinador.hpp"

#define TAMANHO_CART 15
#define QTDE_DEZENAS 25

int main(const int argc, const char **argv)
{
  unsigned int dezenas[TAMANHO_CART];

  lotopp::combinador c(QTDE_DEZENAS, TAMANHO_CART);

  c.next(dezenas);

  lotopp::cartao inicial(dezenas, TAMANHO_CART);

  int counter = 1;

  for (int i = 0; i < TAMANHO_CART; i++)
  {
    assert(inicial[i] == (i + 1));
  }

  while (c.next(dezenas) == 0)
  {
    lotopp::cartao c(dezenas, TAMANHO_CART);

    for (int i = 0; i < TAMANHO_CART; i++)
    {
      assert(dezenas[i] == c[i]);
    }
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
