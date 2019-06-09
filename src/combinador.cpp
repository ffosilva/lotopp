/**
 * Lottery C++ Library
 * Filename: combinador.cpp
 * 
 * This file contains combinador implementation
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#include <mutex>

#include "lotopp/utils.hpp"
#include "lotopp/combinador.hpp"

namespace lotopp
{
combinador::combinador(int quantidade_dezenas, int tamanho_cartao)
    : _quantidade_dezenas(quantidade_dezenas),
      _tamanho_cartao(tamanho_cartao),
      _posicao_atual(0),
      _num_combinacoes(lotopp::comb(quantidade_dezenas, tamanho_cartao))
{
}

int combinador::num_combinacoes()
{
  return _num_combinacoes;
}

void combinador::reset()
{
  _mtx_posicao_atual.lock();
  _posicao_atual = 0;
  _mtx_posicao_atual.unlock();
}

int combinador::next(unsigned int *next)
{
  _mtx_posicao_atual.lock();
  int pos = _posicao_atual++;
  _mtx_posicao_atual.unlock();

  if (pos >= _num_combinacoes)
    return -1;

  lotopp::xord(pos, next, _tamanho_cartao);

  return 0;
}
} // namespace lotopp