#ifndef __SORTING_H
#define __SORTING_H

#include "infoSoc.h"
#include "localCasos.h"
#include "doublyLinkedList.h"
#include "point.h"

/*
Algoritmo shellSorting
PRE: vetor de elementos InfoSoc para ser ordenado e o tamanho no vetor
*/
void shellSorting(InfoSoc* vet, int n);

/*
Função que calcula a área de um poligono qualquer
PRE: Lista de vertices do poligono
POS: Área
*/
float obterArea(DoublyLinkedList l);

void quickSortDoublyLinkedList(DoublyLinkedList l, Node primeiro, Node ultimo, Point (*getPoint)(Info), void (*swapInfo)(Info, Info));

Node partition(DoublyLinkedList l, Node primeiro, Node ultimo, Point (*getpoint)(Info), void (*swapInfo)(Info, Info));

int comparar(Point a, Point b, Point c);

int orientacao(Point a, Point b, Point c);


#endif
