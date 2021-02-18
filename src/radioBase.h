#ifndef __RADIOBASE_H
#define __RADIOBASE_H

#include "point.h"

typedef void* RadioBase;

// Função responsável para criar RadioBase. Retorna um pointer instanciado.
RadioBase criaRadioBase(char* id, float x, float y, char* cp, char* cb, char* sw);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void radioBaseSetId(RadioBase radiobase, char* id);
void radioBaseSetX(RadioBase radiobase, float x);
void radioBaseSetY(RadioBase radiobase, float y);
void radioBaseSetPoint(RadioBase radiobase, Point point);
void radioBaseSetCorPreenchimento(RadioBase radiobase, char* cp);
void radioBaseSetCorBorda(RadioBase radiobase, char* cb);
void radioBaseSetEspessura(RadioBase radiobase, char* sw);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* radioBaseGetId(RadioBase radiobase);
float radioBaseGetX(RadioBase radiobase);
float radioBaseGetY(RadioBase radiobase);
Point radioBaseGetPoint(RadioBase radiobase);
char* radioBaseGetCorPreenchimento(RadioBase radiobase);
char* radioBaseGetCorBorda(RadioBase radiobase);
char* radioBaseGetEspessura(RadioBase radiobase);

/*
    Troca duas radiobases de lugar na memória
    PRE: rb1 e rb2
*/
void radioBaseSwap(RadioBase rb1, RadioBase rb2);

/*
    Escreve uma tag SVG da radioBase no file passado
    PRE: radioBase e file
*/
void radioBaseDesenhaSvgGeo(RadioBase radiobase, void* fileSvg);

#endif
