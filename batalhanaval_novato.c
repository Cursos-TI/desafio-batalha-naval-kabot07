#include <stdio.h>

int main () {
    
    //definindo cabeçalho fixo de eixos
    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int linha[10]  = {1,2,3,4,5,6,7,8,9,10};
    
    //definindo campo de batalha
    int campo[10][10]; // matriz 10x10 de inteiros

    // Inicializa a matriz com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            campo[i][j] = 0;
        }
    }
    
    // 0 é agua e 3 é navio

    // Posicionar navio na vertical
    campo[4][5] = 3;
    campo[3][5] = 3;
    campo[2][5] = 3;

    // Posicionar navio na horizontal

    campo[6][1] = 3;
    campo[6][2] = 3;
    campo[6][3] = 3;


    // Exibe o cabeçalho
    printf("***** BATALHA NAVAL *****\n\n   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", coluna[j]); //coluna
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", linha[i]); //linha

    // Exibe o campo

        for (int j = 0; j < 10; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }

  //Karol Botelho
return 0;
}
