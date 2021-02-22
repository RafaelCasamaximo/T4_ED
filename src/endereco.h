#ifndef __ENDERECO_H
#define __ENDERECO_H

#include "point.h"
#include "quadra.h"

typedef void* Endereco;


Endereco criaEndereco(Quadra quad, char* cpf, char face, int num, char* compl);

void enderecoSetCpf(Endereco endereco, char* cpf);
void enderecoSetPoint(Endereco endereco, Point p);
void enderecoSetFace(Endereco endereco, char face);
void enderecoSetNum(Endereco endereco, int num);
void enderecoSetComplemento(Endereco endereco, char* compl);


char* enderecoGetCpf(Endereco endereco);
Point enderecoGetPoint(Endereco endereco);
char enderecoGetFace(Endereco endereco);
int enderecoGetNum(Endereco endereco);
char* enderecoGetComplemento(Endereco endereco);
void enderecoSwap(Endereco e1, Endereco e2);


#endif