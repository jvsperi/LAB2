#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 60
#define ROWS 25

void init(char matrix[ROWS][COLUMNS]){
    int i,j;
    for (i=0;i<ROWS;i++){
        for (j=0;j<COLUMNS;j++){
            matrix[i][j] = 219;
        }
    }
}
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;
    for (i=0;i<ROWS;i++){
        for (j=0;j<COLUMNS;j++){
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }
} 

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