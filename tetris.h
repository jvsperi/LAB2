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
/*
Inicializa a matriz principal com espaços vazios
*/
void init(char matrix[ROWS][COLUMNS]);

/*
Mostra o conteúdo da matriz principal na tela do computador
*/
void printMatrix(char matrix[ROWS][COLUMNS]);
