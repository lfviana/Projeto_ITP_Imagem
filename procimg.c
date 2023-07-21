#include "projeto.h"


#define MAX 1300

// Função para ler dados de uma imagem de um arquivo PPM
void ler(pixel** imagem, char *code, int *max, int *coluna, int *linha) {
    int i, j;
    FILE *arquivo;
    char nome_arq[50];

    // Abre o arquivo de imagem no formato PPM para leitura
    arquivo = fopen("image.ppm", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    // Lê o código do formato da imagem (ex: "P3")
    fscanf(arquivo, "%s", code);
    printf("%s\n", code);

    // Lê o número de colunas (largura) da imagem
    fscanf(arquivo, "%d", coluna);
    printf("%d\n", *coluna);

    // Lê o número de linhas (altura) da imagem
    fscanf(arquivo, "%d", linha);
    printf("%d\n", *linha);

    // Lê o valor máximo de cor permitido na imagem
    fscanf(arquivo, "%d", max);
    printf("%d\n", *max);

    // Preenche a matriz de pixels com os dados da imagem (componentes de cor RGB)
    for (i = 0; i < *linha; i++) {
        for (j = 0; j < *coluna; j++) {
            fscanf(arquivo, "%d ", &imagem[i][j].r);
            fscanf(arquivo, "%d ", &imagem[i][j].g);
            fscanf(arquivo, "%d\n", &imagem[i][j].b);
        }
    }

    // Fecha o arquivo após a leitura
    fclose(arquivo);
}

// Salva uma matriz de pixels em um arquivo de imagem no formato PPM
void salvar(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;
    char nome_arq[50];
   
    // Solicita ao usuário o novo nome do arquivo para salvar a imagem
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    // Abre o arquivo no modo de escrita (cria ou sobrescreve o arquivo)
    arquivo = fopen(nome_arq, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    }

    // Escreve o código do formato da imagem no arquivo (ex: "P3")
    fprintf(arquivo, "%s\n", code);

    // Escreve o número de colunas (largura) da imagem no arquivo
    fprintf(arquivo, "%d\n", coluna);

    // Escreve o número de linhas (altura) da imagem no arquivo
    fprintf(arquivo, "%d\n", linha);

    // Escreve o valor máximo de cor permitido na imagem no arquivo
    fprintf(arquivo, "%d\n", max);

    // Preenche o arquivo com os dados da matriz de pixels (componentes de cor RGB)
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", imagem[i][j].r);
            fprintf(arquivo, "%d ", imagem[i][j].g);
            fprintf(arquivo, "%d\n", imagem[i][j].b);
        }
    }

    // Fecha o arquivo após salvar os dados
    fclose(arquivo);
}

// Salva uma matriz de pixels em um arquivo de imagem no formato PPM em tons de cinza
void salvarCinza(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    int media;
    FILE *arquivo;
    char nome_arq[50];

    // Solicita ao usuário o novo nome do arquivo para salvar a imagem
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    // Abre o arquivo no modo de escrita (cria ou sobrescreve o arquivo)
    arquivo = fopen(nome_arq, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    }

    // Escreve o código do formato da imagem no arquivo (ex: "P3")
    fprintf(arquivo, "%s\n", code);

    // Escreve o número de colunas (largura) da imagem no arquivo
    fprintf(arquivo, "%d\n", coluna);

    // Escreve o número de linhas (altura) da imagem no arquivo
    fprintf(arquivo, "%d\n", linha);

    // Escreve o valor máximo de cor permitido na imagem no arquivo
    fprintf(arquivo, "%d\n", max);

    // Preenche o arquivo com os dados da matriz de pixels em tons de cinza (componentes de cor RGB convertidos)
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            // Calcula a média aritmética dos valores R, G e B para obter o tom de cinza
            media = (int) (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b) / 3;
            // Escreve os valores de tom de cinza no arquivo
            fprintf(arquivo, "%d ", media);
            fprintf(arquivo, "%d ", media);
            fprintf(arquivo, "%d\n", media);
        }
    }

    // Fecha o arquivo após salvar os dados
    fclose(arquivo);
}

// Gira uma matriz de pixels 90 graus no sentido anti-horário e salva a imagem em um arquivo de imagem no formato PPM
void girar90grausL(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    // Cria uma matriz auxiliar para armazenar os pixels da imagem após a rotação
    pixel **matAux;
    matAux = (pixel**) malloc(coluna * sizeof(pixel*));
    for (int i = 0; i < coluna; i++) {
        matAux[i] = (pixel*) malloc(linha * sizeof(pixel));
    }

    int linhaAux = 0, colunaAux = 0;

    // Realiza a rotação da imagem 90 graus no sentido anti-horário e armazena na matriz auxiliar matAux
    linhaAux = coluna - 1;
    colunaAux = linha - 1;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            matAux[linhaAux - (coluna - 1)][colunaAux].r = imagem[i][j].r;
            matAux[linhaAux - (coluna - 1)][colunaAux].g = imagem[i][j].g;
            matAux[linhaAux - (coluna - 1)][colunaAux].b = imagem[i][j].b;
            linhaAux++;
        }
        linhaAux = coluna - 1;
        colunaAux--;
    }

    // Solicita ao usuário o novo nome do arquivo para salvar a imagem
    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    // Abre o arquivo no modo de escrita (cria ou sobrescreve o arquivo)
    arquivo = fopen(nome_arq, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    }

    // Escreve o código do formato da imagem no arquivo (ex: "P3")
    fprintf(arquivo, "%s\n", code);

    // Escreve o número de linhas (altura) da imagem no arquivo (após a rotação, linhas se tornam colunas)
    fprintf(arquivo, "%d\n", coluna);

    // Escreve o número de colunas (largura) da imagem no arquivo (após a rotação, colunas se tornam linhas)
    fprintf(arquivo, "%d\n", linha);

    // Escreve o valor máximo de cor permitido na imagem no arquivo
    fprintf(arquivo, "%d\n", max);

    // Preenche o arquivo com os dados da matriz de pixels após a rotação (componentes de cor RGB)
    for (i = 0; i < coluna; i++) {
        for (j = 0; j < linha; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    // Fecha o arquivo após salvar os dados
    fclose(arquivo);

    // Libera a memória alocada para a matriz auxiliar matAux
    for (int i = 0; i < coluna; i++) {
        free(matAux[i]);
    }
    free(matAux);
}

// Função para salvar dados de uma imagem ampliada 2x em um arquivo PPM
void salvarAmpliado(pixel** imagem, char *code, int max, int coluna, int linha) {
    int i, j;
    FILE *arquivo;

    // Cria uma matriz auxiliar para armazenar os pixels da imagem ampliada
    pixel **matAux;
    matAux = (pixel**) malloc((coluna*2) * sizeof(pixel*));
    for (int i = 0; i < (coluna*2); i++) {
        matAux[i] = (pixel*) malloc((linha*2) * sizeof(pixel));
    }

    int linhaAux, colunaAux, x = 0, y = 0;

    // Calcula as dimensões da imagem ampliada
    linhaAux = linha*2;
    colunaAux = coluna*2;

    // Amplia a imagem duplicando os pixels da imagem original na matriz auxiliar matAux
    for (int i = 0; i < linhaAux; i++) {
        for (int j = 0; j < colunaAux; j++) {
            matAux[i][j].r = imagem[x][y].r;
            matAux[i][j].g = imagem[x][y].g;
            matAux[i][j].b = imagem[x][y].b;
            matAux[i+1][j].r = imagem[x][y].r;
            matAux[i+1][j].g = imagem[x][y].g;
            matAux[i+1][j].b = imagem[x][y].b;
            if (j % 2 != 0 && j != 0) {
                y++;
            }
        }
        y = 0;
        i++;
        x++;
    }

    // Solicita ao usuário o novo nome do arquivo para salvar a imagem ampliada
    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    // Abre o arquivo no modo de escrita (cria ou sobrescreve o arquivo)
    arquivo = fopen(nome_arq, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    }

    // Escreve o código do formato da imagem no arquivo (ex: "P3")
    fprintf(arquivo, "%s\n", code);

    // Escreve o número de colunas (largura) da imagem ampliada no arquivo
    fprintf(arquivo, "%d\n", coluna*2);

    // Escreve o número de linhas (altura) da imagem ampliada no arquivo
    fprintf(arquivo, "%d\n", linha*2);

    // Escreve o valor máximo de cor permitido na imagem no arquivo
    fprintf(arquivo, "%d\n", max);

    // Preenche o arquivo com os dados da matriz de pixels ampliada (componentes de cor RGB)
    for (i = 0; i < linha*2; i++) {
        for (j = 0; j < coluna*2; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    // Fecha o arquivo após salvar os dados
    fclose(arquivo);

    // Libera a memória alocada para a matriz auxiliar matAux
    for (int i = 0; i < (coluna*2); i++) {
        free(matAux[i]);
    }
    free(matAux);
}

// Salva uma matriz de pixels reduzida à metade do tamanho em um arquivo de imagem no formato PPM
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

    // Solicita ao usuário o novo nome do arquivo para salvar a imagem reduzida
    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);
    arquivo = fopen(nome_arq, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    }

    // Escreve o código do formato da imagem no arquivo (ex: "P3")
    fprintf(arquivo, "%s\n", code);

    // Escreve o número de colunas (largura) da imagem reduzida no arquivo
    fprintf(arquivo, "%d\n", colunaAux);

    // Escreve o número de linhas (altura) da imagem reduzida no arquivo
    fprintf(arquivo, "%d\n", linhaAux);

    // Escreve o valor máximo de cor permitido na imagem no arquivo
    fprintf(arquivo, "%d\n", max);

    // Preenche o arquivo com os dados da matriz de pixels reduzida (componentes de cor RGB)
    for (i = 0; i < linhaAux; i++) {
        for (j = 0; j < colunaAux; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    // Fecha o arquivo após salvar os dados
    fclose(arquivo);

    // Libera a memória alocada para a matriz auxiliar matAux
    for (i = 0; i < colunaAux; i++) {
        free(matAux[i]);
    }
    free(matAux);
}

// Função para salvar dados de uma imagem com efeito de blurring em um arquivo PPM
void salvarBlurring(pixel** imagem, char *code, int max, int coluna, int linha){
    int i, j, aux;
    FILE *arquivo;

    // Cria a matriz auxiliar matAux para armazenar a imagem com o efeito de desfoque (blurring)
    pixel **matAux;
    matAux = (pixel**)malloc(linha * sizeof(pixel*));
    for (int i = 0; i < linha; i++) {
        matAux[i] = (pixel*)malloc(coluna * sizeof(pixel));
    }

    // Aplica o efeito de desfoque na imagem, calculando a média dos pixels vizinhos de cada pixel
    for (i = 1; i < linha - 1; i++) {
        for (j = 1; j < coluna - 1; j++) {
            aux = (int)((imagem[i-1][j-1].r) + (imagem[i-1][j].r) + (imagem[i-1][j+1].r) +
                        (imagem[i][j-1].r) + (imagem[i+1][j].r) + (imagem[i+1][j-1].r) +
                        (imagem[i+1][j+1].r) + (imagem[i+1][j].r) + (imagem[i][j].r)) / 9;
            if (aux < 0) {
                // Valor mínimo é 0 para o canal de cor vermelho (r)
                // matAux[i][j].r = 0;
            } else {
                matAux[i][j].r = aux;
            }

            aux = (int)((imagem[i-1][j-1].g) + (imagem[i-1][j].g) + (imagem[i-1][j+1].g) +
                        (imagem[i][j-1].g) + (imagem[i+1][j].g) + (imagem[i+1][j-1].g) +
                        (imagem[i+1][j+1].g) + (imagem[i+1][j].g) + (imagem[i][j].g)) / 9;
            if (aux < 0) {
                // Valor mínimo é 0 para o canal de cor verde (g)
                // matAux[i][j].g = 0;
            } else {
                matAux[i][j].g = aux;
            }

            aux = (int)((imagem[i-1][j-1].b) + (imagem[i-1][j].b) + (imagem[i-1][j+1].b) +
                        (imagem[i][j-1].b) + (imagem[i+1][j].b) + (imagem[i+1][j-1].b) +
                        (imagem[i+1][j+1].b) + (imagem[i+1][j].b) + (imagem[i][j].b)) / 9;
            if (aux < 0) {
                // Valor mínimo é 0 para o canal de cor azul (b)
                // matAux[i][j].b = 0;
            } else {
                matAux[i][j].b = aux;
            }
        }
    }

    // Solicita ao usuário o novo nome do arquivo para salvar a imagem com o efeito de desfoque
    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    // Abre o arquivo no modo de escrita (cria ou sobrescreve o arquivo)
    arquivo = fopen(nome_arq, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    }

    // Escreve o código do formato da imagem no arquivo (ex: "P3")
    fprintf(arquivo, "%s\n", code);

    // Escreve o número de colunas (largura) da imagem com o efeito de desfoque no arquivo
    fprintf(arquivo, "%d\n", coluna);

    // Escreve o número de linhas (altura) da imagem com o efeito de desfoque no arquivo
    fprintf(arquivo, "%d\n", linha);

    // Escreve o valor máximo de cor permitido na imagem no arquivo
    fprintf(arquivo, "%d\n", max);

    // Preenche o arquivo com os dados da matriz de pixels com o efeito de desfoque (componentes de cor RGB)
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    // Fecha o arquivo após salvar os dados
    fclose(arquivo);

    // Libera a memória alocada para a matriz auxiliar matAux
    for (i = 0; i < linha; i++) {
        free(matAux[i]);
    }
}

// Função para salvar dados de uma imagem com efeito de sharpening em um arquivo PPM
void salvarSharpening(pixel** imagem, char *code, int max, int coluna, int linha){
    int i, j, aux;
    FILE *arquivo;

    // Cria a matriz auxiliar matAux para armazenar a imagem com o efeito de realce (sharpening)
    pixel **matAux;
    matAux = (pixel**)malloc(linha * sizeof(pixel*));
    for (int i = 0; i < linha; i++) {
        matAux[i] = (pixel*)malloc(coluna * sizeof(pixel));
    }

    // Aplica o efeito de realce (sharpening) na imagem
    for (i = 1; i < linha - 1; i++) {
        for (j = 1; j < coluna - 1; j++) {
            aux = (int)((imagem[i-1][j].r * (-1)) + (imagem[i][j-1].r * (-1)) + (imagem[i+1][j].r * (-1)) +
                        (imagem[i][j+1].r * (-1)) + (imagem[i][j].r * (5)));
            if (aux < 0) {
                matAux[i][j].r = 0;
            } else {
                matAux[i][j].r = aux;
            }

            aux = (int)((imagem[i-1][j].g * (-1)) + (imagem[i][j-1].g * (-1)) + (imagem[i+1][j].g * (-1)) +
                        (imagem[i][j+1].g * (-1)) + (imagem[i][j].g * (5)));
            if (aux < 0) {
                matAux[i][j].g = 0;
            } else {
                matAux[i][j].g = aux;
            }

            aux = (int)((imagem[i-1][j].b * (-1)) + (imagem[i][j-1].b * (-1)) + (imagem[i+1][j].b * (-1)) +
                        (imagem[i][j+1].b * (-1)) + (imagem[i][j].b * (5)));
            if (aux < 0) {
                matAux[i][j].b = 0;
            } else {
                matAux[i][j].b = aux;
            }
        }
    }

    // Solicita ao usuário o novo nome do arquivo para salvar a imagem com o efeito de realce
    char nome_arq[50];
    printf("Novo nome do arquivo: \n");
    scanf("%s", nome_arq);

    // Abre o arquivo no modo de escrita (cria ou sobrescreve o arquivo)
    arquivo = fopen(nome_arq, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    }

    // Escreve o código do formato da imagem no arquivo (ex: "P3")
    fprintf(arquivo, "%s\n", code);

    // Escreve o número de colunas (largura) da imagem com o efeito de realce no arquivo
    fprintf(arquivo, "%d\n", coluna);

    // Escreve o número de linhas (altura) da imagem com o efeito de realce no arquivo
    fprintf(arquivo, "%d\n", linha);

    // Escreve o valor máximo de cor permitido na imagem no arquivo
    fprintf(arquivo, "%d\n", max);

    // Preenche o arquivo com os dados da matriz de pixels com o efeito de realce (componentes de cor RGB)
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", matAux[i][j].r);
            fprintf(arquivo, "%d ", matAux[i][j].g);
            fprintf(arquivo, "%d\n", matAux[i][j].b);
        }
    }

    // Fecha o arquivo após salvar os dados
    fclose(arquivo);

    // Libera a memória alocada para a matriz auxiliar matAux
    for (i = 0; i < linha; i++) {
        free(matAux[i]);
    }
    free(matAux);
}

void ImprimeTelaDeOpcoes() {
    printf("*******************\n");
    printf("Escolha uma opção:\n");
    printf("*******************\n");
    printf("\n");
    printf("gray: Criar imagem em escala de cinza;\n");
    printf("enlarge: Ampliar imagem;\n");
    printf("reduce: Reduzir imagem;\n");
    printf("rotate: Rotacionar 90° em sentido anti-horário;\n");
    printf("blur: Aplicar efeito Blurring;\n");
    printf("sharp: Aplicar efeito Sharpening;\n");
    printf("exit: Sair\n");
}

void EscolheOpcao(char* opcao) {
    scanf("%s", opcao);
}

int main(int argc, char** argv) {
    char opcao[50];
    pixel **imagem; //cria uma matriz de pixeis para armazenar a imagem
    imagem = (pixel**) malloc(MAX*sizeof(pixel*));
    for(int i = 0; i < MAX; i++){
        imagem[i] = (pixel*) malloc(MAX*sizeof(pixel));
    }
    char code[3]; //o código para saber se a imagem é ascii ou binária
    int max; //o valor máximo de tonalidade de cada pixel
    int larg, alt; // largura e altura da imagem em pixeis

    ler(imagem,&code[3],&max,&larg,&alt);

    while (1) {
        ImprimeTelaDeOpcoes();
        EscolheOpcao(opcao); // Chama a função EscolheOpcao() passando o array opcao

        if (strcmp(opcao, "exit") == 0) {
            break; // Sai do loop se a opção for "exit"
        }
        else if (strcmp(opcao, "gray") == 0) {
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
        else if (strcmp(opcao, "sharp") == 0) {
            salvarSharpening(imagem, code, max, larg, alt);
        }
        else if (strcmp(opcao, "blur") == 0) {
            salvarBlurring(imagem, code, max, larg, alt);
        }
        else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }


    // Liberar a memória alocada para a matriz de pixels
    for (int i = 0; i < MAX; i++) {
        free(imagem[i]);
    }
    free(imagem);

    return 0;
}