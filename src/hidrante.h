#ifndef __HIDRANTE_H
#define __HIDRANTE_H

#include "point.h"

typedef void* Hidrante;

//Função responsável para criar Hidrante. Retorna um pointer instanciado.
Hidrante criaHidrante(char* id, float x, float y, char* cp, char* cb, char* sw);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void hidranteSetId(Hidrante hidrante, char* id);
void hidranteSetX(Hidrante hidrante, float x);
void hidranteSetY(Hidrante hidrante, float y);
void hidranteSetPoint(Hidrante hidrante, Point point);
void hidranteSetCorPreenchimento(Hidrante hidrante, char* cp);
void hidranteSetCorBorda(Hidrante hidrante, char* cb);
void hidranteSetEspessura(Hidrante hidrante, char* sw);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* hidranteGetId(Hidrante hidrante);
float hidranteGetX(Hidrante hidrante);
float hidranteGetY(Hidrante hidrante);
Point hidranteGetPoint(Hidrante hidrante);
char* hidranteGetCorPreenchimento(Hidrante hidrante);
char* hidranteGetCorBorda(Hidrante hidrante);
char* hidranteGetEspessura(Hidrante hidrante);

void hidranteSwap(Hidrante h1, Hidrante h2);

void hidranteDesenhaSvgGeo(Hidrante hidrante, void* fileSvg);

#endif
