#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "texto.h"



typedef struct{
    int id, size;
    float x, y;
    char* txt;
    char cb[22], cp[22];
}TextoStruct;


//Create
Texto criaTexto(int id, int size, float x, float y, char* txt, char* cb, char* cp){
    TextoStruct* tex = (TextoStruct*)malloc(sizeof(TextoStruct));

    tex->id = id;
    tex->x = x;
    tex->y = y;

    strcpy(tex->cb, cb);
    strcpy(tex->cp, cp);
    tex->txt = (char*) malloc(sizeof(char) * size);
    strcpy(tex->txt, txt);

    return tex;
}


//Setters
void textoSetId(Texto texto, int id){
    TextoStruct* tex = (TextoStruct*)texto;

    tex->id = id;
}

void textoSetX(Texto texto, float x){
    TextoStruct* tex = (TextoStruct*)texto;

    tex->x = x;
}

void textoSetY(Texto texto, float y){
    TextoStruct* tex = (TextoStruct*)texto;

    tex->y = y;
}

void textoSetTexto(Texto texto, char* txt, int size){
    TextoStruct* tex = (TextoStruct*) texto;

    free(tex->txt);
    tex->txt = (char*) malloc(sizeof(char) * size);
    strcpy(tex->txt, txt);
}

void textoSetCorBorda(Texto texto, char* cb){
    TextoStruct* tex = (TextoStruct*)texto;

    strcpy(tex->cb, cb);
}

void textoSetCorPreenchimento(Texto texto, char* cp){
    TextoStruct* tex = (TextoStruct*)texto;

    strcpy(tex->cp, cp);
}


//Getters
int textoGetId(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;

    return tex->id;
}

float textoGetX(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;

    return tex->x;
}

float textoGetY(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;

    return tex->y;
}

char* textoGetTexto(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;

    return tex->txt;   
}

char* textoGetCorBorda(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;

    return tex->cb;
}

char* textoGetCorPreenchimento(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;

    return tex->cp;
}


void textoDeletaTxt(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;

    free(tex->txt);
}
