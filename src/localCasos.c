#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "localCasos.h"

typedef struct{
    int n, num;
    char cep[20], face;
    float x, y;
}LocalCasosStruct;


//Create
LocalCasos criaLocalCasos(int n, int num, char* cep, char face, float x, float y){
    LocalCasosStruct* lc = (LocalCasosStruct*) malloc(sizeof(LocalCasosStruct));
    lc->n = n;
    lc->num = num;
    strcpy(lc->cep, cep);
    lc->face = face;
    lc->x = x;
    lc->y = y;
    return lc;
}

//Setters
void localCasosSetN(LocalCasos localCasos, int n){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    lc->n = n;   
}

void localCasosSetNum(LocalCasos localCasos, int num){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    lc->num = num;   
}

void localCasosSetCep(LocalCasos localCasos, char* cep){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    strcpy(lc->cep, cep);   
}

void localCasosSetFace(LocalCasos localCasos, char face){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    lc->face = face;   
}

void localCasosSetX(LocalCasos localCasos, float x){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    lc->x = x;
}

void localCasosSetY(LocalCasos localCasos, float y){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    lc->y = y;
}

//Getters
int localCasosGetN(LocalCasos localCasos){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    return lc->n;   
}

int localCasosGetNum(LocalCasos localCasos){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    return lc->num;   
}

char* localCasosGetCep(LocalCasos localCasos){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    return lc->cep;   
}

char localCasosGetFace(LocalCasos localCasos){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    return lc->face;   
}

float localCasosGetX(LocalCasos localCasos){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    return lc->x;
}

float localCasosGetY(LocalCasos localCasos){
    LocalCasosStruct* lc = (LocalCasosStruct*)localCasos;
    return lc->y;
}

//Swap
void swap(LocalCasos* p1, LocalCasos* p2){  
    LocalCasosStruct* a = (LocalCasosStruct*) p1;
    LocalCasosStruct* b = (LocalCasosStruct*) p2;
    LocalCasosStruct temp = *a;  
    *a = *b;  
    *b = temp;  
}
