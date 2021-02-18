#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linha.h"
#include "point.h"

typedef struct linha{
    Point p1;
    Point p2;
    int pntInicial;
    int interna;
    char cep[22];
}LinhaStruct;


//Create
Linha criaLinha(float x1, float y1, float x2, float y2, int pntInicial, int interna, char* cep){
    LinhaStruct* lin = (LinhaStruct*) malloc(sizeof(LinhaStruct));
    lin->p1 = criaPoint(x1, y1);
    lin->p2 = criaPoint(x2, y2);
    lin->pntInicial = pntInicial;
    lin->interna = interna;
    strcpy(lin->cep, cep);
    return lin;
}

//Setters
void linhaSetX1(Linha linha, float x1){
    LinhaStruct* lin = (LinhaStruct*) linha;
    setPointX(lin->p1, x1);
}

void linhaSetY1(Linha linha, float y1){
    LinhaStruct* lin = (LinhaStruct*) linha;
    setPointY(lin->p1, y1);
}

void linhaSetX2(Linha linha, float x2){
    LinhaStruct* lin = (LinhaStruct*) linha;
    setPointX(lin->p2, x2);
}

void linhaSetY2(Linha linha, float y2){
    LinhaStruct* lin = (LinhaStruct*) linha;
    setPointY(lin->p2, y2);
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

void linhaSetP1(Linha linha, Point p1){
    LinhaStruct* lin = (LinhaStruct*) linha;
    free(lin->p1);
    lin->p1 = p1;
}

void linhaSetP2(Linha linha, Point p2){
    LinhaStruct* lin = (LinhaStruct*) linha;
    free(lin->p2);
    lin->p2 = p2;
}

//Getters
float linhaGetX1(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return getPointX(lin->p1);
}

float linhaGetY1(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return getPointY(lin->p1);
}

float linhaGetX2(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return getPointX(lin->p2);
}

float linhaGetY2(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return getPointY(lin->p2);
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

Point linhaGetP1(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->p1;
}

Point linhaGetP2(Linha linha){
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->p2;
}