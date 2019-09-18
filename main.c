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
    int keypressed = 0;
    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMNS / 2;
    //inicializando matriz
    init(matrix);
    
    //apagar cursor da tela 

    ShowConsoleCursor(0);
    system("cls");

    // 27 = tecla esc
    while(keypressed != 27){
        gotoxy(0,0);
   //posicionar o simbolo no meio da tela
    matrix[posI][posJ] = (char)219;
    
    printMatrix(matrix);
    //faça posição anterior do @ ser apagada
    matrix[posI][posJ] = ' ';
    if(posI < (ROWS-1)) posI++;

    //lendo teclas
    keypressed = 0;
    if(kbhit()) keypressed = getch();
    if(keypressed==ARROWS) keypressed = getch();
                switch(keypressed){
                case LEFT:
                case TECLA_a: 
                case TECLA_A :if (posJ > 0) posJ--;break; //p esquerda
                case TECLA_d:
                case RIGHT: 
                case TECLA_D: if (posJ < COLUMNS-1) posJ++;break; // p direita
        }
    }
    printf("\n");
    system("pause");

    return 0;
}
