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
            matrix[i][j] = EMPTY;
        }
    }
}
/*
Mostra o conteúdo da matriz principal na tela do computador
*/
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    //linha de cima
     printf("\t\t\t\t\t");
    for(j=0; j<COLUMNS+1; j++){
        if (j==0) printf ("%c", 201);
        else 
        printf("%c",205);
        if (j==COLUMNS) printf("%c", 187); 
    }
    printf("\n");
    for (i=0;i<ROWS;i++){
        printf("\t\t\t\t\t%c",186);
        for (j=0;j<COLUMNS;j++){
                printf("%c",matrix[i][j]);
        }
        printf("%c\n",186);
    }
    //linha de baixo
    printf("\t\t\t\t\t");
    for(j=0; j<COLUMNS+1; j++){
        if (j==0) printf ("%c", 200);
        else 
        printf("%c",205);
        if (j==COLUMNS) printf("%c", 188); 
    }
    //desenhar barra usando simbolo do caracter
} 
void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
    switch(barra.orientacao){
        case ORIENTACAO_DOWN:
        case ORIENTACAO_UP:
            if(barra.i-4>=0) matrix[barra.i-3][barra.j] = simbolo;
            if(barra.i-3>=0) matrix[barra.i-2][barra.j] = simbolo;
            if(barra.i-2>=0) matrix[barra.i-1][barra.j] = simbolo;
            if(barra.i-1>=0) matrix[barra.i-1][barra.j] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
            break;
        case ORIENTACAO_RIGHT:
        case ORIENTACAO_LEFT:
            if(barra.j+1>=0) matrix[barra.i][barra.j+1] = simbolo;
            if(barra.j+2>=0) matrix[barra.i][barra.j+2] = simbolo;
            if(barra.j-2>=0) matrix[barra.i][barra.j-2] = simbolo;
            if(barra.j-1>=0) matrix[barra.i][barra.j-1] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
        //outra orientacao desenho
        break;
        }
    }
void initBar(Bloco *barra){
    //posicao inicial do personagem
    barra->i = 0;
    barra->j = COLUMNS / 2;
    barra->tipo = TIPO_I;
    barra->width = 5;
    barra->height = 1;
    barra->orientacao = ORIENTACAO_LEFT;
}
void rotate(Bloco *bloco){
    if(bloco->orientacao==ORIENTACAO_RIGHT)
        bloco->orientacao = ORIENTACAO_UP;
    else
        bloco->orientacao++;
        //inverte dimen dos tijolo
        int aux = bloco->width;
        bloco->width = bloco->height;
        bloco->height = aux;

        //bug do canto da tela
    if (bloco->j < (bloco->width/2))
        bloco->j = (bloco->width/2);
    else if (bloco->j > COLUMNS - (bloco->width/2)-1)
        bloco->j = COLUMNS - (bloco->width/2)-1;

        //colisão
}
int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra){
    int retorno = 0;
    
    /* para a barra em pé na base ou quando colide com outros elementos */
    if((barra.i + barra.height/2) > (ROWS) || matrix[barra.i+1][barra.j] != EMPTY)
        if(barra.orientacao == ORIENTACAO_UP || barra.orientacao == ORIENTACAO_DOWN)
            retorno = 1;

    /* para a barra deitada na base ou quando colide com outros elementos */
    if((barra.i + barra.width/2) > (ROWS) || matrix[barra.i+1][barra.j] != EMPTY || matrix[barra.i+1][barra.j+1] != EMPTY
        || matrix[barra.i+1][barra.j+2] != EMPTY || matrix[barra.i+1][barra.j-1] != EMPTY || matrix[barra.i+1][barra.j-2] != EMPTY)
        if(barra.orientacao == ORIENTACAO_LEFT || barra.orientacao == ORIENTACAO_RIGHT)
            retorno = 1;           

    return retorno;
}
