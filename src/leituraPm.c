#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quadTree.h"
#include "hashTable.h"
#include "leituraPm.h"

void readPm(QuadTree* qt, HashTable* ht, char* dirPm){
    FILE* filePm = NULL;
    filePm = fopen(dirPm, "r");
    if(!filePm){
        exit(1);
    }
    printf("Arquivo PM aberto com sucesso!");

    //Parametros
    char comando[2], cpf[30], nome[30], sobrenome[30], sexo, nasc[11], cep[20], face, compl[10];
    int num;

    while(1){
        fscanf(filePm, "%s", comando);

        if(feof(filePm)){
            break;
        }

        else if(strcmp(comando, "p") == 0){
            fscanf(filePm, "%s %s %s %c %s", cpf, nome, sobrenome, &sexo, nasc);
        }

        else if(strcmp(comando, "m") == 0){
            fscanf(filePm, "%s %s %c %d %s", cpf, cep, &face, &num, compl);
        }
    }
    fclose(filePm);
}
