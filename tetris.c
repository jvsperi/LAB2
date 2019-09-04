/* 
Jogo interativo Tetris Implementado em linguagem C para uso no console (terminal de comandos)

Autor João Victor Speri da Silva
Data 28/08/2019
*/

#include "tetris.h"
#include <stdio.h>
/*
Inicializa a matriz principal com espaços vazios
*/
void init(char matrix[ROWS][COLUMNS]){
    int i,j;
    for (i=1;i<ROWS;i++){
        for (j=1;j<COLUMNS;j++){
            matrix[i][j] = 219;
        }
    }
}
/*
Mostra o conteúdo da matriz principal na tela do computador
*/
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;
    for (i=1;i<ROWS;i++){
        for (j=1;j<COLUMNS;j++){
                printf("%c",matrix[i][j]);
        }
        printf("\n");
    }
} 