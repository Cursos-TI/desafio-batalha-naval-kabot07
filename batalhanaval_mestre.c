#include <stdio.h>

#define COLUNAS 10 //definir tamanhos
#define LINHAS 10


int main () {
   
    // No campo: Agua = 0, Habilidades = 5, Navios = 3
    
    // Definindo cabeçalho fixo de eixos
    char coluna[COLUNAS] = {'A','B','C','D','E','F','G','H','I','J'};
    int linha[LINHAS]  = {1,2,3,4,5,6,7,8,9,10};
    
    // Definindo campo de batalha
    int campo[LINHAS][COLUNAS];  

    // Inicializa a matriz com 0
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            campo[i][j] = 0;
        }
    }
    
    //POSICIONANDO NAVIOS
    // 0 é agua e 3 é navio

    // Posicionar navio na vertical
    if (campo[6][9] == 0 && campo[5][9] == 0 && campo[4][9] == 0) { // veririca se o campo está vazio
    campo[6][9] = 1;
    campo[5][9] = 1;
    campo[4][9] = 1;
    } else {
    // Caso contrário, exibe erro
    printf("Erro: Sobreposição detectada\n");
}

    // Posicionar navio na horizontal
    if (campo[6][1] == 0 && campo[6][2] == 0 && campo[6][3] == 0) {
    campo[6][1] = 3;
    campo[6][2] = 3;
    campo[6][3] = 3;
} else {
    printf("Erro: Sobreposição detectada\n");
}

    // Posicionar navio na diagonal esquerda
    if (campo[7][3] == 0 && campo[8][4] == 0 && campo[9][5] == 0) {
    campo[7][3] = 3;
    campo[8][4] = 3;
    campo[9][5] = 3;
} else {
    printf("Erro: Sobreposição detectada\n");
}

    // Posicionar navio na diagonal direita
    if (campo[7][2] == 0 && campo[8][1] == 0 && campo[9][0] == 0) {
    campo[7][2] = 3;
    campo[8][1] = 3;
    campo[9][0] = 3;
} else {
    printf("Erro: Sobreposição detectada\n");
}

    // Matrizes para habilidades
    int cruz[3][5]; 
    int cone[3][5]; 
    int octa[3][3];
    int meio = 5 / 2;  // Meio das habilidades
    int formato; //para dar o formato
  

    // HABILIDADE CRUZ (valor 5)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == meio - 1 || j == meio)
                cruz[i][j] = 5;
            else
                cruz[i][j] = 0;
        }
    } 

    // HABILIDADE CONE (valor 5)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) { 
            if (j >= meio) formato = j - meio;   
            else formato = meio - j;
            if (i >= formato) 
            
            cone[i][j] = 5;
        else
            cone[i][j] = 0;
    }
}

    // HABILIDADE OCTAEDRO (valor 5)
    
for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == meio - 1 || j == meio - 1)
                octa[i][j] = 5;
            else
                octa[i][j] = 0;
        }
    } 

    // Posicionando as habilidades no campo de batalha
    int meiox, meioy;

    // Cruz no campo (posição: 1,0)
    meiox = 1; meioy = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (meiox + i < LINHAS && meioy + j < COLUNAS) {
                campo[meiox + i][meioy + j] = cruz[i][j];
            }
        }
    }

    // Cone no campo (posição: 1,5)
    meiox = 1; meioy = 5;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (meiox + i < LINHAS && meioy + j < COLUNAS) {
                campo[meiox + i][meioy + j] = cone[i][j];
            }
        }
    }

    //Octa no campo (posição: 6,5)
    meiox = 6; meioy = 5;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (meiox + i < LINHAS && meioy + j < COLUNAS) {
                campo[meiox + i][meioy + j] = octa[i][j];
            }
        }
    }

    // Exibe o cabeçalho
    printf("***** BATALHA NAVAL *****\n\n   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf("%c ", coluna[j]);
    }
    printf("\n");
   
   
    // Exibe o campo

    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", linha[i]);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", campo[i][j]); 
        }
        printf("\n");
    }



    // Karol Botelho
    return 0;
}
