#include <iostream>
#include <vector>

#include "lotopp/cartao.hpp"
#include "lotopp/combinador.hpp"

#define ARG_QTDE_NUMEROS 20
#define ARG_TAMANHO_CARTAO 6
#define ARG_GARANTE 5

dezena_t buffer_cartao[ARG_TAMANHO_CARTAO];
dezena_t buffer_garante[ARG_TAMANHO_CARTAO];

std::vector<size_t> escolhidos;

lotopp::cartao c_cartao, c_garante;

int main(int argc, char **argv)
{
  if (ARG_GARANTE > ARG_TAMANHO_CARTAO)
  {
    std::cerr << "GARANTE não pode ser maior que ACERTANDO" << std::endl;
    return 1;
  }

  lotopp::combinador comb_combinacoes_cartoes(ARG_QTDE_NUMEROS, ARG_TAMANHO_CARTAO);

  std::cout << "Gerando grafo de combinações...";
  std::cout.flush();

  size_t acertos;
  bool encontrado;

  escolhidos.push_back(0);

  for (size_t i = 0; i < comb_combinacoes_cartoes.num_combinacoes(); i++)
  {
    encontrado = false;
    comb_combinacoes_cartoes.get(buffer_cartao, i);
    c_cartao = lotopp::cartao(buffer_cartao, ARG_TAMANHO_CARTAO);

    for (auto const &escolhido : escolhidos)
    {
      comb_combinacoes_cartoes.get(buffer_garante, escolhido);
      c_garante = lotopp::cartao(buffer_garante, ARG_TAMANHO_CARTAO);

      if ((acertos = c_cartao.acertos(&c_garante)) >= ARG_GARANTE)
      {
        encontrado = true;
        break;
      }
    }

    if (encontrado)
      continue;

    escolhidos.push_back(i);
  }

  std::cout << " Pronto!" << std::endl;
  std::cout << " Foram escolhidos " << escolhidos.size() << " cartões." << std::endl;;
}