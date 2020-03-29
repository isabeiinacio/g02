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
            atualizar_jogada(e, c);

        } else {
            atualizar_casa(e, c);
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

int verificar_vencedor(ESTADO *e, COORDENADA d){
    int r = 0;
    COORDENADA casa_vizinha = d;

    if(d.linha == 7 && d.coluna == 7)
        printf("Vitoria do Jogador 2\n");
    else if(d.linha == 0 && d.coluna == 0)
        printf("Vitoria do Jogador 1\n");

    else{
        for (int l = -1; l < 2; l++)
        {
            for (int c = -1; c < 2; c++)
            {
                COORDENADA v = {d.coluna + c, d.linha + l};
                if (obter_estado_casa(e, v.linha, v.coluna) == VAZIO){
                    r = 1;
                }
            }
        }
        if (r == 0){
            if(obter_jogador_atual(e) == 1)
                printf("Vitoria do jogador 2\n");
            else printf("Vitoria do jogador 1\n");
        }
    }
    return r;
}
