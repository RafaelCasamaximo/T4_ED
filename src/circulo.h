#ifndef __CIRCULO_H_
#define __CIRCULO_H_

#include "point.h"

typedef void* Circulo;

//Create
//Função responsável para criar Circulo. Retorna um pointer instanciado.
Circulo criaCirculo(char* id, float x, float y, float r, char* cb, char* cp);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void circuloSetId(Circulo circulo, char* id);
void circuloSetX(Circulo circulo, float x);
void circuloSetY(Circulo circulo, float y);
void circuloSetRaio(Circulo circulo, float r);
void circuloSetCorBorda(Circulo circulo, char* cb);
void circuloSetCorPreenchimento(Circulo circulo, char* cp);
void circuloSetPoint(Circulo circulo, Point point);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* circuloGetId(Circulo circulo);
float circuloGetX(Circulo circulo);
float circuloGetY(Circulo circulo);
float circuloGetRaio(Circulo circulo);
char* circuloGetCorBorda(Circulo circulo);
char* circuloGetCorPreenchimento(Circulo circulo);
Point circuloGetPoint(Circulo circulo);

void circuloSwap(Circulo c1, Circulo c2);

void circuloDesenhaSvgGeo(Circulo circulo, void* info);

#endif
