/**
 * Lottery C++ Library
 * Filename: cartao.hpp
 * 
 * This file contains cartao header
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#ifndef LOTOPP_CARTAO_HPP
#define LOTOPP_CARTAO_HPP

#include <cstddef>

#include <set>

namespace lotopp
{
class cartao
{
private:
  struct acertos_counter
  {
    struct value_type
    {
      template <typename T>
      value_type(const T &) {}
    };
    void push_back(const value_type &) { ++count; }
    size_t count = 0;
  };

  template <typename T1, typename T2>
  size_t intersection_size(const T1 &s1, const T2 &s2);

  std::set<unsigned int> _numeros;

public:
  cartao(unsigned int *dezenas = NULL, size_t dezenas_len = 0);

  bool adicionar(unsigned int dezena);
  size_t acertos(cartao *other);
  size_t quantidade_dezenas();
  bool contains(unsigned int dezena);
  std::set<unsigned int>::iterator begin();
  std::set<unsigned int>::iterator end();
  std::set<unsigned int>::reverse_iterator rbegin();
  std::set<unsigned int>::reverse_iterator rend();

  unsigned int operator[](int index);
  cartao &operator<<(unsigned int const dezena);
};
} // namespace lotopp

#endif