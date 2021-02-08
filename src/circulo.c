#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circulo.h"



typedef struct{
    int id;
    float x, y, r;
    char cb[22], cp[22];
}CirculoStruct;


//Create
Circulo criaCirculo(int id, float x, float y, float r, char* cb, char* cp){
    CirculoStruct* circ = (CirculoStruct*)malloc(sizeof(CirculoStruct));

    circ->id = id;
    circ->x = x;
    circ->y = y;
    circ->r = r;
    strcpy(circ->cb, cb);
    strcpy(circ->cp, cp);

    return circ;
}


//Setters
void circuloSetId(Circulo circulo, int id){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    circ->id = id;
}

void circuloSetX(Circulo circulo, float x){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    circ->x = x;
}

void circuloSetY(Circulo circulo, float y){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    circ->y = y;
}

void circuloSetRaio(Circulo circulo, float r){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    circ->r = r;
}

void circuloSetCorBorda(Circulo circulo, char* cb){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    strcpy(circ->cb, cb);
}

void circuloSetCorPreenchimento(Circulo circulo, char* cp){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    strcpy(circ->cp, cp);
}


//Getters
int circuloGetId(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->id;
}

float circuloGetX(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->x;
}

float circuloGetY(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->y;
}

float circuloGetRaio(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->r;
}

char* circuloGetCorBorda(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->cb;
}

char* circuloGetCorPreenchimento(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->cp;
}
