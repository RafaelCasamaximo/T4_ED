#include <stdio.h>
#include <stdlib.h>

#include "qry2.h"
#include "quadTree.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "linha.h"
#include "utilitario.h"
#include "texto.h"
#include "retangulo.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE, LINHA};

void dq(QuadTree* qt, char* id, float r, int hashtag, FILE* fileTxt){
     fprintf(fileTxt, "\ndq %s %s %f", hashtag == 1 ? "#" : " ", id, r);

     // DoublyLinkedList lista;
     // Hidrante hidrante = getInfoByIdQt(qt[HIDRANTE], id);
     // if(hidrante != NULL){
     //      lista = nosDentroCirculoQt(qt[QUADRA], hidranteGetX(hidrante), hidranteGetY(hidrante), r);
     // }

     // Semaforo semaforo = getInfoByIdQt(qt[SEMAFORO], id);
     // if(semaforo != NULL){
     //      lista = nosDentroCirculoQt(qt[QUADRA], semaforoGetX(semaforo), semaforoGetY(semaforo), r);
     // }

     // RadioBase radiobase = getInfoByIdQt(qt[RADIOBASE], id);
     // if(radiobase != NULL){
     //      lista = nosDentroCirculoQt(qt[QUADRA], radioBaseGetX(radiobase), radioBaseGetY(radiobase), r);
     // }
     
     // for(Node aux = getFirst(aux); aux != NULL; aux = getNext(aux)){
     //      QtNo noArvore = getInfo(aux); //Nosso nó da arvore
     //      Quadra quadra = getInfoQt(qt[QUADRA], noArvore); //Pega a quadra
     // }

     // // float qX = quadraGetX(quadra);
     // // float qY = quadraGetY(quadra);
     // // float qW = quadraGetWidth(quadra);
     // // float qH = quadraGetHeight(quadra);

     // // if(insideCirculo(qX, qY, x, y, r) == 1 && insideCirculo(qX + qW, qY, x, y, r) == 1 && insideCirculo(qX, qY + qH, x, y, r) == 1 && insideCirculo(qX + qW, qY + qH, x, y, r) == 1){
     // //      quadraSetCorBorda(quadra, cstrk);
     // //      fprintf(fileTxt, "CEP QUADRA: %s\n", quadraGetCep(quadra));
     // // }

}

void del(QuadTree* qt, char* id, FILE* fileTxt){
     fprintf(fileTxt, "\ndel %s", id);

     Quadra quadra = getInfoByIdQt(qt[QUADRA], id);
     if(quadra != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - QUADRA CEP: %s", quadraGetX(quadra), quadraGetY(quadra), quadraGetCep(quadra));
          quadra = removeNoQt(qt, getNoQt(qt, quadraGetX(quadra), quadraGetY(quadra)));
          Linha linha = criaLinha(quadraGetX(quadra) + (quadraGetWidth(quadra) / 2), quadraGetY(quadra) + (quadraGetHeight(quadra) / 2), quadraGetX(quadra) + (quadraGetWidth(quadra) / 2), 0, 0, 0, quadraGetCep(quadra));
          insereQt(qt, linhaGetP1(linha), linha);
          free(quadraGetPoint(quadra));
          free(quadra);
          return;
     }
     Hidrante hidrante = getInfoByIdQt(qt[HIDRANTE], id);
     if(hidrante != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - HIDRANTE CEP: %s", hidranteGetX(hidrante), hidranteGetY(hidrante), hidranteGetId(hidrante));
          hidrante = removeNoQt(qt, getNoQt(qt, hidranteGetX(hidrante), hidranteGetY(hidrante)));
          Linha linha = criaLinha(hidranteGetX(hidrante), hidranteGetY(hidrante), hidranteGetX(hidrante), 0, 0, 0, hidranteGetId(hidrante));
          insereQt(qt, linhaGetP1(linha), linha);
          free(hidranteGetPoint(hidrante));
          free(hidrante);
          return;
     } 
     Semaforo semaforo = getInfoByIdQt(qt[SEMAFORO], id);
     if(semaforo != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - SEMAFORO CEP: %s", semaforoGetX(semaforo), semaforoGetY(semaforo), semaforoGetId(semaforo));
          semaforo = removeNoQt(qt, getNoQt(qt, semaforoGetX(semaforo), semaforoGetY(semaforo)));
          Linha linha = criaLinha(semaforoGetX(semaforo), semaforoGetY(semaforo), semaforoGetX(semaforo), 0, 0, 0, semaforoGetId(semaforo));
          insereQt(qt, linhaGetP1(linha), linha);
          free(semaforoGetPoint(semaforo));
          free(semaforo);
          return;
     }
     RadioBase radiobase = getInfoByIdQt(qt[RADIOBASE], id);
     if(radiobase != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - RADIOBASE CEP: %s", radioBaseGetX(radiobase), radioBaseGetY(radiobase), radioBaseGetId(radiobase));
          radiobase = removeNoQt(qt, getNoQt(qt, radioBaseGetX(radiobase), radioBaseGetY(radiobase)));
          Linha linha = criaLinha(radioBaseGetX(radiobase), radioBaseGetY(radiobase), radioBaseGetX(radiobase), 0, 0, 0, radioBaseGetId(radiobase));
          insereQt(qt, linhaGetP1(linha), linha);
          free(radioBaseGetPoint(radiobase));
          free(radiobase);
          return;
     }
}


void cbq(QuadTree* qt, float x, float y, float r, char* cstrk, FILE* fileTxt){
     DoublyLinkedList lista = nosDentroCirculoQt(qt, x, y, r); //Retorna uma lista de nós que estão dentro do circulo x,y com raio r

     fprintf(fileTxt, "\ncbq %f %f %f %s\n", x, y, r, cstrk);
     
     for(Node aux = getFirst(lista); aux != NULL; aux = getNext(aux)){

          //O comando que o evandro passou NÃO FAZ SENTIDO. Ao inves de nosDentroCirculo retornar uma lista dos ELEMENTOS da quadtree, ela retorna uma lista de NOS
          //As infos (quadra, circ, ret, hidrante, etc) ficam DENTRO DO NÓ DA QUADTREE!!! Por isso temos que acessar a informação da lista (que é o node da QT) e depois pegar a informação desse node :)
          //Por favor evandro se ler esse comentário no trabalho pelo aMOR DE DEUS MUDA NO PRÓXIMO
          //Além do mais, o parâmetro da arvore é inutil, já que getInfoQt não usa. Dentro dele está qt = qt só para não dar warning de unused. Retorna só no->info;
          QtNo noArvore = getInfo(aux); //Nosso nó da arvore
          Quadra quadra = getInfoQt(qt[QUADRA], noArvore); //Pega a quadra

          float qX = quadraGetX(quadra);
          float qY = quadraGetY(quadra);
          float qW = quadraGetWidth(quadra);
          float qH = quadraGetHeight(quadra);

          if(insideCirculo(qX, qY, x, y, r) == 1 && insideCirculo(qX + qW, qY, x, y, r) == 1 && insideCirculo(qX, qY + qH, x, y, r) == 1 && insideCirculo(qX + qW, qY + qH, x, y, r) == 1){
               quadraSetCorBorda(quadra, cstrk);
               fprintf(fileTxt, "CEP QUADRA: %s\n", quadraGetCep(quadra));
          }

     }
}


void crd(QuadTree* qt, char* id, FILE* fileTxt){
     fprintf(fileTxt, "\ncrd? %s", id);

     Quadra quadra = getInfoByIdQt(qt[QUADRA], id);
     if(quadra != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - QUADRA CEP: %s", quadraGetX(quadra), quadraGetY(quadra), quadraGetCep(quadra));
          return;
     }
     Hidrante hidrante = getInfoByIdQt(qt[HIDRANTE], id);
     if(hidrante != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - HIDRANTE CEP: %s", hidranteGetX(hidrante), hidranteGetY(hidrante), hidranteGetId(hidrante));
          return;
     } 
     Semaforo semaforo = getInfoByIdQt(qt[SEMAFORO], id);
     if(semaforo != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - SEMAFORO CEP: %s", semaforoGetX(semaforo), semaforoGetY(semaforo), semaforoGetId(semaforo));
          return;
     }
     RadioBase radiobase = getInfoByIdQt(qt[RADIOBASE], id);
     if(radiobase != NULL){
          fprintf(fileTxt, "\nX:%f Y:%f - RADIOBASE CEP: %s", radioBaseGetX(radiobase), radioBaseGetY(radiobase), radioBaseGetId(radiobase));
          return;
     }
}


void car(QuadTree* qt, float x, float y, float w, float h, FILE* fileTxt){
     DoublyLinkedList lista = nosDentroRetanguloQt(qt, x, y, x + w, y + h); //Retorna uma lista de nós que estão dentro do retangulo x, y, w, h

     fprintf(fileTxt, "\ncar %f %f %f %f", x, y, w, h);

     float areaTotal = 0;

     for(Node aux = getFirst(lista); aux != NULL; aux = getNext(aux)){
          QtNo noArvore = getInfo(aux); //Nosso nó da arvore
          Quadra q = getInfoQt(qt[QUADRA], noArvore); //Pega a quadra

          float qX = quadraGetX(q);
          float qY = quadraGetY(q);
          float qW = quadraGetWidth(q);
          float qH = quadraGetHeight(q);

          if(insideRetangulo(qX, qY, x, y, w, h) == 1 && insideRetangulo(qX + qW, qY, x, y, w, h) == 1 && insideRetangulo(qX, qY + qH, x, y, w, h) == 1 && insideRetangulo(qX + qW, qY + qH, x, y, w, h) == 1){
               //Tudo que estiver aqui dentro vai ser executado para as quadras que estiverem completamente dentro do retangulo

               //Pegar a area da quadra
               float areaQuadraAtual = quadraGetArea(q);

               //Escrever a area da quadra dentro da quadra (Querendo adicionar um TEXTO para ser desenhado no SVG)
               //Para escrever um texto com um valor que é float, eu tenho que converter pra string
               char areaQuadraAtualString[10];
               sprintf(areaQuadraAtualString, "%f", areaQuadraAtual); //Converte float para string. O 1o parâmetro é sempre a string e o resto é o float
               Texto tAux = criaTexto("-1", 10, qX + (qW / 2), qY + (qH / 2), areaQuadraAtualString, "seashell", "black"); //Crio meu texto com a area que vai ser printada dentro da quadra
               insereQt(qt[TEXTO], textoGetPoint(tAux), tAux); //Adiciono texto na QT
               //Somar a area da quadra com a area total
               areaTotal += areaQuadraAtual;

               //Imprime no TXT a area e as informações da quadra atual
               fprintf(fileTxt, "\nQUADRA CEP: %s - ÁREA: %f", quadraGetCep(q), areaQuadraAtual);
          }

     }

     //Printar o retangulo do comando
     Retangulo rAux = criaRetangulo("-1", 0, x, y, w, h, "pink", "none", "3px");
     insereQt(qt[RETANGULO], retanguloGetPoint(rAux), rAux);

     //Traçar linha do ponto X, Y até o topo com a area total ao lado
     char areaTotalString[10];
     sprintf(areaTotalString, "%f", areaTotal);
     Linha lAux = criaLinha(x, y, x, 0, 0, 0, areaTotalString);
     insereQt(qt[LINHA], linhaGetP1(lAux), lAux);

     //Imprime Área total das quadras
     fprintf(fileTxt, "\n ÁREA TOTAL: %f\n", areaTotal);

}
