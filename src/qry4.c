#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qry4.h"
#include "quadTree.h"
#include "hashTable.h"
#include "trataString.h"

void dmprbt(QuadTree* qt, char t, char* sfx, char* dirSaida, char* nomeGeoSemExtensao, char* nomeQrySemExtensao){
    int i;
    switch (t){
    case 'q':
        i = 3;
        break;
    case 'h':
        i = 4;
        break;
    case 's':
        i = 5;
        break;
    case 't':
        i = 6;
        break;
    default:
        break;
    }

    char* nomeGeoQry = NULL;
    char* nomeGeoQrySfx = NULL;
    char* pathDmprbt = NULL;
    concatenaNomeGeoQry(nomeGeoSemExtensao, nomeQrySemExtensao, "", &nomeGeoQry);
    concatenaNomeGeoQry(nomeGeoQry, sfx, ".svg", &nomeGeoQrySfx);
    concatenaCaminhos(dirSaida, nomeGeoQrySfx, &pathDmprbt);

    //Function para imprimir a arvore
    FILE* fileSvgQT = fopen(pathDmprbt, "w");

    desenhaQt(qt[i], fileSvgQT);

    fclose(fileSvgQT);
    free(nomeGeoQry);
    free(nomeGeoQrySfx);
    free(pathDmprbt);

}