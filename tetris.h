/* 
Jogo interativo Tetris Implementado em linguagem C para uso no console (terminal de comandos)

Autor João Victor Speri da Silva
Data 28/08/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//config. dimensões da matriz principal do jogo
#define COLUMNS 60
#define ROWS 25
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define TECLA_a 97
#define TECLA_d 100
#define TECLA_A 65
#define TECLA_D 68
//orientacoes das peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_DOWN 2 
#define ORIENTACAO_LEFT 3 
#define ORIENTACAO_RIGHT 4
// tipos das peças
#define TIPO_L 1
#define TIPO_L_R 2
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5
#define TIPO_O 6
#define TIPO_I 7
//configuracoes de layout
#define PIXEL 219
#define EMPTY 32

//estrutura padrão de componentes
typedef struct{
    int i; //posicao linha
    int j; //posicao coluna
    int orientacao; //orientacao peça
    int tipo; // tipo de peça (7 possiveis)
    int width; //largura peça
    int height; // altura peça
}Bloco;
/*
Inicializa a matriz principal com espaços vazios
*/
void init(char matrix[ROWS][COLUMNS]);

/*
Mostra o conteúdo da matriz principal na tela do computador
*/
void printMatrix(char matrix[ROWS][COLUMNS]);
