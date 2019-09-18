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
/*void init(char matrix[ROWS][COLUMNS]){
    int i,j;
    for (i=0;i<ROWS;i++){
        for (j=0;j<COLUMNS;j++){
            if ((j==59) && (i==24)) matrix[i][j] = (char)188;
            else if ((j==59) && (i==0)) matrix[i][j] = (char)187;
            else if ((j==0) && (i==24)) matrix[i][j] = (char)200;
            else if ((j==0) && (i==0)) matrix[i][j] = (char)201;   
            else if ((i==0) || (i==24)) matrix[i][j] = (char)205; //alterei
            else if ((j==0) || (j==59)) matrix[i][j] = (char)186; //alterei
            else matrix[i][j] = ' ';
        }     
    }
}*/
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
    char a = 205, b = 186;


    //linha de cima
     printf("\t\t\t");
    for(j=0; j<COLUMNS+2; j++){
        printf("%c",a);
    }
    printf("\n");
    for (i=0;i<ROWS;i++){
        printf("\t\t\t%c",b);
        for (j=0;j<COLUMNS;j++){
                printf("%c",matrix[i][j]);
        }
        printf("%c\n",b);
    }
    //linha de baixo
    printf("\t\t\t");
    for(j=0; j<COLUMNS+2; j++){
        printf("%c",a);
    }
} 