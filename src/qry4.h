#ifndef __QRY4_H
#define __QRY4_H

#include "quadTree.h"
#include "hashTable.h"

void m(QuadTree* qt, HashTable* ht, char* cep, FILE* fileTxt);

void dm(QuadTree* qt, HashTable* ht, char* cpf, FILE* fileTxt);

void de(QuadTree* qt, HashTable* ht, char* cnpj, FILE* fileTxt);

void mud(QuadTree* qt, HashTable* ht, char* cpf, char* cep, char face, int num, char* compl, FILE* fileTxt);

void dmprbt(QuadTree* qt, char t, char* sfx, char* dirSaida, char* nomeGeoSemExtensao, char* nomeQrySemExtensao);

void eplg(QuadTree* qt, HashTable* ht, char* tp, float x, float y, float w, float h, FILE* fileTxt);

void catac(QuadTree* qt, HashTable* ht, float x, float y, float r, FILE* fileTxt);

#endif