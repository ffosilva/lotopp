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
cartao::cartao(unsigned int *dezenas, size_t dezenas_len)
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

bool cartao::adicionar(unsigned int dezena)
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

bool cartao::contains(unsigned int val) {
  return _numeros.find(val) != _numeros.end();
}

std::set<unsigned int>::iterator cartao::begin()
{
  return _numeros.begin();
}

std::set<unsigned int>::iterator cartao::end()
{
  return _numeros.end();
}

std::set<unsigned int>::reverse_iterator cartao::rbegin()
{
  return _numeros.rbegin();
}

std::set<unsigned int>::reverse_iterator cartao::rend()
{
  return _numeros.rend();
}

unsigned int cartao::operator[](int index) {
  std::set<unsigned int>::iterator it = this->begin();
  std::advance(it, index);

  return *it;
}

cartao &cartao::operator<<(unsigned int const dezena)
{
  this->adicionar(dezena);

  return *this;
}
} // namespace lotopp