/**
 * Lottery C++ Library
 * Filename: combinador.cpp
 * 
 * This file contains combinador implementation
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#include <mutex>

#include "lotopp/types.hpp"
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

int combinador::get(dezena_t *buff, size_t idx)
{
  return lotopp::xord(idx, buff, _tamanho_cartao);
}

int combinador::next(dezena_t *next)
{
  _mtx_posicao_atual.lock();
  int pos = _posicao_atual++;
  _mtx_posicao_atual.unlock();

  if (pos >= _num_combinacoes)
    return -1;

  get(next, pos);

  return 0;
}
} // namespace lotopp