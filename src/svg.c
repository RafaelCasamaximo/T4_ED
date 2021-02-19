#include <stdio.h>
#include <stdlib.h>

#include "svg.h"
#include "quadTree.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "linha.h"
#include "corPadrao.h"
#include "localCasos.h"
#include "postoSaude.h"
#include "poligono.h"


enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE, LINHA};

void desenhaSvgGeo(QuadTree* qt, char* dirSaida){

    char* corSombra[6] = {"#FFFF00", "#FF9955", "#FF0000", "#FF00CC", "#6600FF", "#A02C5A"}; //Comando usado para fazer a sombras das quadras no SVG do comando dd (Atualizado para T4)
    FILE* fileSvgGeo = NULL;
    fileSvgGeo = fopen(dirSaida, "w");
    if(!fileSvgGeo){
        exit(1);
    }
    printf("Arquivo SVG GEO criado com sucesso!");
    fprintf(fileSvgGeo, "<svg  width=\"10000\" height=\"10000\" viewBox=\"0 0 10000 10000\" xmlns=\"http://www.w3.org/2000/svg\">");

    fprintf(fileSvgGeo, "<defs>");
    for(int i = 0; i < 6; i++){
        fprintf(fileSvgGeo, "<filter id=\"shadow%d\">\n\t\t\t<feDropShadow dx=\"4\" dy=\"4\" stdDeviation=\"0.2\" flood-color=\"%s\"/>\n\t\t</filter>", i, corSombra[i]);
    }
    fprintf(fileSvgGeo, "</defs>");

    percorreLarguraQt(qt[0], circuloDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[1], retanguloDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[2], textoDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[3], quadraDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[4], hidranteDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[5], semaforoDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[6], radioBaseDesenhaSvgGeo, fileSvgGeo);
    percorreLarguraQt(qt[7], postoSaudeDesenhaSvgGeo, fileSvgGeo);

    fprintf(fileSvgGeo, "\n</svg>");
    fclose(fileSvgGeo);
}


void desenhaSvgQry(QuadTree* qt, char* dirSaida){
    FILE* fileSvgQry = NULL;
    fileSvgQry = fopen(dirSaida, "w");
    if(!fileSvgQry){
        exit(1);
    }
    printf("Arquivo SVG QRY criado com sucesso!");
    fprintf(fileSvgQry, "<svg>");

    percorreLarguraQt(qt[0], circuloDesenhaSvgGeo, fileSvgQry);
    percorreLarguraQt(qt[1], retanguloDesenhaSvgQry, fileSvgQry);
    percorreLarguraQt(qt[2], textoDesenhaSvgGeo, fileSvgQry);
    percorreLarguraQt(qt[3], quadraDesenhaSvgQry, fileSvgQry);
    percorreLarguraQt(qt[4], hidranteDesenhaSvgGeo, fileSvgQry);
    percorreLarguraQt(qt[5], semaforoDesenhaSvgGeo, fileSvgQry);
    percorreLarguraQt(qt[6], radioBaseDesenhaSvgGeo, fileSvgQry);
    percorreLarguraQt(qt[7], postoSaudeDesenhaSvgGeo, fileSvgQry); 
    percorreLarguraQt(qt[8], linhaDesenhaSvgQry, fileSvgQry);

    fprintf(fileSvgQry, "\n</svg>");
    fclose(fileSvgQry);
}
