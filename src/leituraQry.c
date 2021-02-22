#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraQry.h"
#include "quadTree.h"
#include "linha.h"
#include "retangulo.h"
#include "qry1.h"
#include "qry2.h"
#include "qry3.h"
#include "qry4.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE, LINHA};

void readQry(QuadTree* qt, char* dirQry, char* dirTxt, char* dirSaida, char* nomeGeoSemExtensao, char* nomeQrySemExtensao){

    FILE* fileTxt = NULL;
    fileTxt = fopen(dirTxt, "w");
    if(!fileTxt){
        exit(1);
    }
    printf("Arquivo TXT aberto com sucesso!");

    FILE* fileQry = NULL;
    fileQry = fopen(dirQry, "r");
    if(!fileQry){
        exit(1);
    }
    printf("Arquivo QRY aberto com sucesso!");

    
    char j[10], k[10], comando[6], cb[22], cp[22], cep[20], face, t, sfx[20];
    int casosCovid = 0, n = 0, num = 0, interno = 0, sobrepoe = 0;
    float x = 0, y = 0, w = 0, h = 0, r = 0, centroDeMassaX = 0, centroDeMassaY = 0; 

    Linha linhaAux = NULL;
    Retangulo retanguloAux = NULL;

    while(1){
        fscanf(fileQry, "%s", comando);
        if(feof(fileQry)){
            break;
        }
        

        //T1_ED
        //o?
        if(strcmp(comando, "o?") == 0){
            fscanf(fileQry, "%s %s", j, k);
            sobrepoe = overlay(qt, j, k, &x, &y, &w, &h, fileTxt);
            if(sobrepoe == 0){
                retanguloAux = criaRetangulo("0", 1, x, y, w, h, "black", "none", "2px");
                insereQt(qt[1], retanguloGetPoint(retanguloAux), retanguloAux);
            }
            if(sobrepoe == 1){
                retanguloAux = criaRetangulo("0", 0, x, y, w, h, "black", "none", "2px");
                insereQt(qt[1], retanguloGetPoint(retanguloAux), retanguloAux);
            }
        }
        //i?        
        if(strcmp(comando, "i?") == 0){
            fscanf(fileQry, "%s %f %f", j, &x, &y);
            interno = inside(qt, j, x, y, &centroDeMassaX, &centroDeMassaY, fileTxt);
            if(interno == 1){ //Dentro
                linhaAux = criaLinha(x, y, centroDeMassaX, centroDeMassaY, 1, 1, "-1");
                insereQt(qt[8], linhaGetP1(linhaAux), linhaAux);
            }
            else if(interno == 0){ //Fora ou borda
                linhaAux = criaLinha(x, y, centroDeMassaX, centroDeMassaY, 1, 0, "-1");
                insereQt(qt[8], linhaGetP1(linhaAux), linhaAux);
            }
        }
        //pnt
        if(strcmp(comando, "pnt") == 0){
            fscanf(fileQry, "%s %s %s", j, cb, cp);
            pnt(qt, j, cb, cp, fileTxt);
        }
        //pnt*
        if(strcmp(comando, "pnt*") == 0){
            fscanf(fileQry, "%s %s %s %s", j, k, cb, cp);
            pntAst(qt, j, k, cb, cp, fileTxt);
        }
        //delf
        if(strcmp(comando, "delf") == 0){
            fscanf(fileQry, "%s", j);
            delf(qt, j, fileTxt);
        }
        //delf*
        if(strcmp(comando, "delf*") == 0){
            fscanf(fileQry, "%s %s", j, k);
            delfAst(qt, j, k, fileTxt);
        }
        

        //T2_ED
        //dq
        if(strcmp(comando, "dq") == 0){
            char hashtag = getc(fileQry);
            hashtag = getc(fileQry);
            if(hashtag == '#'){
                fscanf(fileQry, "%s %f", cep, &r);
                dq(qt, cep, r, 1, fileTxt);
            }
            fseek(fileQry, -2, SEEK_CUR);
            fscanf(fileQry, "%s %f", cep, &r);
            dq(qt, cep, r, 0, fileTxt);
        }
        //del
        if(strcmp(comando, "del") == 0){
            fscanf(fileQry, "%s", cep);
            del(qt, cep, fileTxt);
        }
        //cbq    
        if(strcmp(comando, "cbq") == 0){
            fscanf(fileQry, "%f %f %f %s", &x, &y, &r, cb);
            cbq(qt, x, y, r, cb, fileTxt);
        }   
        //crd?      
        if(strcmp(comando, "crd?") == 0){
            fscanf(fileQry, "%s", cep);
            crd(qt, cep, fileTxt);
        }
        //car
        if(strcmp(comando, "car") == 0){
            fscanf(fileQry, "%f %f %f %f", &x, &y, &w, &h);
            car(qt, x, y, w, h, fileTxt);
        }   


        //T3_ED
        //cv
        if(strcmp(comando, "cv") == 0){
            fscanf(fileQry, "%d %s %c %d", &n, cep, &face, &num);
            cv(qt, n, cep, face, num);
        }
        //soc
        if(strcmp(comando, "soc") == 0){
            fscanf(fileQry, "%d %s %c %d", &casosCovid, cep, &face, &num);
            soc(qt, casosCovid, cep, face, num, fileTxt);
        }
        //ci        
        if(strcmp(comando, "ci") == 0){
            fscanf(fileQry, "%f %f %f", &x, &y, &r);
            ci(qt, x, y, r, fileTxt); 
        }

        //T4_ED
        //m?
        if(strcmp(comando, "m?") == 0){

        }
        //dm?
        if(strcmp(comando, "dm?") == 0){

        }
        //de?
        if(strcmp(comando, "de?") == 0){

        }   
        //mud
        if(strcmp(comando, "mud") == 0){

        }
        //dmprbt
        if(strcmp(comando, "dmprbt") == 0){
            fscanf(fileQry, " %c %s", &t, sfx);
            dmprbt(qt, t, sfx, dirSaida, nomeGeoSemExtensao, nomeQrySemExtensao);
        }
        //eplg?
        if(strcmp(comando, "eplg?") == 0){
            
        }
        //catac
        if(strcmp(comando, "catac") == 0){

        }
    }

    fclose(fileTxt);
    fclose(fileQry);
}
