/* 
Jogo interativo Tetris Implementado em linguagem C para uso no console (terminal de comandos)

Para executar
> start programa.exe

Autor João Victor Speri da Silva
Data 28/08/2019
*/

#include "tetris.h"
#include "display.h"

/* 
    Parte principal do programa, responsavel por iniciar e chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    int posI,posJ;
    //posicao inicial do personagem
    posI = ROWS / ROWS;
    posJ = COLUMNS / 2;
    //inicializando matriz
    init(matrix);
    
    //apagar cursor da tela 

    ShowConsoleCursor(0);
    system("cls");

    while(1){
        gotoxy(0,0);
   
    matrix[posI][posJ] = ' ';
    
    printMatrix(matrix);

    matrix[posI][posJ] = 219;
    if(posI < ROWS) posI++;
    }

    system("pause");

    return 0;
}
