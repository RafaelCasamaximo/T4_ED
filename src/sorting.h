#ifndef __SORTING_H
#define __SORTING_H

#include "infoSoc.h"
#include "localCasos.h"
#include "doublyLinkedList.h"

/*
Algoritmo shellSorting
PRE: vetor de elementos InfoSoc para ser ordenado e o tamanho no vetor
*/
void shellSorting(InfoSoc* vet, int n);

/*
Calcula se os pontos estão no sentido horário ou anti-horario
PRE: três pontos para o cálculo
POS: 0: horário/ 1: anti-horario
*/
int orientacao(LocalCasos a, LocalCasos b, LocalCasos c);

/*
Equivalente ao comparator: Compara o conteúdo das variáveis p0, a e b
PRE: Objetos p0, a, b
POS: 1: iguais/ 0: diferentes
*/
int comparar(LocalCasos p0, LocalCasos a, LocalCasos b);

/*
Divide a lista em listas menores para o quicksort
PRE: lista, primeiro e último node
POS: Node da lista
*/
Node partition(DoublyLinkedList l, Node primeiro, Node ultimo);

/*
Algoritmo de quicksort em uma lista
PRE: lista, primeiro elemento e último elemento
*/
void quickSortList(DoublyLinkedList l, Node primeiro, Node ultimo);

/*
Calcula o menor poligono possível a partir de um conjunto de pontos
PRE: lista de pontos
POS: lista de vertices
*/
DoublyLinkedList envoltoriaConvexa(DoublyLinkedList lista);

/*
Função que calcula a área de um poligono qualquer
PRE: Lista de vertices do poligono
POS: Área
*/
float obterArea(DoublyLinkedList l);

#endif
