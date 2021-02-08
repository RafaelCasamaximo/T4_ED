#ifndef __RETANGULO_H_
#define __RETANGULO_H_

typedef void* Retangulo;

//Função responsável para criar Retangulo. Retorna um pointer instanciado.
Retangulo criaRetangulo(int id, int tracejado, float x, float y, float w, float h, char* cb, char* cp);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void retanguloSetId(Retangulo retangulo, int id);
void retanguloSetTracejado(Retangulo retangulo, int tracejado);
void retanguloSetX(Retangulo retangulo, float x);
void retanguloSetY(Retangulo retangulo, float y);
void retanguloSetWidth(Retangulo retangulo, float w);
void retanguloSetHeight(Retangulo retangulo, float h);
void retanguloSetCorBorda(Retangulo retangulo, char* cb);
void retanguloSetCorPreenchimento(Retangulo retangulo, char* cp);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
int retanguloGetId(Retangulo retangulo);
int retanguloGetTracejado(Retangulo retangulo);
float retanguloGetX(Retangulo retangulo);
float retanguloGetY(Retangulo retangulo);
float retanguloGetWidth(Retangulo retangulo);
float retanguloGetHeight(Retangulo retangulo);
char* retanguloGetCorBorda(Retangulo retangulo);
char* retanguloGetCorPreenchimento(Retangulo retangulo);

#endif
