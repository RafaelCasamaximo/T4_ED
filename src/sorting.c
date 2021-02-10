#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"
#include "infoSoc.h"
#include "doublyLinkedList.h"
#include "localCasos.h"
#include "utilitario.h"
#include "point.h"
#include "convexHull.h"

void shellSorting(InfoSoc* vet, int n){
    int gap = n / 2;
    while(gap > 0){
        for(int i = gap; i < n; i++){
            InfoSoc temp = vet[i];
            int j = i;
            while(j >= gap && infoSocGetDistancia(vet[j - gap]) > infoSocGetDistancia(temp)){
                vet[j] = vet[j - gap];
                j -= gap;
            }
            vet[j] = temp;
        }
        gap = gap / 2;
    }
}

float obterArea(DoublyLinkedList l){
    float a = 0;
    Info i, j;
    Node node;
    for(node = getFirst(l); getNext(node) != NULL; node = getNext(node)){
        i = getInfo(node);
        j = getInfo(getNext(node));
        a += localCasosGetX(i) * localCasosGetY(j) - localCasosGetY(i) * localCasosGetX(j);
    }
    i = getInfo(node);
    j = getInfo(getFirst(l));
    a += localCasosGetX(i) * localCasosGetY(j) - localCasosGetY(i) * localCasosGetX(j);
    return a / 2;
}

void quickSortDoublyLinkedList(DoublyLinkedList l, Node primeiro, Node ultimo, Point (*getPoint)(Info), void (*swapInfo)(Info, Info)){
    if(ultimo != NULL && primeiro != ultimo && getNext(ultimo) != primeiro){
        Node p = partition(l, primeiro, ultimo, getPoint, swapInfo);
        quickSortDoublyLinkedList(l, primeiro, getPrevious(p), getPoint, swapInfo);
        quickSortDoublyLinkedList(l, getNext(p), ultimo, getPoint, swapInfo);
    }
}

Node partition(DoublyLinkedList l, Node primeiro, Node ultimo, Point (*getPoint)(Info), void (*swapInfo)(Info, Info)){
    Node i = getPrevious(primeiro);
    for(Node j = primeiro; j != ultimo; j = getNext(j)){
        if(comparar(getPoint(getInfo(getFirst(l))), getPoint(getInfo(j)), getPoint(getInfo(ultimo)))){
            i = (i == NULL) ? primeiro : getNext(i);
            swapInfo(getInfo(i), getInfo(j));
        }
    }
    i = (i == NULL) ? primeiro : getNext(i);
    swapInfo(getInfo(i), getInfo(ultimo));
    return i;
}

int comparar(Point a, Point b, Point c){
    int aux = orientacao(a, b, c);

    if(aux == 0){
        return distanciaEntrePontos(getPointX(a), getPointY(a), getPointX(c), getPointY(c)) < distanciaEntrePontos(getPointX(a), getPointY(a), getPointX(b), getPointY(b));
    }
    return aux == 1;
}