#ifndef __ESTABELECIMENTO_H
#define __ESTABELECIMENTO_H

#include "quadra.h"
#include "point.h"

typedef void* Estabelecimento;

Estabelecimento criaEstabelecimento(Quadra quad, char* cnpj, char* cpf, char* nome, char* codt, char face, int num);

char* estabelecimentoGetCep(Estabelecimento estabelecimento);
char* estabelecimentoGetCpf(Estabelecimento estabelecimento);
char* estabelecimentoGetCnpj(Estabelecimento estabelecimento);
char* estabelecimentoGetNome(Estabelecimento estabelecimento);
Point estabelecimentoGetPoint(Estabelecimento estabelecimento);
char estabelecimentoGetFace(Estabelecimento estabelecimento);
void estabelecimentoSwap(Estabelecimento e1, Estabelecimento e2);

#endif