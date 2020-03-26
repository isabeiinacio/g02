#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "dados.h"
#include "logica.h"

int validar_jogada(ESTADO *e, COORDENADA c) {
    if(obter_estado_casa(e, c.linha, c.coluna) == VAZIO) {
        if(vizinha_branca(e, c) == 1) return 1;
        else return 0;
    }
    else return 0;
}

int jogar(ESTADO *e, COORDENADA c) {

    if(validar_jogada(e ,c) == 1) {
        if (obter_jogador_atual(e) == 1) {
            atualizar_casa(e, c);
            verificar_vencedor(e, c);
            atualizar_jogada(e, c);

        } else {
            atualizar_casa(e, c);
            verificar_vencedor(e, c);
            atualizar_jogada(e, c);
        }
    } else return 0;

    return 1;
}

int casa_livre(ESTADO *e, COORDENADA c) {
    if (c.linha >= e->ultima_jogada.linha - 1 && c.linha <= e->ultima_jogada.linha + 1 &&
        c.coluna <= e->ultima_jogada.coluna - 1 && c.coluna >= e->ultima_jogada.coluna + 1) {
        if (obter_estado_casa(e, c.linha, c.coluna) != PRETA && obter_estado_casa(e, c.linha, c.coluna) != BRANCA) {
            return 1;
        }
    } else return 0;
}

int verificar_vencedor(ESTADO *e, COORDENADA c){
    if(c.linha == 7 && c.coluna == 7)
        printf("Vitoria do Jogador 2\n");
    if(c.linha == 0 && c.coluna == 0)
        printf("Vitoria do Jogador 1\n");
    }
