#include <stdio.h>
#include <stdlib.h>

#include "infoSoc.h"



typedef struct{
    float xPS, yPS, distancia;
}InfoSocStruct;

InfoSoc criaInfoSoc(float xPS, float yPS, float distancia){
    InfoSocStruct* is = (InfoSocStruct*) malloc(sizeof(InfoSocStruct));

    is->xPS = xPS;
    is->yPS = yPS;
    is->distancia = distancia;

    return is;
}


//Setters
void infoSocSetX(InfoSoc infoSoc, float x){
    InfoSocStruct* is = (InfoSocStruct*) infoSoc;

    is->xPS = x;
}

void infoSocSetY(InfoSoc infoSoc, float y){
    InfoSocStruct* is = (InfoSocStruct*) infoSoc;
    
    is->yPS = y;
}

void infoSocSetDistancia(InfoSoc infoSoc, float distancia){
    InfoSocStruct* is = (InfoSocStruct*) infoSoc;
    
    is->distancia = distancia;
}


//Getters
float infoSocGetX(InfoSoc infoSoc){
    InfoSocStruct* is = (InfoSocStruct*) infoSoc;

    return is->xPS;
}

float infoSocGetY(InfoSoc infoSoc){
    InfoSocStruct* is = (InfoSocStruct*) infoSoc;
    
    return is->yPS;
}

float infoSocGetDistancia(InfoSoc infoSoc){
    InfoSocStruct* is = (InfoSocStruct*) infoSoc;
    
    return is->distancia;
}
