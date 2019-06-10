#include <iostream>
#include <vector>

#include "lotopp/cartao.hpp"
#include "lotopp/combinador.hpp"

#include "boost/graph/adjacency_list.hpp"

#define ARG_QTDE_NUMEROS 20
#define ARG_TAMANHO_CARTAO 15
#define ARG_ACERTANDO 14
#define ARG_GARANTE 14

std::vector<lotopp::cartao> combinacoes_cartoes;
std::vector<lotopp::cartao> combinacoes_garante;

dezena_t buffer_cartao[ARG_TAMANHO_CARTAO];

int main(int argc, char **argv)
{
  lotopp::combinador comb_combinacoes_cartoes(ARG_QTDE_NUMEROS, ARG_TAMANHO_CARTAO);
  lotopp::combinador comb_combinacoes_garante(ARG_QTDE_NUMEROS, ARG_ACERTANDO);

  std::cout << "Gerando combinações de cartões... ";
  std::cout.flush();

  while (comb_combinacoes_cartoes.next(buffer_cartao) == 0)
  {
    combinacoes_cartoes.push_back(*new lotopp::cartao(buffer_cartao, ARG_TAMANHO_CARTAO));
  }

  std::cout << "Pronto!" << std::endl
            << "Foram geradas " << combinacoes_cartoes.size() << " combinações." << std::endl;

  std::cout << "Gerando combinações de garante... ";
  std::cout.flush();

  while (comb_combinacoes_garante.next(buffer_cartao) == 0)
  {
    combinacoes_garante.push_back(*new lotopp::cartao(buffer_cartao, ARG_ACERTANDO));
  }

  std::cout << "Pronto!" << std::endl
            << "Foram geradas " << combinacoes_garante.size() << " combinações." << std::endl;

  boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> grafo_acertos(combinacoes_cartoes.size() + combinacoes_garante.size());

  size_t acertos, qtde_cartoes = combinacoes_cartoes.size();
  
  for (size_t i = 0; i < combinacoes_cartoes.size(); i++)
  {
    for (size_t j = 0; j < combinacoes_garante.size(); j++)
    {
      if ((acertos = combinacoes_cartoes[i].acertos(&combinacoes_garante[j])) >= ARG_GARANTE)
      {
        boost::add_edge(i, i + qtde_cartoes, grafo_acertos);
      }
      //if combinacoes_cartoes[i].value.conferir(combinacoes_garante[j].value) >= garante : combinacoes_cartoes[i].connect(combinacoes_garante[j])
    }
  }
}