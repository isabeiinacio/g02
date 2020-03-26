#ifndef LAIRASTOS_INTERFACE_H
#define LAIRASTOS_INTERFACE_H

#include "dados.h"

/**
 * \brief Função que implementa o tabuleiro
 * @param file Ficheiro com os tabuleiros
 * @param e Apontador para o estado da função
 */
void mostrar_tabuleiro(FILE* file, ESTADO *e);

/**
 * \brief Função que deteta os imputs do usuário
 * @param e Apontador para o estado da função
 * @return
 */
int interpretador(ESTADO *e);

/**
 * \brief Função que permite ao utilizador saber o estado do jogo
 * @param e Apontador para o estado da função
 * @param n_comandos Controla o número de comandos
 */
void prompt(ESTADO *e, int n_comandos);

/**
 * \brief Funçao que guarda o tabuleiro num ficheiro
 * @param e Apontador para o estado da função
 */
void guardar_tabuleiro(ESTADO *e);

#endif