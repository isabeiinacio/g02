
#ifndef LAIRASTOS_LOGICA_H
#define LAIRASTOS_LOGICA_H

/**
 * \brief Função que implementa a jogada
 * @param estado Apontador para o estado da função
 * @param c Coordenada onde vai ser jogada
 * @return
 */
int jogar(ESTADO *estado, COORDENADA c);

/**
 * \brief Função que verifica se a jogada é valida
 * @param e Apontador para o estado da função
 * @param c Coordenada da casa a verificar
 * @return
 */
int validar_jogada(ESTADO *e, COORDENADA c);

/**
 * \brief Função que verifica se as casas à volta estão livres
 * @param e Apontador para o estado da função
 * @param c Coordenada da casa a verificar
 * @return
 */
int casa_livre (ESTADO *e, COORDENADA c);

/**
 * \brief Funçao que verifica o vencedor
 * @param e Apontador para o estado da função
 * @param c Coordenada da casa do vencedor
 */
int verificar_vencedor(ESTADO *e, COORDENADA c);

#endif
