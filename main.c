/* 
Jogo interativo Tetris Implementado em linguagem C para uso no console (terminal de comandos)

Para executar
> start programa.exe

Autor João Victor Speri da Silva
Data 28/08/2019
*/

#include "tetris.h"
/* 
    Parte principal do programa, responsavel por iniciar e chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    int posI,posJ;
    //posicao inicial do personagem
    posI = ROWS / 2;
    posJ = COLUMNS / 2;
    //inicializando matriz
    init(matrix);

    while(1){
    system("cls");
   
    matrix[posI][posJ] = ' ';
    
    printMatrix(matrix);

    matrix[posI][posJ] = 219;
    if(posJ < COLUMNS) posJ++;
    }

    system("pause");

    return 0;
}
