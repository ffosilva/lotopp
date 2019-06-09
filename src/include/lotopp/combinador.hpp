/**
 * Lottery C++ Library
 * Filename: combinador.hpp
 * 
 * This file contains combinador header
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#ifndef LOTOPP_COMBINADOR_HPP
#define LOTOPP_COMBINADOR_HPP

#include <mutex>

namespace lotopp
{
class combinador
{
private:
    int _quantidade_dezenas;
    int _tamanho_cartao;
    int _posicao_atual;
    int _num_combinacoes;
    std::mutex _mtx_posicao_atual;

public:
    combinador(int quantidade_dezenas, int tamanho_cartao);

    void reset();
    int num_combinacoes();
    int next(unsigned int *next);
};
} // namespace lotopp

#endif // _LOTOPP_COMBINADOR_HPP_