/**
 * Lottery C++ Library
 * Filename: cartao.cpp
 * 
 * This file contains cartao implementation
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#include <algorithm>
#include <cstddef>

#include "lotopp/cartao.hpp"

namespace lotopp
{
cartao::cartao(dezena_t *dezenas, size_t dezenas_len)
{
  for (size_t i = 0; i < dezenas_len; i++)
  {
    _numeros.insert(dezenas[i]);
  }
}

template <typename T1, typename T2>
size_t cartao::intersection_size(const T1 &s1, const T2 &s2)
{
  acertos_counter c;
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(c));

  return c.count;
}

bool cartao::adicionar(dezena_t dezena)
{
  return _numeros.insert(dezena).second;
}

size_t cartao::acertos(cartao *other)
{
  return intersection_size(_numeros, other->_numeros);
}

size_t cartao::quantidade_dezenas()
{
  return _numeros.size();
}

bool cartao::contains(dezena_t val) {
  return _numeros.find(val) != _numeros.end();
}

cartao::iterator cartao::begin()
{
  return _numeros.begin();
}

cartao::iterator cartao::end()
{
  return _numeros.end();
}

cartao::reverse_iterator cartao::rbegin()
{
  return _numeros.rbegin();
}

cartao::reverse_iterator cartao::rend()
{
  return _numeros.rend();
}

dezena_t cartao::operator[](int index) {
  cartao::iterator it = this->begin();
  std::advance(it, index);

  return *it;
}

cartao &cartao::operator<<(dezena_t const dezena)
{
  this->adicionar(dezena);

  return *this;
}
} // namespace lotopp