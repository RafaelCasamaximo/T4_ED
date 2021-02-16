#ifndef LEITURAQRY__H_
#define LEITURAQRY__H_

#include "quadTree.h"
#include "corPadrao.h"

/*
Lê as consultas requisitadas no arquivo QRY
Pré: As listas e o diretório do arquivo QRY
*/
void readQry(QuadTree* qt, char* dirQry, char* dirTxt);

#endif
