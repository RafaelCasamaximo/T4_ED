#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraEc.h"

void readEc(char* dirEc){
    FILE* fileEc = NULL;
    fileEc = fopen(dirEc, "r");
    if(!fileEc){
        exit(1);
    }
    printf("Arquivo EC aberto com sucesso!");

    //Parametros
    char comando[2], codt[30], descricao[30], cnpj[30], cpf[30], cep[20], face, nome[30];
    int num;

    while(1){
        fscanf(fileEc, "%s", comando);
        
        if(feof(fileEc)){
            break;
        }

        else if(strcmp(comando, "t") == 0){
            fscanf(fileEc, "%s %s", codt, descricao);
        }

        else if(strcmp(comando, "e") == 0){
            fscanf(fileEc, "%s %s %s %s %c %d %s", cnpj, cpf, codt, cep, &face, &num, nome);
        }
    }
    fclose(fileEc);
}
