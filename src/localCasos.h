#ifndef __LOCAL_CASOS_H
#define __LOCAL_CASOS_H

typedef void* LocalCasos; 

//Função responsável para criar LocalCasos. Retorna um pointer instanciado.
LocalCasos criaLocalCasos(int n, int num, char* cep, char face, float x, float y);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
int localCasosGetN(LocalCasos localCasos);
int localCasosGetNum(LocalCasos localCasos);
char* localCasosGetCep(LocalCasos localCasos);
char localCasosGetFace(LocalCasos localCasos);
float localCasosGetX(LocalCasos localCasos);
float localCasosGetY(LocalCasos localCasos);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void localCasosSetN(LocalCasos localCasos, int n);
void localCasosSetNum(LocalCasos localCasos, int num);
void localCasosSetCep(LocalCasos localCasos, char* cep);
void localCasosSetFace(LocalCasos localCasos, char face);
void localCasosSetX(LocalCasos localCasos, float x);
void localCasosSetY(LocalCasos localCasos, float y);

/*
Realiza a troca dos atributos de dois objetos p1 e p2
PRE: Objetos p1 e p2
*/
void swap(LocalCasos* p1, LocalCasos* p2);

#endif