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
    switch(tijolo.orientacao){
        case ORIENTACAO_UP:
            if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j] = PIXEL;
            if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j] = PIXEL;
            if(tijolo.i-1>=0)matrix[tijolo.i-1][tijolo.j] = PIXEL;
            matrix[tijolo.i][tijolo.j] = PIXEL;
            break;
        case ORIENTACAO_LEFT:
            if(tijolo.j < COLUMNS) matrix[tijolo.i][tijolo.j-3] = PIXEL;
            if(tijolo.j > 0) matrix[tijolo.i][tijolo.j-2] = PIXEL;
            matrix[tijolo.i][tijolo.j-1] = PIXEL;
            matrix[tijolo.i][tijolo.j] = PIXEL;
        break; 
   }
    
    printMatrix(matrix);
    //faça posição anterior do @ ser apagada
    switch(tijolo.orientacao){
        case ORIENTACAO_UP: 
            if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j] = EMPTY;
            if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j] = EMPTY;
            if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j] = EMPTY;
            matrix[tijolo.i][tijolo.j] = EMPTY;
            break;
        case ORIENTACAO_LEFT:    
            if(tijolo.j < COLUMNS) matrix[tijolo.i][tijolo.j-3] = EMPTY;
            if(tijolo.j > 0) matrix[tijolo.i][tijolo.j-2] = EMPTY;
            matrix[tijolo.i][tijolo.j-1] = EMPTY;
            matrix[tijolo.i][tijolo.j] = EMPTY;
            break;
    }
    
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
        }
    }
    printf("\n");
    system("pause");

    return 0;
}
