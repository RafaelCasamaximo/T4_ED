#ifndef __SEMAFORO_H
#define __SEMAFORO_H

#include "point.h"

typedef void* Semaforo; //Cria um tipo Semaforo que guarda void*

//Função responsável para criar Semaforo. Retorna um pointer instanciado.
Semaforo criaSemaforo(char* id, float x, float y, char* cp, char* cb, char* sw); //Cria um novo Semaforo

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void semaforoSetId(Semaforo semaforo, char* id); //Seta um novo valor para o id do Semaforo
void semaforoSetX(Semaforo semaforo, float x);
void semaforoSetY(Semaforo semaforo, float y);
void semaforoSetPoint(Semaforo semaforo, Point point);
void semaforoSetCorPreenchimento(Semaforo semaforo, char* cp);
void semaforoSetCorBorda(Semaforo semaforo, char* cb);
void semaforoSetEspessura(Semaforo semaforo, char* sw);
/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* semaforoGetId(Semaforo semaforo); //Retorna o valor atual do id do Semaforo
float semaforoGetX(Semaforo semaforo);
float semaforoGetY(Semaforo semaforo);
Point semaforoGetPoint(Semaforo semaforo);
char* semaforoGetCorPreenchimento(Semaforo semaforo);
char* semaforoGetCorBorda(Semaforo semaforo);
char* semaforoGetEspessura(Semaforo semaforo);

void semaforoSwap(Semaforo s1, Semaforo s2);

void semaforoDesenhaSvgGeo(Semaforo semaforo, void* fileSvg);

#endif
