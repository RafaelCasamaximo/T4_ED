#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hidrante.h"
#include "point.h"

typedef struct hidrante{
    char id[20];
    Point point;
}HidranteStruct;


Hidrante criaHidrante(char* id, float x, float y){
    HidranteStruct* hid = (HidranteStruct*) malloc(sizeof(HidranteStruct));
    Point point = criaPoint(x, y);
    strcpy(hid->id, id);
    hid->point = point;
    
    return hid;
}


//Setters
void hidranteSetId(Hidrante hidrante, char* id){
    HidranteStruct* hid = (HidranteStruct*) hidrante;

    strcpy(hid->id, id);
}

void hidranteSetX(Hidrante hidrante, float x){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    setPointX(hid->point, x);
}

void hidranteSetY(Hidrante hidrante, float y){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    setPointY(hid->point, y);
}


//Getters
char* hidranteGetId(Hidrante hidrante){
    HidranteStruct* hid = (HidranteStruct*) hidrante;

    return hid->id;
}

float hidranteGetX(Hidrante hidrante){
    HidranteStruct* hid = (HidranteStruct*) hidrante;

    return getPointX(hid->point);
}

float hidranteGetY(Hidrante hidrante){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    
    return getPointY(hid->point);
}

Point hidranteGetPoint(Hidrante hidrante){
    HidranteStruct* hid = (HidranteStruct*) hidrante;

    return hid->point;
}
