#ifndef __SVG_H
#define __SVG_H

#include "quadTree.h"
#include "corPadrao.h"

/*
DesenhaSvgGeo o arquivo SVG do GEO
Pré: As listas, as cores dos elementos e o caminho onde será criada as saídas
*/
void DesenhaSvgGeo(QuadTree* qt, CorPadrao cores, char* dirSaida);

/*
DesenhaSvgGeo o arquivo SVG do QRY
Pré: As listas, as cores dos elementos e o caminho onde será criada as saídas
*/
void DesenhaSvgQry(DoublyLinkedList* listas, CorPadrao cores, char* dirSaida);

#endif
