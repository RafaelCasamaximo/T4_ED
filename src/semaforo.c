#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semaforo.h"
#include "point.h"
#include "extraInfoGeo.h"
#include "corPadrao.h"

typedef struct semaforo{ 
    char id[20];
    Point point;
}SemaforoStruct;


//Create
Semaforo criaSemaforo(char* id, float x, float y){
    SemaforoStruct* sem = (SemaforoStruct*) malloc(sizeof(SemaforoStruct));
    strcpy(sem->id, id);
    Point point = criaPoint(x, y);
    sem->point = point;
    return sem;
}

//Setters
void semaforoSetId(Semaforo semaforo, char* id){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    strcpy(sem->id, id);
}

void semaforoSetX(Semaforo semaforo, float x){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    setPointX(sem->point, x);
}

void semaforoSetY(Semaforo semaforo, float y){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    setPointY(sem->point, y);
}

void semaforoSetPoint(Semaforo semaforo, Point point){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    free(sem->point);
    sem->point = point;
}

//Getters
char* semaforoGetId(Semaforo semaforo){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    return sem->id;
}

float semaforoGetX(Semaforo semaforo){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    return getPointX(sem->point);
}

float semaforoGetY(Semaforo semaforo){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    return getPointY(sem->point);
}

Point semaforoGetPoint(Semaforo semaforo){
    SemaforoStruct* sem = (SemaforoStruct*) semaforo;
    return sem->point;
}

void semaforoSwap(Semaforo s1, Semaforo s2){
    SemaforoStruct* a = (SemaforoStruct*) s1;
    SemaforoStruct* b = (SemaforoStruct*) s2;
    SemaforoStruct temp = *a;
    *a = *b;
    *b = temp;
}

void semaforoDesenhaSvgGeo(Semaforo semaforo, void* info){
    fprintf((FILE*)extraInfoGetFileSvgGeo(info), "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", semaforoGetX(semaforo), semaforoGetY(semaforo), coresPadraoGetPreenchimentoSemaforos(extraInfoGetCores(info)), coresPadraoGetBordaSemaforos(extraInfoGetCores(info)), coresPadraoGetEspessuraSemaforos(extraInfoGetCores(info))); //);
}