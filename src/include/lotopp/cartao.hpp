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

#include "lotopp/types.hpp"

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

  std::set<dezena_t> _numeros;

public:
  cartao(dezena_t *dezenas = NULL, size_t dezenas_len = 0);

  bool adicionar(dezena_t dezena);
  size_t acertos(cartao *other);
  size_t quantidade_dezenas();
  bool contains(dezena_t dezena);

  typedef typename std::set<dezena_t>::iterator iterator;
  typedef typename std::set<dezena_t>::reverse_iterator reverse_iterator;

  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();

  dezena_t operator[](int index);
  cartao &operator<<(dezena_t const dezena);
};
} // namespace lotopp

#endif