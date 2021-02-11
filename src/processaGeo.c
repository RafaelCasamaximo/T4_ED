#include <stdio.h>
#include <stdlib.h>

#include "processaGeo.h"
#include "quadTree.h"
#include "doublyLinkedList.h"
#include "stack.h"
#include "point.h"
#include "convexHull.h"

#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "postoSaude.h"
#include "densidadeDemografica.h"


//Enumeration para todas as listas utilizadas
enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE};

void instanciaQts(QuadTree* quadTrees){
    //Define uma quadtree para cada figura ou instrumento e passa a função
    quadTrees[0] = criaQt(circuloGetId);
    quadTrees[1] = criaQt(retanguloGetId);
    quadTrees[2] = criaQt(textoGetId);
    quadTrees[3] = criaQt(quadraGetCep);
    quadTrees[4] = criaQt(hidranteGetId);
    quadTrees[5] = criaQt(semaforoGetId);
    quadTrees[6] = criaQt(radioBaseGetId);
    quadTrees[7] = criaQt(NULL);

}

void convertToQuadTrees(QuadTree* quadTrees, DoublyLinkedList* listas){
    //Converte cada Lista individualmente para uma quadtree e salva no index certo
    DoublyLinkedListToQuadTree(listas[0], quadTrees[0], circuloGetPoint, circuloSwap);
    DoublyLinkedListToQuadTree(listas[1], quadTrees[1], retanguloGetPoint, retanguloSwap);
    DoublyLinkedListToQuadTree(listas[2], quadTrees[2], textoGetPoint, textoSwap);
    DoublyLinkedListToQuadTree(listas[3], quadTrees[3], quadraGetPoint, quadraSwap);
    DoublyLinkedListToQuadTree(listas[4], quadTrees[4], hidranteGetPoint, hidranteSwap);
    DoublyLinkedListToQuadTree(listas[5], quadTrees[5], semaforoGetPoint, semaforoSwap);
    DoublyLinkedListToQuadTree(listas[6], quadTrees[6], radioBaseGetPoint, radioBaseSwap);
    DoublyLinkedListToQuadTree(listas[7], quadTrees[7], postoSaudeGetPoint, postoSaudeSwap);
}

QuadTree DoublyLinkedListToQuadTree(DoublyLinkedList l, QuadTree qt, Point (*getPoint)(void*), void (*swapInfo)(void*,void*)){
    //Essa função realiza o convexhull com a lista até sobrar menos de 3 pontos. Após realizar o convexHull cada convex hull salva o resultado numa stack (realiza o procesimento até que não tenha mais pontos)
    //Após isso, enquanto há elementos na stack criada como resultado do convexhull, adiciona na quadtree na ordem certa
    DoublyLinkedList conHull;
    Stack stack = createStack();
    while(getSize(l) > 3){
        conHull = convexHull(l, getPoint, swapInfo);
        if(conHull != NULL){
            for(Node i = getFirst(conHull); i != NULL; i = getNext(i)){
                for(Node j = getFirst(l); j != NULL; j = getNext(j)){
                    //Pega as informações
                    Info infoJ = getInfo(j);
                    Info infoI = getInfo(i);
                    //Pega o ponto do infoJ
                    Point pontoJ = getPoint(infoJ);
                    //Se forem iguais, é o mesmo elemento na envoltória convexa e na lista, o que significa que podemos retirar de lista e colocar na pilha pra adicionar na quadTree depois
                    if(pontoJ == infoI){
                        pushStack(stack, infoJ);
                        //Retira da lista porem sem desalocar a Info (flag 0), pois é a mesma info que agora está na stack (infoJ)
                        removeNode(l, j, 0);
                        //Se encontrar o elemento equivalente quebra o laço
                        break;
                    }
                }
            }
            //Remove a lista, porém sem desalocar as infos, pois eles estão na stack agora
            removeList(conHull, 0);
        }
    }

    //Caso tenha sobrado mais elementos na lista que não se encaixaram no convex hull (esse elementos podem ser no máximo 3) adiciona eles agora na stack
    for(Node i = getFirst(l); i != NULL; i = getNext(i)){
        Info infoI = getInfo(i);
        pushStack(stack, infoI);
    }
    while(!isEmptyStack(stack)){
        //Pega o elemento do topo
        Info aux = topStack(stack);
        //Retira da stack, porém, sem desalocar Info
        popStack(stack, 0);
        insereQt(qt, getPoint(aux), aux);
    }
    //Desaloca a variável da stack (nesse ponto ela já vai estar vazia, porém, como a função encapsula o free não tem problema usar)
    removeStack(stack, 0);
    return conHull;
}
