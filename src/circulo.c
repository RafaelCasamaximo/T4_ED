#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circulo.h"
#include "point.h"


typedef struct{
    int id;
    float r;
    Point point;
    char cb[22], cp[22];
}CirculoStruct;


//Create
Circulo criaCirculo(int id, float x, float y, float r, char* cb, char* cp){
    CirculoStruct* circ = (CirculoStruct*)malloc(sizeof(CirculoStruct));
    Point point = criaPoint(x, y);

    circ->id = id;
    circ->point = point;
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

    setPointX(circ->point, x);
}

void circuloSetY(Circulo circulo, float y){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    setPointY(circ->point, y);
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

void circuloSetPonto(Circulo circulo, Point point){
    CirculoStruct* circ = (CirculoStruct*)circulo;
    
    free(circ->point);
    circ->point = point;
}


//Getters
int circuloGetId(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->id;
}

float circuloGetX(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return getPointX(circ->point);
}

float circuloGetY(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return getPointY(circ->point);
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

Point circuloGetPoint(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*)circulo;

    return circ->point;
}