#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quadra.h"

typedef struct quadra{
    char cep[20];
    float x;
    float y;
    float w;
    float h;
    char cb[22];
    char cp[22];
    int arredondado;
}QuadraStruct;


Quadra criaQuadra(char* cep, float x, float y, float w, float h, char* cb, char* cp, int arredondado){
    QuadraStruct* quad = (QuadraStruct*) malloc(sizeof(QuadraStruct));

    strcpy(quad->cep, cep);
    quad->x = x;
    quad->y = y;
    quad->w = w;
    quad->h = h;
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


    quad->x = x;
}

void quadraSetY(Quadra quadra, float y){
    QuadraStruct* quad = (QuadraStruct*) quadra;

    quad->y = y;
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


//Getters
char* quadraGetCep(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;

    return quad->cep;
}

float quadraGetX(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;

    return quad->x;
}

float quadraGetY(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;

    return quad->y;
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
