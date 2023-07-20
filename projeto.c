#include "projeto.h"


#define MAX 1300

void ler(pixel** imagem, char *code, int *max, int *coluna, int *linha) {
    int i, j;
   
    FILE *arquivo;
    char nome_arq[50];

    arquivo = fopen("got.ppm", "r");
       
    if ((arquivo = fopen("got.ppm", "r")) == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    fscanf(arquivo, "%s", code);
    printf("%s\n", code);
    fscanf(arquivo, "%d", coluna);
    printf("%d\n", *coluna);
    fscanf(arquivo, "%d", linha);
    printf("%d\n", *linha);
    fscanf(arquivo, "%d", max);
    printf("%d\n", *max);

    for (i = 0; i < *linha; i++) {
        for (j = 0; j < *coluna; j++) {
       
            fscanf(arquivo, "%d ", &imagem[i][j].r);
            fscanf(arquivo, "%d ", &imagem[i][j].g);
            fscanf(arquivo, "%d\n", &imagem[i][j].b);
        }
    }
    fclose(arquivo);
}

void salvar(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", coluna);
    fprintf (arquivo, "%d\n", linha);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", imagem[i][j].r);
            fprintf(arquivo, "%d ", imagem[i][j].g);
            fprintf(arquivo, "%d\n", imagem[i][j].b);
        }
    }

    fclose(arquivo);
}

void salvarCinza(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    int media;
    FILE *arquivo;

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", coluna);
    fprintf (arquivo, "%d\n", linha);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            media = (int) (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b)/3;
            fprintf(arquivo, "%d ", media);
            fprintf(arquivo, "%d ", media);
            fprintf(arquivo, "%d\n", media);
        }
    }

    fclose(arquivo);
}

void girar90grausL(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    pixel **matAux;
    matAux = (pixel**) malloc(coluna*sizeof(pixel*));
    for(int i = 0;i < coluna;i++){
      matAux[i] = (pixel*) malloc(linha*sizeof(pixel));
    }
    int linhaAux = 0,colunaAux = 0;

    linhaAux = coluna-1;
    colunaAux = linha-1;
      for(int i = 0; i < linha; i++){
          for(int j = 0; j < coluna; j++){
              matAux[linhaAux - (coluna - 1)][colunaAux].r = imagem[i][j].r;
              matAux[linhaAux - (coluna - 1)][colunaAux].g = imagem[i][j].g;
              matAux[linhaAux - (coluna - 1)][colunaAux].b = imagem[i][j].b;
              linhaAux++;
          }
          linhaAux = coluna-1;
          colunaAux--;
      }

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", linha);
    fprintf (arquivo, "%d\n", coluna);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < coluna; i++) {
        for (j = 0; j < linha; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    fclose(arquivo);
}

void girar90grausR(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    pixel **matAux;
    matAux = (pixel**) malloc(coluna*sizeof(pixel*));
    for(int i = 0;i < coluna;i++){
      matAux[i] = (pixel*) malloc(linha*sizeof(pixel));
    }
    int linhaAux = 0,colunaAux = 0;

    linhaAux = coluna-1;
    colunaAux = linha-1;
      for(int i = 0; i < coluna; i++){
          for(int j = 0; j < linha; j++){
              matAux[i][j].r = imagem[colunaAux - (linha - 1)][linhaAux].r;
              matAux[i][j].g = imagem[colunaAux - (linha - 1)][linhaAux].g;
              matAux[i][j].b = imagem[colunaAux - (linha - 1)][linhaAux].b;
              colunaAux++;
          }
          linhaAux--;
          colunaAux = linha - 1;
      }

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", linha);
    fprintf (arquivo, "%d\n", coluna);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < coluna; i++) {
        for (j = 0; j < linha; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    fclose(arquivo);
}

void salvarAmpliado(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    pixel **matAux;
    matAux = (pixel**) malloc((coluna*2)*sizeof(pixel*));
    for(int i = 0;i < (coluna*2);i++){
      matAux[i] = (pixel*) malloc((linha*2)*sizeof(pixel));
    }
    int linhaAux,colunaAux,x = 0,y = 0;
    linhaAux = linha*2;
    colunaAux = coluna*2;
    for(int i = 0; i < linhaAux; i++){
          for(int j = 0; j < colunaAux; j++){
              matAux[i][j].r = imagem[x][y].r;
              matAux[i][j].g = imagem[x][y].g;
              matAux[i][j].b = imagem[x][y].b;
              matAux[i+1][j].r = imagem[x][y].r;
              matAux[i+1][j].g = imagem[x][y].g;
              matAux[i+1][j].b = imagem[x][y].b;
              if(j%2 != 0 && j != 0){
                y++;

              }
          }
          y = 0;
         
          i++;
          x++;
      }

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", coluna*2);
    fprintf (arquivo, "%d\n", linha*2);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < linha*2; i++) {
        for (j = 0; j < coluna*2; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    fclose(arquivo);
}

void salvarReduzido(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    // Criar a matriz auxiliar reduzida à metade do tamanho da imagem original
    int colunaAux = coluna / 2;
    int linhaAux = linha / 2;
    pixel **matAux = (pixel**)malloc(colunaAux * sizeof(pixel*));
    for (i = 0; i < colunaAux; i++) {
        matAux[i] = (pixel*)malloc(linhaAux * sizeof(pixel));
    }

    // Preenche a matriz auxiliar reduzida com a média dos quadrados de 4 pixels da imagem original
    for (i = 0; i < linhaAux; i++) {
        for (j = 0; j < colunaAux; j++) {
            int sumR = imagem[i*2][j*2].r + imagem[i*2][j*2 + 1].r + imagem[i*2 + 1][j*2].r + imagem[i*2 + 1][j*2 + 1].r;
            int sumG = imagem[i*2][j*2].g + imagem[i*2][j*2 + 1].g + imagem[i*2 + 1][j*2].g + imagem[i*2 + 1][j*2 + 1].g;
            int sumB = imagem[i*2][j*2].b + imagem[i*2][j*2 + 1].b + imagem[i*2 + 1][j*2].b + imagem[i*2 + 1][j*2 + 1].b;

            matAux[i][j].r = sumR / 4;
            matAux[i][j].g = sumG / 4;
            matAux[i][j].b = sumB / 4;
        }
    }

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);
    arquivo = fopen(nome_arq, "w");

    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d\n", colunaAux);
    fprintf(arquivo, "%d\n", linhaAux);
    fprintf(arquivo, "%d\n", max);

    for (i = 0; i < linhaAux; i++) {
        for (j = 0; j < colunaAux; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    fclose(arquivo);
}

void salvarBlurring(pixel** imagem, char *code, int max, int coluna, int linha){
    int i, j,aux;
    FILE *arquivo;
    pixel **matAux;
    matAux = (pixel**) malloc(linha*sizeof(pixel*));
    for(int i = 0;i < coluna;i++){
      matAux[i] = (pixel*) malloc(coluna*sizeof(pixel));
    }

    for (i = 1; i < linha-1; i++) {
        for (j = 1; j < coluna-1; j++) {
           
            aux = (int)( (imagem[i-1][j-1].r) + (imagem[i-1][j].r) + (imagem[i-1][j+1].r) + (imagem[i][j-1].r) + (imagem[i+1][j].r) + (imagem[i+1][j-1].r) +  (imagem[i+1][j+1].r)+ (imagem[i+1][j].r)+(imagem[i][j].r) )/9;
            if(aux < 0){
                //matAux[i][j].r = 0;
            }else{
                matAux[i][j].r = aux;
            }
            aux = (int)( (imagem[i-1][j-1].g) + (imagem[i-1][j].g) + (imagem[i-1][j+1].g) + (imagem[i][j-1].g) + (imagem[i+1][j].g) + (imagem[i+1][j-1].g) +  (imagem[i+1][j+1].g)+ (imagem[i+1][j].g)+(imagem[i][j].g) )/9;
            if(aux < 0){
                //matAux[i][j].g = 0;
            }else{
                matAux[i][j].g = aux;
            }
            aux= (int)( (imagem[i-1][j-1].b) + (imagem[i-1][j].b) + (imagem[i-1][j+1].b) + (imagem[i][j-1].b) + (imagem[i+1][j].b) + (imagem[i+1][j-1].b) +  (imagem[i+1][j+1].b)+ (imagem[i+1][j].b)+(imagem[i][j].b) )/9;
            if(aux < 0){
                //matAux[i][j].b = 0;
            }else{
                matAux[i][j].b = aux;
            }
        }
    }

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", coluna);
    fprintf (arquivo, "%d\n", linha);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }
}

void salvarSharpening(pixel** imagem, char *code, int max, int coluna, int linha){
    int i, j,aux;
    FILE *arquivo;
    pixel **matAux;
    matAux = (pixel**) malloc(linha*sizeof(pixel*));
    for(int i = 0;i < coluna;i++){
      matAux[i] = (pixel*) malloc(coluna*sizeof(pixel));
    }

    for (i = 1; i < linha-1; i++) {
        for (j = 1; j < coluna-1; j++) {
           
            aux = (int)( (imagem[i-1][j].r*(-1)) + (imagem[i][j-1].r*(-1)) + (imagem[i+1][j].r*(-1)) +  (imagem[i][j+1].r*(-1))+(imagem[i][j].r*(5)) );
            if(aux < 0){
                matAux[i][j].r = 0;
            }else{
                matAux[i][j].r = aux;
            }
            aux =(int)( (imagem[i-1][j].g*(-1)) + (imagem[i][j-1].g*(-1)) + (imagem[i+1][j].g*(-1)) +  (imagem[i][j+1].g*(-1))+(imagem[i][j].g*(5)) );
            if(aux < 0){
                matAux[i][j].g = 0;
            }else{
                matAux[i][j].g = aux;
            }
            aux= (int)( (imagem[i-1][j].b*(-1)) + (imagem[i][j-1].b*(-1)) + (imagem[i+1][j].b*(-1)) +  (imagem[i][j+1].b*(-1))+(imagem[i][j].b*(5)) );
            if(aux < 0){
                matAux[i][j].b = 0;
            }else{
                matAux[i][j].b = aux;
            }
        }
    }

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", coluna);
    fprintf (arquivo, "%d\n", linha);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }
}

void ImprimeTelaDeOpcoes() {
    printf("*******************\n");
    printf("Escolha uma opção:\n");
    printf("*******************\n");
    printf("\n");
    printf("gray: Criar imagem em escala de cinza;\n");
    printf("enlarge: Ampliar imagem;\n");
    printf("reduce: Reduzir imagem;\n");
    printf("rotate: Rotacionar 90° À direita;\n");
    printf("rotate_left: Rotacionar 90° À esquerda;\n");
    printf("sharp: Aplicar efeito Blurring;\n");
    printf("blur: Aplicar efeito Sharpening;\n");
    printf("exit: Sair\n");
}

char* EscolheOpcao() {
    char opcao[50];
    scanf("%s", opcao);
    return strdup(opcao); // Retorna uma cópia da string digitada pelo usuário
}


int main(int argc, char** argv) {
    char* opcao;
    pixel **imagem; //cria uma matriz de pixeis para armazenar a imagem
    imagem = (pixel**) malloc(MAX*sizeof(pixel*));
    for(int i = 0; i < MAX; i++){
        imagem[i] = (pixel*) malloc(MAX*sizeof(pixel));
    }
    char code[3]; //o código para saber se a imagem é ascii ou binária
    int max; //o valor máximo de tonalidade de cada pixel
    int larg, alt; // largura e altura da imagem em pixeis

    ler(imagem, code, &max, &larg, &alt);

    do {
        ImprimeTelaDeOpcoes();
        opcao = EscolheOpcao();

        if (strcmp(opcao, "gray") == 0) {
            salvarCinza(imagem, code, max, larg, alt);
        }
        else if (strcmp(opcao, "enlarge") == 0) {
            salvarAmpliado(imagem, code, max, larg, alt);
        }
        else if (strcmp(opcao, "reduce") == 0) {
            salvarReduzido(imagem, code, max, larg, alt);
        }
        else if (strcmp(opcao, "rotate") == 0) {
            girar90grausL(imagem, code, max, larg, alt);
        }
        else if (strcmp(opcao, "rotate_left") == 0) {
            girar90grausR(imagem, code, max, larg, alt);
        }
        else if (strcmp(opcao, "sharp") == 0) {
            salvarSharpening(imagem, code, max, larg, alt);
        }
        else if (strcmp(opcao, "blur") == 0) {
            salvarBlurring(imagem, code, max, larg, alt);
        }
        
    } while (strcmp(opcao, "exit") != 0);

    // Liberar a memória alocada para a matriz de pixels
    for (int i = 0; i < MAX; i++) {
        free(imagem[i]);
    }
    free(imagem);

    return 0;
}