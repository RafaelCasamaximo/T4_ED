#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "texto.h"
#include "point.h"

typedef struct{
    char* id[10];
    int size;
    Point point;
    char* txt;
    char cb[22], cp[22];
}TextoStruct;


//Create
Texto criaTexto(char* id, int size, float x, float y, char* txt, char* cb, char* cp){
    TextoStruct* tex = (TextoStruct*)malloc(sizeof(TextoStruct));
    Point point = criaPoint(x, y);
    tex->point = point;
    strcpy(tex->id, id);
    strcpy(tex->cb, cb);
    strcpy(tex->cp, cp);
    tex->txt = (char*) malloc(sizeof(char) * size);
    strcpy(tex->txt, txt);
    return tex;
}


//Setters
void textoSetId(Texto texto, char* id){
    TextoStruct* tex = (TextoStruct*)texto;
    strcpy(tex->id, id);
}

void textoSetX(Texto texto, float x){
    TextoStruct* tex = (TextoStruct*)texto;
    setPointX(tex->point, x);
}

void textoSetY(Texto texto, float y){
    TextoStruct* tex = (TextoStruct*)texto;
    setPointY(tex->point, y);
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

void textoSetPoint(Texto texto, Point point){
    TextoStruct* tex = (TextoStruct*)texto;
    free(tex->point);
    tex->point = point;
}


//Getters
char* textoGetId(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;
    return tex->id;
}

float textoGetX(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;
    return getPointX(tex->point);
}

float textoGetY(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;
    return getPointY(tex->point);
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

Point textoGetPoint(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;
    return tex->point;
}

//Desaloca texto
void textoDeletaTxt(Texto texto){
    TextoStruct* tex = (TextoStruct*)texto;
    free(tex->txt);
}
