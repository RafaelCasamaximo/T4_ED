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

#include "extraInfoGeo.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE};

void DesenhaSvgGeo(QuadTree* qt, CorPadrao cores, char* dirSaida){

    FILE* fileSvgGeo = NULL;
    fileSvgGeo = fopen(dirSaida, "w");
    if(!fileSvgGeo){
        exit(1);
    }
    printf("Arquivo SVG GEO criado com sucesso!");
    fprintf(fileSvgGeo, "<svg>");

    ExtraInfoGeo info = criaExtraInfoGeo(fileSvgGeo, cores);

    percorreLarguraQt(qt[0], circuloDesenhaSvgGeo, info);
    percorreLarguraQt(qt[1], retanguloDesenhaSvgGeo, info);
    percorreLarguraQt(qt[2], textoDesenhaSvgGeo, info);
    percorreLarguraQt(qt[3], quadraDesenhaSvgGeo, info);
    percorreLarguraQt(qt[4], hidranteDesenhaSvgGeo, info);
    percorreLarguraQt(qt[5], semaforoDesenhaSvgGeo, info);
    percorreLarguraQt(qt[6], radioBaseDesenhaSvgGeo, info);
    percorreLarguraQt(qt[7], postoSaudeDesenhaSvgGeo, info);

    fprintf(fileSvgGeo, "\n</svg>");
    fclose(fileSvgGeo);

    free(info);
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
