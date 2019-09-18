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

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
        }
    }
}
/*
Mostra o conteúdo da matriz principal na tela do computador
*/
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    //linha de cima
     printf("\t\t\t");
    for(j=0; j<COLUMNS+1; j++){
        if (j==0) printf ("%c", 201);
        else 
        printf("%c",205);
        if (j==COLUMNS) printf("%c", 187); 
    }
    printf("\n");
    for (i=0;i<ROWS;i++){
        printf("\t\t\t%c",186);
        for (j=0;j<COLUMNS;j++){
                printf("%c",matrix[i][j]);
        }
        printf("%c\n",186);
    }
    //linha de baixo
    printf("\t\t\t");
    for(j=0; j<COLUMNS+1; j++){
        if (j==0) printf ("%c", 200);
        else 
        printf("%c",205);
        if (j==COLUMNS) printf("%c", 188); 
    }
} 