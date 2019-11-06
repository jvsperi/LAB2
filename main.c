/* 
Jogo interativo Tetris Implementado em linguagem C para uso no console (terminal de comandos)

Para executar
> start programa.exe

Autor João Victor Speri da Silva
Data 28/08/2019
*/

#include "tetris.h"
#include "display.h"
#define DEBUG 0

/* 
    Parte principal do programa, responsavel por iniciar e chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    int keypressed = 0;
    Bloco tijolo;

    //posicao inicial tijolo
    initBar(&tijolo);

    //apagar cursor da tela 
    ShowConsoleCursor(0);
    system("cls");

    //inicializando matriz
    init(matrix);

    // 27 = tecla esc
    while(keypressed != ESC){
        gotoxy(0,0);

        #if DEBUG == 1
            printf("\n\t Posicao %c = (%d,%d)\n",219, tijolo.i, tijolo.j);
            printf("\t Dimensao = (%d,%d)\n", tijolo.width, tijolo.height);
        #endif

   //posicionar o simbolo no meio da tela
    drawBar(matrix,tijolo,PIXEL);
    
    printMatrix(matrix);

    //faça posição anterior do @ ser apagada
    if(!collisionDetect(matrix, tijolo)){
        drawBar(matrix,tijolo,EMPTY);
        //posicao da @ ir para direita
        if(tijolo.i < (ROWS-1)) tijolo.i++;
    }else{
        initBar(&tijolo);
    }
    //lendo teclas
    keypressed = 0;
    if(kbhit()) keypressed = getch();
    if(keypressed==ARROWS) keypressed = getch();
                switch(keypressed){
                case TECLA_a: 
                case TECLA_A :
                case LEFT:
                    if(matrix[tijolo.i][tijolo.j-3] == EMPTY) if (tijolo.j - (tijolo.width/2) > 0) tijolo.j--;break; //p esquerda
                case TECLA_d:
                case TECLA_D: 
                case RIGHT: 
                    if(matrix[tijolo.i][tijolo.j+3] == EMPTY) if (tijolo.j + (tijolo.width/2) < COLUMNS-1) tijolo.j++;break; // p direita
                case TECLA_ESPACO: rotate(&tijolo);
                break;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
