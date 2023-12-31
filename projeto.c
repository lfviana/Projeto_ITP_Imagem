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

void salvarCoresTrocadas(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", coluna);
    fprintf (arquivo, "%d\n", linha);
    fprintf (arquivo, "16");

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", imagem[i][j].r);
            fprintf(arquivo, "%d ", imagem[i][j].g);
            fprintf(arquivo, "%d\n", imagem[i][j].b);
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
    matAux = (pixel**) malloc(coluna * sizeof(pixel*));
    for (i = 0; i < coluna; i++) {
        matAux[i] = (pixel*) malloc(linha * sizeof(pixel));
    }
    int linhaAux = 0, colunaAux = 0;

    linhaAux = coluna - 1;
    colunaAux = 0;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            matAux[i][j].r = imagem[linha - 1 - j][i].r;
            matAux[i][j].g = imagem[linha - 1 - j][i].g;
            matAux[i][j].b = imagem[linha - 1 - j][i].b;
        }
    }

    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "w");

    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d\n", linha);
    fprintf(arquivo, "%d\n", coluna);
    fprintf(arquivo, "%d\n", max);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    fclose(arquivo);

    // Liberar a memória alocada para matAux
    for (i = 0; i < coluna; i++) {
        free(matAux[i]);
    }
    free(matAux);
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

void salvarBordas(pixel** imagem, char *code, int max, int coluna, int linha){
    int i, j,aux;
    FILE *arquivo;
    pixel **matAux;
    matAux = (pixel**) malloc(linha*sizeof(pixel*));
    for(int i = 0;i < coluna;i++){
      matAux[i] = (pixel*) malloc(coluna*sizeof(pixel));
    }

    for (i = 1; i < linha-1; i++) {
        for (j = 1; j < coluna-1; j++) {
           
            aux = (int)( (imagem[i-1][j].r) + (imagem[i][j-1].r) + (imagem[i+1][j].r) +  (imagem[i][j+1].r)+(imagem[i][j].r*(-4)) );
            if(aux < 0){
                matAux[i][j].r = 0;
            }else{
                matAux[i][j].r = aux;
            }
            aux =(int)( (imagem[i-1][j].g) + (imagem[i][j-1].g) + (imagem[i+1][j].g) +  (imagem[i][j+1].g)+(imagem[i][j].g*(-4)) );
            if(aux < 0){
                matAux[i][j].g = 0;
            }else{
                matAux[i][j].g = aux;
            }
            aux= (int)( (imagem[i-1][j].b) + (imagem[i][j-1].b) + (imagem[i+1][j].b) +  (imagem[i][j+1].b)+(imagem[i][j].b*(-4)) );
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

void salvarRelevo(pixel** imagem, char *code, int max, int coluna, int linha){
    int i, j,aux;
    FILE *arquivo;
    pixel **matAux;
    matAux = (pixel**) malloc(linha*sizeof(pixel*));
    for(int i = 0;i < coluna;i++){
      matAux[i] = (pixel*) malloc(coluna*sizeof(pixel));
    }

    for (i = 1; i < linha-1; i++) {
        for (j = 1; j < coluna-1; j++) {
           
            aux = (int)( (imagem[i-1][j-1].r*(-2)) + (imagem[i+1][j+1].r*(2)) + (imagem[i-1][j].r*(-1)) + (imagem[i][j-1].r*(-1)) + (imagem[i+1][j].r) +  (imagem[i][j+1].r)+(imagem[i][j].r*(1)) );
            if(aux < 0){
                matAux[i][j].r = 0;
            }else{
                matAux[i][j].r = aux;
            }
            aux =(int)( (imagem[i-1][j-1].g*(-2)) + (imagem[i+1][j+1].g*(2)) + (imagem[i-1][j].g*(-1)) + (imagem[i][j-1].g*(-1)) + (imagem[i+1][j].g) +  (imagem[i][j+1].g)+(imagem[i][j].g*(1)) );
            if(aux < 0){
                matAux[i][j].g = 0;
            }else{
                matAux[i][j].g = aux;
            }
            aux= (int)( (imagem[i-1][j-1].b*(-2)) + (imagem[i+1][j+1].b*(2)) + (imagem[i-1][j].b*(-1)) + (imagem[i][j-1].b*(-1)) + (imagem[i+1][j].b) +  (imagem[i][j+1].b)+(imagem[i][j].b*(1)) );
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

int negativar(int n, int v[],int pos){
    if(pos > 0){
        if (n == pos){
            return v[pos];
        }else{
            return negativar(n,v,pos-1);
        }
    }
}

void salvarNegativo(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j = 0 ;
    FILE *arquivo;
    pixel **matAux;
    matAux = (pixel**) malloc(linha*sizeof(pixel*));
    for(int i = 0;i < coluna;i++){
      matAux[i] = (pixel*) malloc(coluna*sizeof(pixel));
    }
    int *neg;
    neg = (int*) malloc((max+1)*sizeof(int));
    for(i = max; i >= 0; i--){
        neg[j] = i;
        j++;
    }

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            matAux[i][j].r = negativar(imagem[i][j].r, neg, 255);
            matAux[i][j].g = negativar(imagem[i][j].g, neg, 255);
            matAux[i][j].b = negativar(imagem[i][j].b, neg, 255);
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

    fclose(arquivo);
}


void ImprimeTelaDeOpcoes(){
    printf("*******************\n");
    printf("Escolha uma opção:\n");
    printf("*******************\n");
    printf("\n");
    printf("1 - Escala Cinza;\n");
    printf("2 - Ampliar;\n");
    printf("3 - Reduzir;\n");
    printf("4 - Rotacionar 90° À direita;\n");
    printf("5 - Rotacionar 90° À esquerda;\n");
    printf("6 - Efeito Blurring;\n");
    printf("7 - Efeito Sharpening;\n");
    printf("8 - Detecção de bordas;\n");
    printf("9 - Destacar Relevo;\n");
    printf("10 - Cores Trocadas;\n");
    printf("11 - Negativo;\n");
    printf("12 - Sair\n");

}

int EscolheOpcao(){
    int r;
    scanf("%d", &r);
    return r;
}


int main(int argc, char** argv) {
    int opcao;
    pixel **imagem; //cria uma matriz de pixeis para armazenar a imagem
    imagem = (pixel**) malloc(MAX*sizeof(pixel*));
    for(int i = 0;i < MAX;i++){
      imagem[i] = (pixel*) malloc(MAX*sizeof(pixel));
    }
    char code[3]; //o código para saber se a imagem é ascii ou binária
    int max; //o valor máximo de tonalidade de cada pixel
    int larg, alt; // largura e altura da imagem em pixeis
   
    ler(imagem,&code[3],&max,&larg,&alt);
 do
    {
      ImprimeTelaDeOpcoes();
      opcao = EscolheOpcao();
     if (opcao == 1){
       salvarCinza(imagem,&code[3],max,larg,alt);
     }
     if (opcao == 2){
       
     }
     if (opcao == 3){
       
     }
     if(opcao == 4){
       girar90grausL(imagem,&code[3],max,larg,alt);
     }
     if(opcao == 5){
       girar90grausR(imagem,&code[3],max,larg,alt);
     }
     if(opcao == 6){
        salvarSharpening(imagem,&code[3],max,larg,alt);
     }
     if(opcao == 7){
        salvarBlurring(imagem,&code[3],max,larg,alt);
     }
     if(opcao == 8){
        salvarBordas(imagem,&code[3],max,larg,alt);
     }
     if(opcao == 9){
        salvarRelevo(imagem,&code[3],max,larg,alt);
     }
     if(opcao == 10){
        salvarCoresTrocadas(imagem,&code[3],max,larg,alt);
     }
     if(opcao == 11){
        salvarNegativo(imagem,&code[3],max,larg,alt);
     }
     
    } while (opcao != 12);

    return 0;
}

