/* 
Jogo interativo Tetris Implementado em linguagem C para uso no console (terminal de comandos)

Para executar
> start programa.exe

Autor João Victor Speri da Silva
Data 28/08/2019
*/

#include "tetris.h"
#include "display.h"
#define DEBUG 1

/* 
    Parte principal do programa, responsavel por iniciar e chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    int keypressed = 0;
    Bloco tijolo;
    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS / 2;
    tijolo.tipo = TIPO_I;
    tijolo.width = 1;
    tijolo.height = 4;
    tijolo.orientacao = ORIENTACAO_LEFT;
    //inicializando matriz
    init(matrix);
    
    //apagar cursor da tela 

    ShowConsoleCursor(0);
    system("cls");

    // 27 = tecla esc
    while(keypressed != ESC){
        gotoxy(0,0);

        #if DEBUG == 1
            printf("\t %c = (%d,%d)\n",219, tijolo.i, tijolo.j);
        #endif

   //posicionar o simbolo no meio da tela
    drawBar(matrix,tijolo,PIXEL);
    
    printMatrix(matrix);

    //faça posição anterior do @ ser apagada
    drawBar(matrix,tijolo,EMPTY);
    
    if(tijolo.i < (ROWS-1)) tijolo.i++;

    //lendo teclas
    keypressed = 0;
    if(kbhit()) keypressed = getch();
    if(keypressed==ARROWS) keypressed = getch();
                switch(keypressed){
                case LEFT:
                case TECLA_a: 
                case TECLA_A :if (tijolo.j > 0) tijolo.j--;break; //p esquerda
                case TECLA_d:
                case RIGHT: 
                case TECLA_D: if (tijolo.j < COLUMNS-1) tijolo.j++;break; // p direita
                case TECLA_ESPACO: 
                    if(tijolo.orientacao==ORIENTACAO_RIGHT)
                        tijolo.orientacao = ORIENTACAO_UP;
                    else
                        tijolo.orientacao++;
        }
    }
    printf("\n");
    system("pause");

    return 0;
}
