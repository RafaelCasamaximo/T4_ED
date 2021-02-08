#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "radioBase.h"



typedef struct radiobase{
    char id[20];
    float x;
    float y;
}RadioBaseStruct;


RadioBase criaRadioBase(char* id, float x, float y){
    RadioBaseStruct* radio = (RadioBaseStruct*) malloc(sizeof(RadioBaseStruct));

    strcpy(radio->id, id);
    radio->x = x;
    radio->y = y;

    return radio;
}


//Setters
void radioBaseSetId(RadioBase radiobase, char* id){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    strcpy(radio->id, id);
}

void radioBaseSetX(RadioBase radiobase, float x){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    radio->x = x;
}

void radioBaseSetY(RadioBase radiobase, float y){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;
    
    radio->y = y;
}


//Getters 
char* radioBaseGetId(RadioBase radiobase){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;   

    return radio->id;
}

float radioBaseGetX(RadioBase radiobase){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase;

    return radio->x;
}

float radioBaseGetY(RadioBase radiobase){
    RadioBaseStruct* radio = (RadioBaseStruct*) radiobase; 

    return radio->y;
}
