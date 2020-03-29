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
                    case VAZIO: fprintf(file, ".");break;
                    case BRANCA: fprintf(file, "*");break;
                    case PRETA: fprintf(file, "#");break;
                }
        }
        fputc('\n', file);
    }
}

void ler_tabuleiro(ESTADO *e, char* nome){
    FILE *tabuleiro;
    char buffer[8][9];
    tabuleiro = fopen( nome ,"r");
    int l = 0;
    while (l<8 && fgets(buffer[l], BUF_SIZE, tabuleiro) != NULL)
        l++;
    int p=0;
    for (int h = 7; h >= 0; h--){
        for (int c = 0; c < 8; c++){
            COORDENADA atual = {h,c};
            CASA v;
            set_casa(e, atual, buffer[p][c]);
        }
        p++;
    }
}

void guardar_tabuleiro(ESTADO *e, char* nome){

    FILE *tabuleiro;
    tabuleiro = fopen( nome ,"w");

    mostrar_tabuleiro(tabuleiro, e);

    for(int i=1;i<=obter_numero_de_jogadas(e);i++){
        printf("%d %d",ob)                                //<-
    }

    fclose(tabuleiro);
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    int n_comandos = 0;
    char *nome = (char *) malloc(BUF_SIZE);

    mostrar_tabuleiro(stdout, e);
    prompt(e, n_comandos++);

    int r=1;

    while(fgets(linha, BUF_SIZE, stdin)) {
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            int n = jogar(e, coord);
            if (!n)
                printf("A jogada nao e valida\n");
            mostrar_tabuleiro(stdout, e);
            r=verificar_vencedor (e,coord);
            if(r==0)
               break;
            prompt(e, n_comandos++);
        }
        if(sscanf(linha, "gr %s", nome) == 1) {
            guardar_tabuleiro(e,nome);
            prompt(e, n_comandos++);
        }
        if(sscanf(linha, "ler %s", nome) == 1) { //Falta por a funcionar
            ler_tabuleiro(e,nome);
            mostrar_tabuleiro(stdout,e);
            prompt(e, n_comandos++);
        }
        if(strlen(linha) == 2 && strncmp(linha, "Q", 1) == 0) {
            printf("Obrigado por jogar\n"); break;
        }
    }
}
