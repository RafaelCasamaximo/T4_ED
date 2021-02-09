#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"
#include "infoSoc.h"
#include "doublyLinkedList.h"
#include "localCasos.h"
#include "utilitario.h"

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


int orientacao(LocalCasos a, LocalCasos b, LocalCasos c){
    float area = (localCasosGetX(b) - localCasosGetX(a)) * (localCasosGetY(c) - localCasosGetY(a)) - (localCasosGetY(b) - localCasosGetY(a)) * (localCasosGetX(c) - localCasosGetX(a));
    if(area > 1){
        return 1;
    }
    if(area < 1){
        return -1;
    }
    return 0;
}


int comparar(LocalCasos p0, LocalCasos a, LocalCasos b){
    int aux = orientacao(p0, a, b);
    if(aux == 0){
        return distanciaEntrePontos(localCasosGetX(p0), localCasosGetY(p0),localCasosGetX(b), localCasosGetY(b)) < distanciaEntrePontos(localCasosGetX(p0), localCasosGetY(p0), localCasosGetX(a), localCasosGetY(a));
    }
    return aux == 1;
}


Node partition(DoublyLinkedList l, Node primeiro, Node ultimo){
    Node i = getPrevious(primeiro);
    for(Node j = primeiro; j != ultimo; j = getNext(j)){
        if(comparar(getInfo(getFirst(l)), getInfo(j), getInfo(ultimo))){
            i = (i == NULL) ? primeiro : getNext(i); 
            swap(getInfo(i), getInfo(j));
        }
    }

    i = (i == NULL) ? primeiro : getNext(i); 
    swap(getInfo(i), getInfo(ultimo));
    return i; 
}


void quickSortList(DoublyLinkedList l, Node primeiro, Node ultimo){
    if(ultimo != NULL && primeiro != NULL && getNext(ultimo) != primeiro){
        Node p = partition(l, primeiro, ultimo);
        quickSortList(l, primeiro,getPrevious(p));
        quickSortList(l, getNext(p),ultimo);
    }
}


DoublyLinkedList envoltoriaConvexa(DoublyLinkedList lista){
    Node primeiro = getFirst(lista);
    Node i = NULL;

    LocalCasos p2 = NULL;
    LocalCasos p1 = getInfo(primeiro);

    for(i = getNext(primeiro); i != NULL; i = getNext(i)){
        p2 = getInfo(i);
        if(localCasosGetY(p2) < localCasosGetY(p1) || (localCasosGetY(p2) == localCasosGetY(p1) && localCasosGetX(p2) < localCasosGetX(p1))){
            p1 = p2;
        }
    }

    swap(getInfo(primeiro), p1);
    quickSortList(lista, getNext(primeiro), getLast(lista));

    int j = 1;

    for(i = getNext(getNext(primeiro)); i != NULL; i = getNext(i)){

        p1 = getInfo(i);
        p2 = getInfo(getPrevious(i));

        if(orientacao(getInfo(primeiro), p1, p2) == 0){
            removeNode(lista, getPrevious(i), 1);
        }
        else{
            j++;
        }
    }
    if(j < 3){
        return NULL;
    }
    
    DoublyLinkedList envConv = create();
    for(i = primeiro, j = 0; j < 3; j++, i = getNext(i)){
        insert(envConv, getInfo(i));
    }
    while(i != NULL){
        while(orientacao(getInfo(getPrevious(getLast(envConv))), getInfo(getLast(envConv)), getInfo(i)) != 1){
           removeNode(envConv, getLast(envConv), 1);
        }
        insert(envConv, getInfo(i));
        i = getNext(i);
    }
    return envConv;
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
