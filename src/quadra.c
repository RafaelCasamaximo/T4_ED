#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "point.h"
#include "quadra.h"

typedef struct quadra{
    char cep[20];
    Point point;
    float w;
    float h;
    float dd;
    char cb[22];
    char cp[22];
    int arredondado;
}QuadraStruct;


//Create
Quadra criaQuadra(char* cep, float x, float y, float w, float h, char* cb, char* cp, int arredondado){
    QuadraStruct* quad = (QuadraStruct*) malloc(sizeof(QuadraStruct));
    Point point = criaPoint(x, y);
    strcpy(quad->cep, cep);
    quad->point = point;
    quad->w = w;
    quad->h = h;
    quad->dd = 0;
    strcpy(quad->cb, cb);
    strcpy(quad->cp, cp);
    quad->arredondado = arredondado;
    return quad; 
}

//Setters
void quadraSetCep(Quadra quadra, char* cep){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cep, cep);
}

void quadraSetX(Quadra quadra, float x){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    setPointX(quad->point, x);
}

void quadraSetY(Quadra quadra, float y){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    setPointY(quad->point, y);
}

void quadraSetWidth(Quadra quadra, float w){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->w = w;
}

void quadraSetHeight(Quadra quadra, float h){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->h = h;
}

void quadraSetCorBorda(Quadra quadra, char* cb){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cb, cb);
}

void quadraSetCorPreenchimento(Quadra quadra, char* cp){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cp, cp);
}

void quadraSetArredondado(Quadra quadra, int arredondado){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->arredondado = arredondado;
}

void quadraSetPoint(Quadra quadra, Point point){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    free(quad->point);
    quad->point = point;
}

void quadraSetDensidadeDemografica(Quadra quadra, float dd){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->dd = dd;
}

//Getters
char* quadraGetCep(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cep;
}

float quadraGetX(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return getPointX(quad->point);
}

float quadraGetY(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return getPointY(quad->point);
}

float quadraGetWidth(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->w;
}

float quadraGetHeight(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->h;
}

char* quadraGetCorBorda(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cb;
}

char* quadraGetCorPreenchimento(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cp;
}

int quadraGetArredondado(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->arredondado;
}

float quadraGetArea(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return (quad->w * quad->h);
}

Point quadraGetPoint(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->point;
}

float quadraGetDensidadeDemografica(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->dd;
}

void quadraSwap(Quadra q1, Quadra q2){
    QuadraStruct* a = (QuadraStruct*) q1;
    QuadraStruct* b = (QuadraStruct*) q2;
    QuadraStruct temp = *a;
    *a = *b;
    *b = temp;
}
