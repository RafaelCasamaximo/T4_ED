#include <stdio.h>
#include <stdlib.h>

#include "qry2.h"
#include "quadTree.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"

void crd(QuadTree* qt, char* id, FILE* fileTxt){
    fprintf(fileTxt, "\ncrd?");

   Quadra quadra = getInfoByIdQt(qt[3], id);
   if(quadra != NULL){
       fprintf(fileTxt, "\nX:%f Y:%f - QUADRA CEP: %s", quadraGetX(quadra), quadraGetY(quadra), quadraGetCep(quadra));
       return;
   }
   Hidrante hidrante = getInfoByIdQt(qt[4], id);
   if(hidrante != NULL){
        fprintf(fileTxt, "\nX:%f Y:%f - HIDRANTE CEP: %s", hidranteGetX(hidrante), hidranteGetY(hidrante), hidranteGetId(hidrante));
        return;
   } 
   Semaforo semaforo = getInfoByIdQt(qt[5], id);
   if(semaforo != NULL){
        fprintf(fileTxt, "\nX:%f Y:%f - SEMAFORO CEP: %s", semaforoGetX(semaforo), semaforoGetY(semaforo), semaforoGetId(semaforo));
        return;
   }
   RadioBase radiobase = getInfoByIdQt(qt[6], id);
    if(radiobase != NULL){
        fprintf(fileTxt, "\nX:%f Y:%f - RADIOBASE CEP: %s", radioBaseGetX(radiobase), radioBaseGetY(radiobase), radioBaseGetId(radiobase));
        return;
   }
}