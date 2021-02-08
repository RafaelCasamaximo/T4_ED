#ifndef __INFOSOC_H
#define __INFOSOC_H

typedef void* InfoSoc;

//Função responsável para criar InfoSoc. Retorna um pointer instanciado.
InfoSoc criaInfoSoc(float xPS, float yPS, float distancia);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void infoSocSetX(InfoSoc infoSoc, float x);
void infoSocSetY(InfoSoc infoSoc, float y);
void infoSocSetDistancia(InfoSoc infoSoc, float distancia);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
float infoSocGetX(InfoSoc infoSoc);
float infoSocGetY(InfoSoc infoSoc);
float infoSocGetDistancia(InfoSoc infoSoc);

#endif
