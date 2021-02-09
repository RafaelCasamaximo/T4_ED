#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linha.h"

typedef struct linha{
    float x1;
    float y1;
    float x2;
    float y2;
    int pntInicial;
    int interna;
    char cep[22];
}LinhaStruct;


//Create
Linha criaLinha(float x1, float y1, float x2, float y2, int pntInicial, int interna, char* cep){
    LinhaStruct* lin = (LinhaStruct*) malloc(sizeof(LinhaStruct));
    lin->x1 = x1;
    lin->y1 = y1;
    lin->x2 = x2;
    lin->y2 = y2;
    lin->pntInicial = pntInicial;
    lin->interna = interna;
    strcpy(lin->cep, cep);
    return lin;
}

//Setters
void linhaSetX1(Linha linha, float x1){
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->x1 = x1;
}

void linhaSetY1(Linha linha, float y1){
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->y1 = y1;
}

void linhaSetX2(Linha linha, float x2){
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->x2 = x2;
}

void linhaSetY2(Linha linha, float y2){
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->y2 = y2;
}

void linhaSetPntInicial(Linha linha, int pntInicial){
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->pntInicial = pntInicial;
}

void linhaSetInterna(Linha linha, int interna){
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->interna = interna;
}

void linhaSetCep(Linha linha, char* cep){
    LinhaStruct* lin = (LinhaStruct*) linha;
    strcpy(lin->cep, cep);
}

//Getters
float linhaGetX1(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->x1;
}

float linhaGetY1(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->y1;
}

float linhaGetX2(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->x2;
}

float linhaGetY2(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->y2;
}

int linhaGetPntInicial(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->pntInicial;
}

int linhaGetInterna(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->interna;
}

char* linhaGetCep(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->cep;
}
