#ifndef LAIRASTOS_DADOS_H
#define LAIRASTOS_DADOS_H

/**
 * \brief Estrutura de dados para a casa
 */
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
 * \brief Tipo de dados da coordenada
 */
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
 * \brief Tipo de dados da jogada
 */
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
 * \brief typedef para as jodadas
 */
typedef JOGADA JOGADAS[32];

/**
 * \brief Tipo de dados do estado
 */
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

/**
 * \brief Inicializa o estado
 * @return
 */
ESTADO *inicializar_estado();

/**
 * \brief Inicializa tabuleiro
 * @param tab tabuleiro de dimenções 8 por 8
 */
void inicializar_tabuleiro(ESTADO *estado);

/**
 * \brief Obtem o jogador atual
 * @param estado Apontador para o estado da função
 * @return
 */
int obter_jogador_atual(ESTADO *estado);

/**
 * \brief Obtem o número de jogadas
 * @param estado Apontador para o estado da função
 * @return
 */
int obter_numero_de_jogadas(ESTADO *estado);

/**
 * \brief Obtem o valor da casa
 * @param e Apontador para o estado da função
 * @param l Linha da coordenada da casa
 * @param c Coluna da coordenada da casa
 * @return
 */
CASA obter_estado_casa(ESTADO *e, int l, int c);

/**
 * \brief Função que atualiza o valor da casa
 * @param e Apontador para o estado da função
 * @param c Coordenada da casa a verificar
 */
void atualizar_casa(ESTADO *e, COORDENADA c);

/**
 * \brief Funçao que teste se as casas vizinhas têm a peça branca
 * @param e Apontador para o estado da função
 * @param c Coordenada da casa a verificar
 * @return
 */
int vizinha_branca(ESTADO *e, COORDENADA c);

/**
 * \brief Função que atualiza a jogada
 * @param e Apontador para o estado da função
 * @param c Coordenada da casa que vai ser preenchida pela jogada
 */
void atualizar_jogada(ESTADO *e, COORDENADA c);

#endif
