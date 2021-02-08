#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "poligono.h"



typedef struct {
    float* x;
    float* y;
    int tamanho;
    char cor[22];

}PoligonoStruct;

Poligono criaPoligono(char cor[], int tamanho){
    PoligonoStruct* polig = (PoligonoStruct*) malloc(sizeof(PoligonoStruct));

    polig->x = (float*)malloc(sizeof(float) * tamanho);
    polig->y = (float*)malloc(sizeof(float) * tamanho);
    strcpy(polig->cor, cor);
    polig->tamanho = tamanho;

    return polig;
}

float poligonoGetX(Poligono poligono, int index){
    PoligonoStruct* polig = (PoligonoStruct*) poligono;

    return polig->x[index];
}

float poligonoGetY(Poligono poligono, int index){
    PoligonoStruct* polig = (PoligonoStruct*) poligono;

    return polig->y[index];
}

char* poligonoGetCor(Poligono poligono){
    PoligonoStruct* polig = (PoligonoStruct*) poligono;

    return polig->cor;
}

int poligonoGetTamanho(Poligono poligono){
    PoligonoStruct* polig = (PoligonoStruct*) poligono;

    return polig->tamanho;
}


void poligonoSetX(Poligono poligono, float x, int index){
    PoligonoStruct* polig = (PoligonoStruct*) poligono;

    polig->x[index] = x;
}

void poligonoSetY(Poligono poligono, float y, int index){
    PoligonoStruct* polig = (PoligonoStruct*) poligono;
    
    polig->y[index] = y;
}

void desalocaXY(Poligono poligono){
    PoligonoStruct* polig = (PoligonoStruct*) poligono;

    free(polig->x);
    free(polig->y);
}