#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilitario.h"
#include "doublyLinkedList.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "quadra.h"
#include "hidrante.h"
#include "radioBase.h"
#include "semaforo.h"
#include "localCasos.h"
#include "infoSoc.h"
#include "postoSaude.h"
#include "sorting.h"
#include "densidadeDemografica.h"
#include "poligono.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE, DENSIDADEDEMOGRAFICA, LOCALCASOS, POLIGONO};


int inside(DoublyLinkedList* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY, FILE* fileTxt){
    int id = 0;
    
    fprintf(fileTxt, "i? %d %f %f\n", j, x, y);

    for(int i = 0; i < 2; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            Info info = getInfo(aux);
            if(i == CIRCULO){
                id = circuloGetId(info);
            }
            else if(i == RETANGULO){
                id = retanguloGetId(info);
            }
            if(id == j){
                if(i == CIRCULO){
                    *centroDeMassaX = circuloGetX(info);
                    *centroDeMassaY = circuloGetY(info);
                    int resultado = insideCirculo(x, y, circuloGetX(info), circuloGetY(info), circuloGetRaio(info));
                    fprintf(fileTxt, "CIRCULO %s\n\n", resultado == 1 ? "CONTÉM" : "NÃO CONTÉM");
                    return resultado;
                }
                else if(i == RETANGULO){
                    *centroDeMassaX = retanguloGetX(info) + (retanguloGetWidth(info) / 2);
                    *centroDeMassaY = retanguloGetY(info) + (retanguloGetHeight(info) / 2);
                    int resultado = insideRetangulo(x, y, retanguloGetX(info), retanguloGetY(info), retanguloGetWidth(info), retanguloGetHeight(info));
                    fprintf(fileTxt, "CIRCULO %s\n\n", resultado == 1 ? "CONTÉM" : "NÃO CONTÉM");
                    return resultado;
                }
            }
        }
    }
    return -1;
}


int overlayCirculoRetangulo(Circulo c, Retangulo r){
    float dX = circuloGetX(c) - maxF(retanguloGetX(r), minF(circuloGetX(c), retanguloGetX(r) + retanguloGetWidth(r)));
    float dY = circuloGetY(c) - maxF(retanguloGetY(r), minF(circuloGetY(c), retanguloGetY(r) + retanguloGetHeight(r)));
    if((dX * dX + dY * dY) <= (circuloGetRaio(c) * circuloGetRaio(c))){
        return 1;
    } 
    return 0;
}

int overlayCirculoCirculo(Circulo c1, Circulo c2){
    if(distanciaQuadrada(circuloGetX(c1), circuloGetY(c1), circuloGetX(c2), circuloGetY(c2)) <= (circuloGetRaio(c1) + circuloGetRaio(c2)) * (circuloGetRaio(c1) + circuloGetRaio(c2))){
        return 1;
    }
    return 0;
}

int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2){

    int inside = -1;

    float r1X = retanguloGetX(r1);
    float r1Y = retanguloGetY(r1);
    float r1W = retanguloGetWidth(r1);
    float r1H = retanguloGetHeight(r1);

    float r2X = retanguloGetX(r2);
    float r2Y = retanguloGetY(r2);
    float r2W = retanguloGetWidth(r2);
    float r2H = retanguloGetHeight(r2);

    //Existe algum ponto do r1 contido no r2?
    inside = insideRetangulo(r1X, r1Y, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r1X + r1W, r1Y, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r1X, r1Y + r1H, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r1X + r1W, r1Y + r1H, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }

    //Existe algum ponto do r2 contido no r1?
    inside = insideRetangulo(r2X, r2Y, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r2X + r2W, r2Y, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r2X, r2Y + r2H, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r2X + r2W, r2Y + r2H, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    
    return 0;
}

int overlay(DoublyLinkedList* listas, int j, int k, float* x, float* y, float* w, float* h, FILE* fileTxt){
    float vX[4] = {0, 0, 0, 0};
    float vY[4] = {0, 0, 0, 0};
    
    int overlay = -1;

    Info infoJ = NULL;
    int tipoJ = -1;
    Info infoK = NULL;
    int tipoK = -1;

    fprintf(fileTxt, "o? %d %d\n", j, k);

    int idAux = 0;

    for(int i = 0; i < 2; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            if(i == CIRCULO){
                idAux = circuloGetId(getInfo(aux));
            }
            else if(i == RETANGULO){
                idAux = retanguloGetId(getInfo(aux));
            }
            if(idAux == j){
                infoJ = getInfo(aux);
                tipoJ = i;
            }
            if(idAux == k){
                infoK = getInfo(aux);
                tipoK = i;
            }
        }
    }

    if(tipoJ == CIRCULO){
        vX[0] = circuloGetX(infoJ) + circuloGetRaio(infoJ);
        vX[1] = circuloGetX(infoJ) - circuloGetRaio(infoJ);
        vY[0] = circuloGetY(infoJ) + circuloGetRaio(infoJ);
        vY[1] = circuloGetY(infoJ) - circuloGetRaio(infoJ);
    }
    else if(tipoJ == RETANGULO){
        vX[0] = retanguloGetX(infoJ);
        vX[1] = retanguloGetX(infoJ) + retanguloGetWidth(infoJ);
        vY[0] = retanguloGetY(infoJ);
        vY[1] = retanguloGetY(infoJ) + retanguloGetHeight(infoJ);
    }

    if(tipoK == CIRCULO){
        vX[2] = circuloGetX(infoK) + circuloGetRaio(infoK);
        vX[3] = circuloGetX(infoK) - circuloGetRaio(infoK);
        vY[2] = circuloGetY(infoK) + circuloGetRaio(infoK);
        vY[3] = circuloGetY(infoK) - circuloGetRaio(infoK);
    }
    else if(tipoK == RETANGULO){
        vX[2] = retanguloGetX(infoK);
        vX[3] = retanguloGetX(infoK) + retanguloGetWidth(infoK);
        vY[2] = retanguloGetY(infoK);
        vY[3] = retanguloGetY(infoK) + retanguloGetHeight(infoK);
    }

    *x = minV(vX, 4);
    *y = minV(vY, 4);
    *w = maxV(vX, 4) - *x;
    *h = maxV(vY, 4) - *y;

    if(tipoJ == CIRCULO && tipoK == CIRCULO){
        overlay = overlayCirculoCirculo(infoJ, infoK);
        fprintf(fileTxt, "CIRCULO CIRCULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");
        return overlay;
    }
    else if(tipoJ == RETANGULO && tipoK == RETANGULO){
        overlay = overlayRetanguloRetangulo(infoJ, infoK);
        fprintf(fileTxt, "RETANGULO RETANGULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");
        return overlay;
    }
    else if(tipoJ == CIRCULO && tipoK == RETANGULO){
        overlay = overlayCirculoRetangulo(infoJ, infoK);
        fprintf(fileTxt, "CIRCULO RETANGULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");

        return overlay;
    }
    else if(tipoJ == RETANGULO && tipoK == CIRCULO){
        overlay = overlayCirculoRetangulo(infoK, infoJ);
        fprintf(fileTxt, "RETANGULO CIRCULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");
        return overlay;
    }
    return -1;
}


void pnt(DoublyLinkedList* listas, int j, char* cb, char* cp, FILE* fileTxt){
    int id = 0;

    Info info;    

    for(int i = 0; i < 3; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            info = getInfo(aux);
            if(i == CIRCULO){
                id = circuloGetId(info);
            }
            else if(i == RETANGULO){
                id = retanguloGetId(info);
            }
            else if(i == TEXTO){
                id = textoGetId(info);
            }
            if(id == j){
                if(i == CIRCULO){
                    circuloSetCorBorda(info, cb);
                    circuloSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)));
                }
                else if(i == RETANGULO){
                    retanguloSetCorBorda(info, cb);
                    retanguloSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)));
                }
                else if(i == TEXTO){
                    textoSetCorBorda(info, cb);
                    textoSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, textoGetX(getInfo(aux)), textoGetY(getInfo(aux)));
                }
                return;
            }
        }
    }
}

void pntAst(DoublyLinkedList* listas, int j, int k, char* cb, char* cp, FILE* fileTxt){
    
    for(int i = min(j, k); i <= max(j, k); i++){
        pnt(listas, i, cb, cp, fileTxt);
    }
}
 

void delf(DoublyLinkedList* listas, int j, FILE* fileTxt){
    int id;
    
    for(int i = 0; i < 3; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            if(i == CIRCULO){
                id = circuloGetId(getInfo(aux));
                fprintf(fileTxt, "\nID: %d X: %f Y: %f R: %f CB: %s CP: %s\n", id, circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)), circuloGetRaio(getInfo(aux)), circuloGetCorBorda(getInfo(aux)), circuloGetCorPreenchimento(getInfo(aux)));
            }
            else if(i == RETANGULO){
                id = retanguloGetId(getInfo(aux));
                fprintf(fileTxt, "\nID: %d X: %f Y: %f W: %f H: %f CB: %s CP: %s\n", id, retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)), retanguloGetWidth(getInfo(aux)), retanguloGetHeight(getInfo(aux)), retanguloGetCorBorda(getInfo(aux)), retanguloGetCorPreenchimento(getInfo(aux)));
            }
            else if(i == TEXTO){
                id = textoGetId(getInfo(aux));
                fprintf(fileTxt, "\nID: %d X: %f Y: %f CB: %s CP: %s TEXTO: %s\n", id, textoGetX(getInfo(aux)), textoGetY(getInfo(aux)), textoGetCorBorda(getInfo(aux)), textoGetCorPreenchimento(getInfo(aux)), textoGetTexto(getInfo(aux)));
            }
            if(id == j){
                if(i == TEXTO){
                    textoDeletaTxt(getInfo(aux));
                }
                removeNode(listas[i], aux, 1);
                return;
            }
        }
    }
}

void delfAst(DoublyLinkedList* listas, int j, int k, FILE* fileTxt){
    for(int i = min(j, k); i <= max(j, k); i++){
        delf(listas, i, fileTxt);
    }
}



void del(DoublyLinkedList* listas, char* cep, FILE* fileTxt){
    for(int i = QUADRA; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            char id[20];
            float x = 0, y = 0;
            if(i == QUADRA){
                strcpy(id, quadraGetCep(getInfo(aux)));
                x = quadraGetX(getInfo(aux));
                y = quadraGetY(getInfo(aux));
                fprintf(fileTxt, "\nCEP: %s X: %f Y: %f W: %f H: %f\n", id, quadraGetX(getInfo(aux)), quadraGetY(getInfo(aux)), quadraGetWidth(getInfo(aux)), quadraGetHeight(getInfo(aux)));
            }
            else if(i == HIDRANTE){
                strcpy(id, hidranteGetId(getInfo(aux)));
                x = hidranteGetX(getInfo(aux));
                y = hidranteGetY(getInfo(aux));
                fprintf(fileTxt, "\nID: %s X: %f Y: %f\n", id, hidranteGetX(getInfo(aux)), hidranteGetY(getInfo(aux)));
            }
            else if(i == SEMAFORO){
                strcpy(id, semaforoGetId(getInfo(aux)));
                x = semaforoGetX(getInfo(aux));
                y = semaforoGetY(getInfo(aux));
                fprintf(fileTxt, "\nID: %s X: %f Y: %f\n", id, semaforoGetX(getInfo(aux)), semaforoGetY(getInfo(aux)));
            }
            else if(i == RADIOBASE){
                strcpy(id, radioBaseGetId(getInfo(aux)));
                x = radioBaseGetX(getInfo(aux));
                y = radioBaseGetY(getInfo(aux));
                fprintf(fileTxt, "\nID: %s X: %f Y: %f\n", id, radioBaseGetX(getInfo(aux)), radioBaseGetY(getInfo(aux)));
            }

            if(strcmp(id, cep) == 0){
                insert(listas[LINHA], criaLinha(x, y, x, 0, 0, 0, id));
                removeNode(listas[i], aux, 1);
                return;
            }
        }
    }
}


void cbq(DoublyLinkedList* listas, float x, float y, float r, char* cb, FILE* fileTxt){
    float xQuadra = 0, yQuadra = 0, wQuadra = 0, hQuadra = 0;
    
    for(Node aux = getFirst(listas[QUADRA]); aux != NULL; aux = getNext(aux)){
        xQuadra = quadraGetX(getInfo(aux));
        yQuadra = quadraGetY(getInfo(aux));
        wQuadra = quadraGetWidth(getInfo(aux));
        hQuadra = quadraGetHeight(getInfo(aux));

        /*
        x,y 
        x + w, y
        x, y + h
        x + w, y + h
        */
        int insideP1 = insideCirculo(xQuadra, yQuadra, x, y, r);
        int insideP2 = insideCirculo(xQuadra + wQuadra, yQuadra, x, y, r);
        int insideP3 = insideCirculo(xQuadra, yQuadra + hQuadra, x, y, r);
        int insideP4 = insideCirculo(xQuadra +  wQuadra, yQuadra + hQuadra, x, y, r);
        
        if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
            quadraSetCorBorda(getInfo(aux), cb);
            fprintf(fileTxt, "\nCEP: %s\n", quadraGetCep(getInfo(aux)));
        }
    }
}


void crd(DoublyLinkedList* listas, char* id, FILE* fileTxt){
    char idAux[20];
    for(int i = QUADRA; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            if(i == QUADRA){
                strcpy(idAux, quadraGetCep(getInfo(aux)));
            }
            else if(i == HIDRANTE){
                strcpy(idAux, hidranteGetId(getInfo(aux)));
            }
            else if(i == SEMAFORO){
                strcpy(idAux, semaforoGetId(getInfo(aux)));
            }
            else if(i == RADIOBASE){
                strcpy(idAux, radioBaseGetId(getInfo(aux)));
            }

            if(strcmp(id, idAux) == 0){
                if(i == QUADRA){
                    fprintf(fileTxt, "\nTIPO: QUADRA X: %f Y: %f\n", quadraGetX(getInfo(aux)), quadraGetY(getInfo(aux)));
                }
                else if(i == HIDRANTE){
                    fprintf(fileTxt, "\nTIPO: HIDRANTE X: %f Y: %f\n", hidranteGetX(getInfo(aux)), hidranteGetY(getInfo(aux)));
                }
                else if(i == SEMAFORO){
                    fprintf(fileTxt, "\nTIPO: SEMAFORO X: %f Y: %f\n", semaforoGetX(getInfo(aux)), semaforoGetY(getInfo(aux)));
                }
                else if(i == RADIOBASE){
                    fprintf(fileTxt, "\nTIPO: RADIO BASE X: %f Y: %f\n", radioBaseGetX(getInfo(aux)), radioBaseGetY(getInfo(aux)));
                }
            }

        }
    }
}


void car(DoublyLinkedList* listas, float x, float y, float w, float h, int id, FILE* fileTxt){
    float areaTotal = 0;
    char areaFiguraString[10];
    char areaString[22];

    int counter = id;
    fprintf(fileTxt, "----------------------------\nCAR X: %f Y: %f W: %f H: %f - LISTA DE CEPS E IDs DAS QUADRAS E EQUIPAMENTOS: \n", x, y, w, h);
    for(int i = QUADRA; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            counter--;
            if(i == QUADRA){
                float xQuadra = quadraGetX(getInfo(aux));
                float yQuadra = quadraGetY(getInfo(aux));
                float wQuadra = quadraGetWidth(getInfo(aux));
                float hQuadra = quadraGetHeight(getInfo(aux));

                int insideP1 = insideRetangulo(xQuadra, yQuadra, x, y, w, h);
                int insideP2 = insideRetangulo(xQuadra + wQuadra, yQuadra, x, y, w, h);
                int insideP3 = insideRetangulo(xQuadra, yQuadra + hQuadra, x, y, w, h);
                int insideP4 = insideRetangulo(xQuadra + wQuadra, yQuadra + hQuadra, x, y, w, h);

                if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
                    areaTotal += quadraGetArea(getInfo(aux));
                    sprintf(areaFiguraString, "%f", quadraGetArea(getInfo(aux)));
                    insert(listas[TEXTO], criaTexto(counter, 10, xQuadra + (wQuadra/2), yQuadra + (hQuadra/2), areaFiguraString, "seashell", "black"));
                    fprintf(fileTxt, "TIPO: QUADRA / CEP: %s\n", quadraGetCep(getInfo(aux)));
                }
            }
            else if(i == HIDRANTE){
                float xH = hidranteGetX(getInfo(aux));
                float yH = hidranteGetY(getInfo(aux));
                int p = insideRetangulo(xH, yH, x, y, w, h);

                if(p == 1){
                    areaTotal += 28.27; //porque o raio padrão no svg é 3, utiliza-se Pi(r^2)
                    insert(listas[TEXTO], criaTexto(counter, 6, xH , yH, "28.27", "seashell", "black"));
                    fprintf(fileTxt, "TIPO: HIDRANTE / ID: %s \n", hidranteGetId(getInfo(aux)));
                }
            }
            else if(i == SEMAFORO){
                float xS = semaforoGetX(getInfo(aux));
                float yS = semaforoGetY(getInfo(aux));
                int p = insideRetangulo(yS, yS, x, y, w, h);
                if(p == 1){
                    areaTotal += 28.27;
                    insert(listas[TEXTO], criaTexto(counter, 6, xS , yS, "28.27", "seashell", "black"));
                    fprintf(fileTxt, "TIPO: SEMAFORO / ID: %s\n", semaforoGetId(getInfo(aux)));
                }
            }
            else if(i == RADIOBASE){
                float xR = semaforoGetX(getInfo(aux));
                float yR = semaforoGetY(getInfo(aux));
                int p = insideRetangulo(xR, yR, x, y, w, h);
                if(p == 1){
                    areaTotal += 28.27;
                    insert(listas[TEXTO], criaTexto(counter, 6, xR , yR, "28.27", "seashell", "black"));
                    fprintf(fileTxt, "TIPO: RADIOBASE / ID: %s\n", radioBaseGetId(getInfo(aux)));
                }
            }
        }
    }

    sprintf(areaString, "%f", areaTotal);
    insert(listas[RETANGULO], criaRetangulo(counter-50, 0, x, y, w, h, "black", "none"));
    insert(listas[LINHA], criaLinha(x, y, x, 0, 0, 0, areaString));
    fprintf(fileTxt, "\nÁREA TOTAL: %f\n----------------------------\n", areaTotal);
}


void dq(DoublyLinkedList* listas, char* id, float r, int hashtag, int identificadorFigura, FILE* fileTxt){
    char idAux[20];
    float x = 0;
    float y = 0;
    fprintf(fileTxt, "----------------------------\nDQ - HASHTAG (1 - SIM/ 0 - NÃO): %d ID: %s R: %f\n", hashtag, id, r);
    
    for(int i = HIDRANTE; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            //Acha o ID do equipamento urbano que a gente precisa
            if(i == SEMAFORO){
                strcpy(idAux, semaforoGetId(getInfo(aux)));
            }
            else if(i == HIDRANTE){
                strcpy(idAux, hidranteGetId(getInfo(aux)));
            }
            else if(i == RADIOBASE){
                strcpy(idAux, radioBaseGetId(getInfo(aux)));
            }
            if(strcmp(idAux, id) == 0){
                //Pega o X e Y do equipamento
                if(i == SEMAFORO){
                    x = semaforoGetX(getInfo(aux));
                    y = semaforoGetY(getInfo(aux));
                    fprintf(fileTxt, "SEMAFORO - X: %f Y: %f\n", x ,y);
                }
                else if(i == HIDRANTE){
                    x = hidranteGetX(getInfo(aux));
                    y = hidranteGetY(getInfo(aux));
                    fprintf(fileTxt, "HIDRANTE - X: %f Y: %f\n", x ,y);
                }
                else if(i == RADIOBASE){
                    x = radioBaseGetX(getInfo(aux));
                    y = radioBaseGetY(getInfo(aux));
                    fprintf(fileTxt, "RADIOBASE - X: %f Y: %f\n", x ,y);
                }
            }
        }
    }
    //A partir desse momento a gente já tem o X e o Y (da parte anterior) e o raio do parâmetro
    //Remove as quadras (pois existe hashtag)
    //Percorre a lista de quadras pra ver quais estão completamente internas ao circulo
    if(hashtag == 1){
        Node auxDelete = getFirst(listas[QUADRA]);
        while(auxDelete != NULL){
            float xQuadra = quadraGetX(getInfo(auxDelete));
            float yQuadra = quadraGetY(getInfo(auxDelete));
            float wQuadra = quadraGetWidth(getInfo(auxDelete));
            float hQuadra = quadraGetHeight(getInfo(auxDelete));

            int insideP1 = insideCirculo(xQuadra, yQuadra, x, y, r);
            int insideP2 = insideCirculo(xQuadra + wQuadra, yQuadra, x, y, r);
            int insideP3 = insideCirculo(xQuadra, yQuadra + hQuadra, x, y, r);
            int insideP4 = insideCirculo(xQuadra + wQuadra, yQuadra + hQuadra, x, y, r);

            //Se a quadra tá completamente dentro do circulo deleta ela
            Node tempAux = getNext(auxDelete);
            if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
                fprintf(fileTxt, "\n QUADRA / CEP: %s", quadraGetCep(getInfo(auxDelete)));
                removeNode(listas[QUADRA], auxDelete, 1);
            }
            auxDelete = tempAux;
        }
    }

    //Não remove as quadras. Ao invés disso, só muda a cor delas e deixa a borda arredondada (pois não existe hashtag)
    //Percorre a lista de quadras pra ver quais estão completamente internas ao circulo
    else if(hashtag == 0){
        for(Node auxMudaCor = getFirst(listas[QUADRA]); auxMudaCor != NULL; auxMudaCor = getNext(auxMudaCor)){
            float xQuadra = quadraGetX(getInfo(auxMudaCor));
            float yQuadra = quadraGetY(getInfo(auxMudaCor));
            float wQuadra = quadraGetWidth(getInfo(auxMudaCor));
            float hQuadra = quadraGetHeight(getInfo(auxMudaCor));

            int insideP1 = insideCirculo(xQuadra, yQuadra, x, y, r);
            int insideP2 = insideCirculo(xQuadra + wQuadra, yQuadra, x, y, r);
            int insideP3 = insideCirculo(xQuadra, yQuadra + hQuadra, x, y, r);
            int insideP4 = insideCirculo(xQuadra + wQuadra, yQuadra + hQuadra, x, y, r);

            //Muda a cor do preenchimento e da borda e deixa o canto arredondado
            if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
                fprintf(fileTxt, "\n QUADRA / CEP: %s", quadraGetCep(getInfo(auxMudaCor)));
                quadraSetArredondado(getInfo(auxMudaCor), 1);
                quadraSetCorBorda(getInfo(auxMudaCor), "olive");
                quadraSetCorPreenchimento(getInfo(auxMudaCor), "beige");
            }

        }
    }
    //DesenhaSvgGeo os dois aneis em volta do equipamento urbano e o circulo da área de deleção
    insert(listas[CIRCULO], criaCirculo(identificadorFigura, 7, x, y, "blue", "none"));
    insert(listas[CIRCULO], criaCirculo(identificadorFigura - 1, 11, x, y, "blue", "none"));
    insert(listas[CIRCULO], criaCirculo(identificadorFigura - 2, r, x, y, "blue", "none"));
}



//T3_ED
void cv(DoublyLinkedList* listas, int n,  char* cep, char face, int num){
    char cepAux[20];
    float x, y, w, h;
    LocalCasos localCasosAux = NULL;
    
    for(Node aux = getFirst(listas[QUADRA]); aux != NULL; aux = getNext(aux)){
        strcpy(cepAux, quadraGetCep(getInfo(aux)));
        if(strcmp(cepAux, cep) == 0){
            x = quadraGetX(getInfo(aux));
            y = quadraGetY(getInfo(aux));
            w = quadraGetWidth(getInfo(aux));
            h = quadraGetHeight(getInfo(aux));
        }
    }
    if(face == 'L'){
        y += num;
        y -= 10;
    }
    else if(face == 'S'){
        x += num;
        //x -= 10; errado
    }
    else if(face == 'O'){
        x += w;
        x -= 20;
        y += num;
        y -= 10;
    }
    else if(face == 'N'){
        y += h;
        y -= 20;
        x += num;
        //x -= 10;
    }
    //criaLocalCasos(int n, int num, char* cep, char face, float x, float y);
    localCasosAux = criaLocalCasos(n, num, cep, face, x, y);
    insert(listas[LOCALCASOS], localCasosAux);
}


void soc(DoublyLinkedList* listas, int k, char* cep, char face, int num, FILE* fileTxt){
    float xLC, yLC;
    int qtdPS = 0;
    Linha linhaAux = NULL;
    Retangulo retanguloAux = NULL;

    for(Node aux = getFirst(listas[LOCALCASOS]); aux != NULL; aux = getNext(aux)){
        if(strcmp(cep, localCasosGetCep(getInfo(aux))) == 0 && face == localCasosGetFace(getInfo(aux)) && num == localCasosGetNum(getInfo(aux))){
            xLC = localCasosGetX(getInfo(aux));
            yLC = localCasosGetY(getInfo(aux));
        }
    }

    for(Node aux = getFirst(listas[POSTOSAUDE]); aux != NULL; aux = getNext(aux)){
        qtdPS++;    
    }

    if(qtdPS > 0){
        //-------------------------------------------------------------------------

        InfoSoc* info = malloc(qtdPS * sizeof(InfoSoc));
        for(int i = 0; i < qtdPS; i++){
            info[i] = criaInfoSoc(10, 10, 10);
        }
        //-------------------------------------------------------------------------
        int i = 0;
        for(Node aux = getFirst(listas[POSTOSAUDE]); aux != NULL; aux = getNext(aux)){
            infoSocSetX(info[i], postoSaudeGetX(getInfo(aux)));
            infoSocSetY(info[i], postoSaudeGetY(getInfo(aux)));
            infoSocSetDistancia(info[i], distanciaEntrePontos(xLC, yLC, postoSaudeGetX(getInfo(aux)), postoSaudeGetY(getInfo(aux))));
            i++;
        }

        shellSorting(info, qtdPS);
        
        for(i = 0; i < k && i < qtdPS; i++){ 
            fprintf(fileTxt, "\nPS %d - X: %f Y: %f", i+1, infoSocGetX(info[i]), infoSocGetY(info[i]));
            linhaAux = criaLinha(xLC + 10, yLC + 10, infoSocGetX(info[i]), infoSocGetY(info[i]), -1, 0, "");
            insert(listas[LINHA], linhaAux);

            retanguloAux = criaRetangulo(-1, 0, xLC+5, yLC+5, 10, 10, "white", "blue");
            insert(listas[RETANGULO], retanguloAux);
        }

        for(int i = 0; i < qtdPS; i++){
            free(info[i]);
        }
        free(info);
    }

}


int circInsideDensidadeDemografica(DensidadeDemografica dd, float x, float y, float r){
    if((x - r > densidadeDemograficaGetX(dd) && x - r < densidadeDemograficaGetX(dd) + densidadeDemograficaGetWidth(dd)) ||(x + r > densidadeDemograficaGetX(dd) && x + r < densidadeDemograficaGetX(dd) + densidadeDemograficaGetWidth(dd))){
        if((y - r > densidadeDemograficaGetY(dd) && y - r < densidadeDemograficaGetY(dd) + densidadeDemograficaGetHeight(dd)) ||(y + r > densidadeDemograficaGetY(dd) && y + r < densidadeDemograficaGetY(dd) + densidadeDemograficaGetHeight(dd))){
            return 1;
        }
    }
    return 0;
}

PostoSaude centroide(DoublyLinkedList l, float area){
    float x = 0;
    float y = 0;
    Info i = NULL;
    Info j = NULL;
    Node aux;

    for(aux = getFirst(l); aux != NULL; aux = getNext(aux)){
        i = getInfo(aux);
        j = getInfo(getNext(aux));
        x += (localCasosGetX(i) + localCasosGetX(j)) * localCasosGetX(i) * localCasosGetY(j) - localCasosGetY(i) * localCasosGetX(j);
        y += (localCasosGetY(i) + localCasosGetY(j)) * localCasosGetX(i) * localCasosGetY(j) - localCasosGetY(i) * localCasosGetX(j);
    }
    i = getInfo(aux);
    j = getInfo(getFirst(l));

    x += (localCasosGetX(i) + localCasosGetX(j)) * localCasosGetX(i) * localCasosGetY(j) - localCasosGetY(i) * localCasosGetX(j);
    y += (localCasosGetY(i) + localCasosGetY(j)) * localCasosGetX(i) * localCasosGetY(j) - localCasosGetY(i) * localCasosGetX(j);

    return criaPostoSaude(x / (6 * area), y / (6 * area));
}

void ci(DoublyLinkedList* listas, float x, float y, float r, FILE* fileTxt){

    Circulo circuloAux = NULL;
    float d = 0, area = 0, inc = 0;
    int numCasos = 0;
    char cor[22];
    PostoSaude postoAux = NULL;

    for(Node aux = getFirst(listas[DENSIDADEDEMOGRAFICA]); aux != NULL; aux = getNext(aux)){
        if(circInsideDensidadeDemografica(getInfo(aux), x, y, r) == 1){
            d = densidadeDemograficaGetDensidadeDemografica(getInfo(aux));
            break;
        }
    }

    circuloAux = criaCirculo(-1, x, y, r, "green", "none");
    insert(listas[CIRCULO], circuloAux);

    DoublyLinkedList listaAux = NULL;
    listaAux = create();

    DoublyLinkedList casos = NULL;

    for(Node aux = getFirst(listas[LOCALCASOS]); aux != NULL; aux = getNext(aux)){
        if(insideCirculo(localCasosGetX(getInfo(aux)), localCasosGetY(getInfo(aux)), x, y, r) == 1){
            LocalCasos localCasoAux = NULL;
            localCasoAux = criaLocalCasos(localCasosGetN(getInfo(aux)), localCasosGetNum(getInfo(aux)), localCasosGetCep(getInfo(aux)), localCasosGetFace(getInfo(aux)), localCasosGetX(getInfo(aux)), localCasosGetY(getInfo(aux)));
            insert(listaAux, localCasoAux);
            fprintf(fileTxt, "\n LC X: %f Y: %f\n", localCasosGetX(getInfo(aux)), localCasosGetY(getInfo(aux)));
            numCasos += localCasosGetN(getInfo(aux));   
        }
    }
    if(getFirst(listaAux) == NULL){
        return;
    }

    int qtdElemListaAux = 0;
    for(Node aux = getFirst(listaAux); aux != NULL; aux = getNext(aux)){
        qtdElemListaAux++;
    }

    if(qtdElemListaAux > 2){
        casos = envoltoriaConvexa(listaAux);
    }
    else{
        return;
    }

    if(casos == NULL){
        casos = listaAux;
    }

    area = obterArea(casos);
    fprintf(fileTxt, "Numero de casos : %d\nArea : %f\n", numCasos, area);

    if(area != 0){
        inc = 10 * numCasos/(d * area);
        if(inc < 0.1){
            strcpy(cor, "00FFFF");
            fprintf(fileTxt,"Categoria A - Livre de Covid\n");
        }
        else if(inc < 5){
            strcpy(cor, "008080");
            fprintf(fileTxt,"Categoria B - Baixa incidencia\n");
        }
        else if(inc < 10){
            strcpy(cor, "FFFF00");
            fprintf(fileTxt,"Categoria C - Media incidencia\n");
        }
        else if(inc < 20){
            strcpy(cor, "FF0000");
            fprintf(fileTxt,"Categoria D - Alta incidencia\n");
        }
        else{
            strcpy(cor, "800080");
            fprintf(fileTxt,"Categoria E - Catastrofico\n");
            for(Node aux = getFirst(listas[POSTOSAUDE]); aux != NULL; aux = getNext(aux)){
                Info infoAux = getInfo(aux);
                if(insideCirculo(postoSaudeGetX(infoAux), postoSaudeGetY(infoAux), x, y, r)){
                    postoAux = infoAux;
                }
            }
            if(postoAux == NULL){
                postoAux = centroide(casos, area);
                fprintf(fileTxt, "Sugere-se um novo posto em: (%f, %f)\n", postoSaudeGetX(postoAux), postoSaudeGetY(postoAux));
            }
        }
    }
    else{
        fprintf(fileTxt, "Nao e possivel obter a categoria da região, e necessario ao menos 3 locais com incidencia");
    }

    int tamanho = 0;

    Node primeiroCasos = getFirst(casos);

    for(Node aux = getFirst(casos); aux != NULL; aux = getNext(aux)){
        tamanho++;
    }

    Poligono poligonoAux = NULL;
    poligonoAux = criaPoligono(cor, tamanho);

    insert(listas[POLIGONO], poligonoAux);
    for(int count = 0; count < tamanho; count++){
        Info poligonoInfoAux = getInfo(primeiroCasos);
        poligonoSetX(poligonoAux, localCasosGetX(poligonoInfoAux), count);
        poligonoSetY(poligonoAux, localCasosGetY(poligonoInfoAux), count);
    
        primeiroCasos = getNext(primeiroCasos);
    }

    removeList(casos, 0);
    //removeList(listaAux);
}
