#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "dados.h"
#include "logica.h"


void inicializar_tabuleiro(ESTADO *e) {

    for (int l = 7; l >= 0; l--)
        for(int c = 0; c < 8; c++) {
            e->tab[l][c] = VAZIO;
        }

    e->tab [4][4] = BRANCA;
}

ESTADO *inicializar_estado() {

    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));

    inicializar_tabuleiro(e);
    e->num_jogadas = 0;
    e->jogador_atual = 1;
    e->ultima_jogada.linha = 4;
    e->ultima_jogada.coluna = 4;

    return e;
}

CASA obter_estado_casa (ESTADO *e, int l, int c) {
    return e->tab[l][c];
}

int obter_jogador_atual(ESTADO *e){
    if(e->jogador_atual == 1) return 1;
    else return 2;
}
int obter_numero_de_jogadas(ESTADO *e) {
    return e->num_jogadas;
}

void atualizar_casa(ESTADO *e, COORDENADA c) {
    e->tab[c.linha][c.coluna] = BRANCA;
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA;
    e->ultima_jogada = c;
}

void atualizar_jogada(ESTADO *e, COORDENADA c) {
    if(obter_jogador_atual(e) == 1) {
        e->jogadas[e->num_jogadas].jogador1 = c;
        e->jogador_atual = 2;
    } else {
        e->jogadas[e->num_jogadas].jogador2 = c;
        e->num_jogadas++;
        e->jogador_atual = 1;
    }
}

JOGADA obter_jogada(ESTADO *e, int n){              //<-

}

int vizinha_branca(ESTADO *e, COORDENADA c) {
    if(c.linha == e->ultima_jogada.linha - 1 && c.coluna == e->ultima_jogada.coluna - 1) return 1;
    if(c.linha == e->ultima_jogada.linha - 1 && c.coluna == e->ultima_jogada.coluna) return 1;
    if(c.linha == e->ultima_jogada.linha - 1 && c.coluna == e->ultima_jogada.coluna + 1) return 1;
    if(c.linha == e->ultima_jogada.linha && c.coluna == e->ultima_jogada.coluna - 1) return 1;
    if(c.linha == e->ultima_jogada.linha && c.coluna == e->ultima_jogada.coluna + 1) return 1;
    if(c.linha == e->ultima_jogada.linha + 1 && c.coluna == e->ultima_jogada.coluna - 1) return 1;
    if(c.linha == e->ultima_jogada.linha + 1 && c.coluna == e->ultima_jogada.coluna) return 1;
    if(c.linha == e->ultima_jogada.linha + 1 && c.coluna == e->ultima_jogada.coluna + 1) return 1;
    else return 0;
}

void set_casa (ESTADO *e, COORDENADA c, CASA valor){
    e->tab[c.coluna][c.linha] = valor;
}

COORDENADA obter_ultcoord (ESTADO *e){
    return e->ultima_jogada;
}
