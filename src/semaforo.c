#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semaforo.h"



typedef struct semaforo{ 
    char id[20];
    float x;
    float y;
}SemaforoStruct;


Semaforo criaSemaforo(char* id, float x, float y){
    SemaforoStruct* sem = (SemaforoStruct*) malloc(sizeof(SemaforoStruct));

    strcpy(sem->id, id);
    sem->x = x;
    sem->y = y;

    return sem;
}


//Setters
void semaforoSetId(Semaforo semaforo, char* id){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    strcpy(sem->id, id);
}

void semaforoSetX(Semaforo semaforo, float x){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    
    sem->x = x;
}

void semaforoSetY(Semaforo semaforo, float y){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;

    sem->y = y;
}


//Getters
char* semaforoGetId(Semaforo semaforo){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;

    return sem->id;
}

float semaforoGetX(Semaforo semaforo){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;

    return sem->x;
}

float semaforoGetY(Semaforo semaforo){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;

    return sem->y;
}
