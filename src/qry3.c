#include <stdio.h>
#include <stdlib.h>

#include "qry3.h"
#include "quadTree.h"
#include "quadra.h"
#include "localCasos.h"
#include "doublyLinkedList.h"
#include "sorting.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE, LINHA, LOCALCASOS};

void cv(QuadTree* qt, int casosCovid, char* cep, char face, int num){
    float cx = 0, cy = 0;

    convertLocalCasosToPoint(qt[QUADRA], cep, face, num, &cx, &cy);

    LocalCasos casa = criaLocalCasos(casosCovid, num, cep, face, cx, cy);
    insereQt(qt[LOCALCASOS], localCasosGetPoint(casa), casa);
}

void convertLocalCasosToPoint(QuadTree qt, char* cep, char face, int num, float* cx, float* cy){
    float qx, qy, qw, qh;
    Quadra quadra = getInfoByIdQt(qt, cep);
    if(quadra != NULL){
        qx = quadraGetX(quadra);
        qy = quadraGetY(quadra);
        qw = quadraGetWidth(quadra);
        qh = quadraGetHeight(quadra);
    
        if(face == 'S' || face == 's'){
            *cx = qx + num;
            *cy = qy;
        }
        else if(face == 'N' || face == 'n'){
            *cx = qx + num;
            *cy = qy + qh - 20;
        }
        else if(face == 'L' || face == 'l'){
            *cx = qx;
            *cy = qy + num;
        }
        else if(face == 'O' || face == 'o'){
            *cx = qx + qw - 20;
            *cy = qy + num;
        }
    }
}

void soc(QuadTree* qt, int k, char* cep, char face, int num, FILE* fileTxt){
    float cx, cy;

    DoublyLinkedList lista = create();
    
    //Com um CEP FACE NUM ele calcula a posição X e Y desse endereço
    convertLocalCasosToPoint(qt[QUADRA], cep, face, num, &cx, &cy);

    //Percorre cada um dos nós da arvore da arvore, e para cada nó, inserimos a informação desse nó numa lista criada
    percorreLarguraQt(qt[POSTOSAUDE], convertQtToList, lista);
    //Agora, temos uma lista com todos os postos de saúde
    
    //shellSorting(lista, cx, cy);

    //morador do endereço cap face num precisa de atendimento
    /*
    determinar os k postos de atendimento mais próximos

    //para determinar os k postos de atendimento, precisamos do shellSorting
    //shellSorting(postos de saude, x, y)
    //pode retornar uma lista com linhas do ponto x, y até os k postos de atendimento mais próximos
    
    //A gente adiciona uma variavel na linha chamada tracejado
    //Se tracejado == 1 linha sai tracejado

    //Adiciona todas as linhas na quadTree

    colocar um pequeno quadrado azul com bordas brancas no endereço
    //Retangulo
    */

}

void convertQtToList(Info info, DoublyLinkedList lista){
    insert(lista, info);
}


void ci(){

}