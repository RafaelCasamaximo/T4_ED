#ifndef __ESTABELECIMENTO_H
#define __ESTABELECIMENTO_H

#include "quadra.h"
#include "point.h"

typedef void* Estabelecimento;

/*Create
Função responsável para criar Estabelecimento. 
PRE: 
POS: Retorna um pointer instanciado.
*/
Estabelecimento criaEstabelecimento(Quadra quad, char* cnpj, char* cpf, char* nome, char* codt, char face, int num);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* estabelecimentoGetCep(Estabelecimento estabelecimento);
char* estabelecimentoGetCodt(Estabelecimento estabelecimento);
char* estabelecimentoGetCpf(Estabelecimento estabelecimento);
char* estabelecimentoGetCnpj(Estabelecimento estabelecimento);
char* estabelecimentoGetNome(Estabelecimento estabelecimento);
Point estabelecimentoGetPoint(Estabelecimento estabelecimento);
char estabelecimentoGetFace(Estabelecimento estabelecimento);
int estabelecimentoGetNum(Estabelecimento estabelecimento);

/*
    Troca dois estabelecimentos de lugar na memória
    PRE: estabelecimento 1 e estabelecimento 2
*/
void estabelecimentoSwap(Estabelecimento e1, Estabelecimento e2);

#endif