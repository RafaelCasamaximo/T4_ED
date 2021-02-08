#ifndef __UTILITARIO_H
#define __UTILITARIO_H

/*
Calcula a distancia quadrada (entre dois pontos)
Pré: As coordenadas dos dois pontos (x1, y1 e x2, y2)
Pós: Retorna um float referente a distância dos dois pontos
*/
float distanciaQuadrada(float x1, float  y1, float  x2, float  y2);

/*
Calcula a distancia entre dois pontos
PRE: Coordenadas dos dois pontos
POS: distancia
*/
float distanciaEntrePontos(float x1, float  y1, float  x2, float  y2);

//Calcula o min de 2 valores;
//a, b - valores especificados;
int min(int a, int b);

//Calcula o max de 2 valores;
//a, b - valores especificados;
int max(int a, int b);

//Calcula o min de 2 valores;
//a, b - valores especificados;
float minF(float a, float b);

//Calcula o max de 2 valores;
//a, b - valores especificados;
float maxF(float a, float b);

//Calcula o min de um vetor;
float minV(float v[], int tamanho);

//Calcula o max de um vetor;
float maxV(float v[], int tamanho);

#endif
