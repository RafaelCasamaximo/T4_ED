#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "radioBase.h"
#include "point.h"

typedef struct radiobase{
    char id[20];
    Point point;
}RadioBaseStruct;


RadioBase criaRadioBase(char* id, float x, float y){
    RadioBaseStruct* radio = (RadioBaseStruct*) malloc(sizeof(RadioBaseStruct));
    Point point = criaPoint(x, y);

    strcpy(radio->id, id);
    radio->point = point;

    return radio;
}


//Setters
void radioBaseSetId(RadioBase radiobase, char* id){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    strcpy(radio->id, id);
}

void radioBaseSetX(RadioBase radiobase, float x){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    setPointX(radio->point, x);
}

void radioBaseSetY(RadioBase radiobase, float y){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;
    
    setPointY(radio->point, y);
}

void radioBaseSetPoint(RadioBase radiobase, Point point){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    free(radio->point);
    radio->point = point;
}

//Getters 
char* radioBaseGetId(RadioBase radiobase){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;   

    return radio->id;
}

float radioBaseGetX(RadioBase radiobase){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    return getPointX(radio->point);
}

float radioBaseGetY(RadioBase radiobase){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase; 

    return getPointY(radio->point);
}

Point radioBaseGetPoint(RadioBase radiobase){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    return radio->point;
}