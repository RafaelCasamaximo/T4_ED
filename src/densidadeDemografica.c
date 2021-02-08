#include <stdio.h>
#include <stdlib.h>

#include "densidadeDemografica.h"



typedef struct{
    float x, y, w, h, d;
}DensidadeDemograficaStruct;


//Create
DensidadeDemografica criaDensidadeDemografica(float x, float y, float w, float h, float d){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)malloc(sizeof(DensidadeDemograficaStruct));

    dd->x = x;
    dd->y = y;
    dd->w = w;
    dd->h = h;
    dd->d = d;

    return dd;
}


//Setters
void densidadeDemograficaSetX(DensidadeDemografica densidade, float x){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    dd->x = x;
}

void densidadeDemograficaSetY(DensidadeDemografica densidade, float y){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    dd->y = y;
}

void densidadeDemograficaSetWidth(DensidadeDemografica densidade, float w){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    dd->w = w;
}

void densidadeDemograficaSetHeight(DensidadeDemografica densidade, float h){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    dd->h = h;
}

void densidadeDemograficaSetDensidadeDemografica(DensidadeDemografica densidade, float d){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    dd->d = d;
}


//Getters
float densidadeDemograficaGetX(DensidadeDemografica densidade){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    return dd->x;
}

float densidadeDemograficaGetY(DensidadeDemografica densidade){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    return dd->y;
}

float densidadeDemograficaGetWidth(DensidadeDemografica densidade){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;

    return dd->w;
}

float densidadeDemograficaGetHeight(DensidadeDemografica densidade){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;
    
    return dd->h;
}

float densidadeDemograficaGetDensidadeDemografica(DensidadeDemografica densidade){
    DensidadeDemograficaStruct* dd = (DensidadeDemograficaStruct*)densidade;
    
    return dd->d;
}
