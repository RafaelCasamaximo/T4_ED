#include <stdio.h>
#include <stdlib.h>

#include "quadTree.h"
#include "svg.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "linha.h"
#include "corPadrao.h"
#include "localCasos.h"
#include "postoSaude.h"
#include "poligono.h"


enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE};

void desenhaSvgGeo(QuadTree* qt, char* dirSaida){

    FILE* fileSvgGeo = NULL;
    fileSvgGeo = fopen(dirSaida, "w");
    if(!fileSvgGeo){
        exit(1);
    }
    printf("Arquivo SVG GEO criado com sucesso!");
    fprintf(fileSvgGeo, "<svg>");

    percorreLarguraQt(qt[0], circuloDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[1], retanguloDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[2], textoDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[3], quadraDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[4], hidranteDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[5], semaforoDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[6], radioBaseDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[7], postoSaudeDesenhaSvgGeo, fileSvgGeo);

    fprintf(fileSvgGeo, "\n</svg>");
    fclose(fileSvgGeo);
}


// void DesenhaSvgQry(DoublyLinkedList* listas, CorPadrao cores, char* dirSaida){
//     FILE* fileSvgQry = NULL;
//     fileSvgQry = fopen(dirSaida, "w");
//     if(!fileSvgQry){
//         exit(1);
//     }
//     printf("Arquivo SVG QRY criado com sucesso!");
//     fprintf(fileSvgQry, "<svg>");

//     fprintf(fileSvgQry, "\n</svg>");
//     fclose(fileSvgQry);
// }
