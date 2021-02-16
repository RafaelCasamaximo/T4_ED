#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qry1.h"
#include "quadTree.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "utilitario.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE};

//T1
int inside(QuadTree* qt, char* j, float x, float y, float* centroMassaX, float* centroMassaY, FILE* fileTxt){

    Circulo circulo =  getInfoByIdQt(qt[CIRCULO], j);
    Retangulo retangulo = getInfoByIdQt(qt[RETANGULO], j);

    fprintf(fileTxt, "i? %s %f %f\n", j, x, y);

    int isInside = 0;

    if(!circulo){
        *centroMassaX = circuloGetX(circulo);
        *centroMassaY = circuloGetY(circulo);
        isInside = insideCirculo(x, y, circuloGetX(circulo), circuloGetY(circulo), circuloGetRaio(circulo));
        fprintf(fileTxt, "CIRCULO %s\n\n", isInside == 1 ? "CONTÉM" : "NÃO CONTÉM");
    }
    else if(!retangulo){
        *centroMassaX = retanguloGetX(retangulo) + (retanguloGetWidth(retangulo) / 2);
        *centroMassaY = retanguloGetY(retangulo) + (retanguloGetHeight(retangulo) / 2);
        isInside = insideRetangulo(x, y, retanguloGetX(retangulo), retanguloGetY(retangulo), retanguloGetWidth(retangulo), retanguloGetHeight(retangulo));
        fprintf(fileTxt, "RETANGULO %s\n\n", isInside == 1 ? "CONTÉM" : "NÃO CONTÉM");
    }

    return isInside;
}

/* inside
x, y = ponto
j = id da figura
getInfoById -> achar a figura
percorrer a qt de circulo e a de retangulo ate achar o id
ver se x,y estao dentro da figura -> inside
*/

void pnt(QuadTree* qt, char* j, char* cb, char* cp, FILE* fileTxt){
    Circulo circulo = getInfoByIdQt(qt[CIRCULO], j);
    Retangulo retangulo = getInfoByIdQt(qt[RETANGULO], j);
    Texto texto = getInfoByIdQt(qt[TEXTO], j);

    fprintf(fileTxt, "pnt %s %s %s", j, cb, cp);

    if(!circulo){
        circuloSetCorBorda(circulo, cb);
        circuloSetCorPreenchimento(circulo, cp);
        fprintf(fileTxt, "CIRCULO X: %f Y: %f", circuloGetX(circulo), circuloGetY(circulo));
    }
    else if(!retangulo){
        retanguloSetCorBorda(retangulo, cb);
        retanguloSetCorPreenchimento(retangulo, cp);
        fprintf(fileTxt, "RETANGULO X: %f Y: %f", retanguloGetX(retangulo), retanguloGetY(retangulo));
    }
    else if(!texto){
        textoSetCorBorda(texto, cb);
        textoSetCorPreenchimento(texto, cp);
        fprintf(fileTxt, "TEXTO X: %f Y: %f", textoGetX(texto), textoGetY(texto));
    }
}

void delf(QuadTree* qt, char* j, FILE* fileTxt){
    Circulo circulo = getInfoByIdQt(qt[CIRCULO], j);
    Retangulo retangulo = getInfoByIdQt(qt[RETANGULO], j);
    Texto texto = getInfoByIdQt(qt[TEXTO], j);

    fprintf(fileTxt, "delf %s", j);

    if(!circulo){
        circulo = removeNoQt(qt, getNoQt(qt, circuloGetX(circulo), circuloGetY(circulo)));
        free(circuloGetPoint(circulo));
        free(circulo);
        
    }
    else if(!retangulo){
        retangulo = removeNoQt(qt, getNoQt(qt, retanguloGetX(retangulo), retanguloGetY(retangulo)));
        free(retanguloGetPoint(retangulo));
        free(retangulo);
    }
    else if(!texto){
        texto = removeNoQt(qt, getNoQt(qt, textoGetX(texto), textoGetY(texto)));
        free(textoGetPoint(texto));
        free(texto);
    }

}