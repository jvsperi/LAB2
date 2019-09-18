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
   //posicionar o simbolo no meio da tela
    matrix[posI][posJ] = (char)219;
    
    printMatrix(matrix);
    //faça posição anterior do @ ser apagada
    matrix[posI][posJ] = ' ';
    if(posI < (ROWS-1)) posI++;
    }

    system("pause");

    return 0;
}
