#ifndef PROJETO_H
#define PROJETO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, g, b;
} pixel;

void ler(pixel** imagem, char *code, int *max, int *coluna, int *linha);
void salvar(pixel** imagem, char *code, int max, int coluna, int linha);
void salvarCinza(pixel** imagem, char *code, int max, int coluna, int linha);

#endif