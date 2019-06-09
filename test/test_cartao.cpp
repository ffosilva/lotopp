#include <iostream>
#include <cassert>

#include "lotopp/cartao.hpp"

int main(const int argc, const char **argv)
{
  lotopp::cartao cartao;

  assert(!cartao.contains(3));
  cartao.adicionar(3);
  assert(cartao.contains(3));

  assert(!cartao.contains(2));
  cartao.adicionar(2);
  assert(cartao.contains(2));

  assert(!cartao.contains(1));
  cartao.adicionar(1);
  assert(cartao.contains(1));

  assert(cartao.quantidade_dezenas() == 3);

  cartao << 1 << 2 << 3;
  assert(cartao.quantidade_dezenas() == 3);

  assert(!cartao.contains(4));
  assert(!cartao.contains(5));
  assert(!cartao.contains(6));

  cartao << 4 << 5 << 6;
  assert(cartao.quantidade_dezenas() == 6);

  assert(cartao.contains(4));
  assert(cartao.contains(5));
  assert(cartao.contains(6));

  assert(cartao[0] == 1);
  assert(cartao[1] == 2);
  assert(cartao[2] == 3);
  assert(cartao[3] == 4);
  assert(cartao[4] == 5);
  assert(cartao[5] == 6);

  cartao << 7 << 7 << 7 << 7 << 7 << 7 << 7 << 8;

  assert(cartao.quantidade_dezenas() == 8);

  int counter = 0;
  lotopp::cartao::iterator it = cartao.begin();
  while (it != cartao.end())
  {
    counter++;
    it++;
  }
  assert(counter == 8);

  std::cout << "Done! All tests passed..." << std::endl;

  return 0;
}