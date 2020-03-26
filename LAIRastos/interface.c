#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "dados.h"
#include "logica.h"

#define BUF_SIZE 1024

void prompt(ESTADO *e, int n_comandos) {
    printf("# <%d> <PL%d> <%d>", n_comandos, obter_jogador_atual(e), obter_numero_de_jogadas(e));
}

void mostrar_tabuleiro(FILE* file, ESTADO *e) {

    for (int l = 7; l >= 0; l--) {
        for(int c = 0; c < 8; c++) {
            if(l == 7 && c == 7) fprintf(file, "2");
            else if(l == 0 && c == 0) fprintf(file, "1");
            else
                switch(obter_estado_casa(e, l, c)) {
                    case VAZIO: fprintf(file, "."); break;
                    case BRANCA: fprintf(file, "*");break;
                    case PRETA: fprintf(file, "#"); break;
                }
        }
        fputc('\n', file);
    }
}

void guardar_tabuleiro(ESTADO *e) {

    FILE *tabuleiro;
    tabuleiro = fopen("tabuleiro.txt", "w");

    mostrar_tabuleiro(tabuleiro, e);

    fclose(tabuleiro); //verificar jogada nao deixa ver o 1 ou acabar
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    int n_comandos = 0;

    mostrar_tabuleiro(stdout, e);
    prompt(e, n_comandos++);

    while(fgets(linha, BUF_SIZE, stdin)) {
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            //COORDENADA coord = {*lin , *col}; //possivel merda
            int n = jogar(e, coord);
            if (!n)
                printf("A jogada nao e valida\n");
            mostrar_tabuleiro(stdout, e);
            prompt(e, n_comandos++);
            verificar_vencedor (e,coord);
        }
        if(strlen(linha) == 3 && strncmp(linha, "gr", 2) == 0) {
            guardar_tabuleiro(e);
            prompt(e, n_comandos++);
        }
        if(strlen(linha) == 4 && strncmp(linha, "ler", 3) == 0) { //Falta implementar
            prompt(e, n_comandos++);
        }
        if(strlen(linha) == 2 && strncmp(linha, "Q", 1) == 0) {
            printf("Obrigado por jogar"); break;
        }
    }
}
