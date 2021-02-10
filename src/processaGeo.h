#ifndef __PROCESSAGEO_H
#define __PROCESSAGEO_H

#include "quadTree.h"
#include "doublyLinkedList.h"
#include "point.h"

void convertToQuadTrees(QuadTree* quadTrees, DoublyLinkedList* listas);
//Chama a função DoublyLinkedListsToQuadTrees,, que chama DoublyLinkedListToQuadTree para todas as listas, que chama convexHull para todas as listas "recursivamente"

QuadTree DoublyLinkedListToQuadTree(DoublyLinkedList l, QuadTree qt, Point (*getPoint)(void*), void (*swapInfo)(void*,void*));
//Realizar o convexHull com a lista até sobrar três ou menos elementos
//Colocar elementos numa Stack até chegar nessa condição
//Enquanto stackIsEmpty == 0 insertQt

void instanciaQts(QuadTree* quadTrees);
//realiza o comando criaQt(getId) para todas as arvores alocadas menos pra postoSaude


#endif