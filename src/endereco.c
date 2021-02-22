#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "endereco.h"
#include "point.h"
#include "quadra.h"

typedef struct{
    Point point;
    char cpf[20];
    char cep[20];
    char compl[20];
    char face;
    int numero;
}EnderecoStruct;

Endereco criaEndereco(Quadra quad, char* cpf, char face, int num, char* compl){
    EnderecoStruct* endereco = (EnderecoStruct*) malloc(sizeof(EnderecoStruct));
    float x = quadraGetX(quad);
    float y = quadraGetY(quad);
    float h = quadraGetWidth(quad);
    float w = quadraGetHeight(quad);
    switch (face){
    case 'n':
        x += num;
        y += h;
        break;
    case 's':
        x += num;
        break;
    case 'l':
        y += num;
        break;
    case 'o':
        x += w;
        y += num;
        break;
    }
    strcpy(endereco->cpf, cpf);
    strcpy(endereco->cep, quadraGetCep(quad));
    strcpy(endereco->compl, compl);
    endereco->point = criaPoint(x,y);
    endereco->face = face;
    endereco->numero = num;
    return endereco;
}



void enderecoSetCpf(Endereco endereco, char* cpf) {
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    strcpy(e->cpf, cpf);
}

void enderecoSetPoint(Endereco endereco, Point p) {
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    e->point = p;
}

void enderecoSetFace(Endereco endereco, char face) {
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    e->face = face;
}

void enderecoSetNum(Endereco endereco, int num) {
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    e->numero = num;
}

void enderecoSetComplemento(Endereco endereco, char* compl) {
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    strcpy(e->compl, compl);
}



char* enderecoGetCpf(Endereco endereco){
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    return e->cpf;
}

Point enderecoGetPoint(Endereco endereco){
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    return e->point;
}

char enderecoGetFace(Endereco endereco){
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    return e->face;
}

int enderecoGetNum(Endereco endereco){
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    return e->numero;
}

char* enderecoGetComplemento(Endereco endereco) {
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    return e->compl;
}

char* enderecoGetCep(Endereco endereco){
    EnderecoStruct* e = (EnderecoStruct*) endereco;
    return e->cep;
}

void enderecoSwap(Endereco e1, Endereco e2){  
    EnderecoStruct* a = (EnderecoStruct*) e1;
    EnderecoStruct* b = (EnderecoStruct*) e2;
    EnderecoStruct temp = *a;  
    *a = *b;  
    *b = temp;  
}


