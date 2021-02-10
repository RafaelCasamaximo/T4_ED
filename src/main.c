//Standart Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Custom Headers para configuração
#include "parametro.h"
#include "trataString.h"
#include "corPadrao.h"
#include "leituraGeo.h"
#include "processaGeo.h"
//#include "leituraQry.h"
#include "svg.h"
#include "texto.h"
#include "poligono.h"
//Custom Headers para estruturas e organização
#include "doublyLinkedList.h"
#include "quadTree.h"


//Enumeration para todas as listas utilizadas
enum LISTAS{CIRCULO, RETANGULO, TEXTO, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE, DENSIDADEDEMOGRAFICA};


int main(int argc, char* argv[]){
    //Variáveis passadas como parametro para o Path
    char* dirEntrada = NULL;
    char* arqGeo = NULL;
    char* arqQry = NULL;
    char* dirSaida = NULL;

    //Variaveis criadas para a localização dos arquivos de entrada e de saída
    //Armazena dirEntrada + arqGeo
    char* dirGeo = NULL;
    // //Armazena o nome do arquivo .geo
    // char* nomeArquivoGeo = NULL;
    // //Armazena o path de saida do arquivo .svg + nome do arquivo + extensão
    // char* saidaSvgGeo = NULL;
    // //Armazena o path de entrada do arquivo qry
    // char* dirQry = NULL;
    // //Armazena o nome do arquivo .geo sem extensão
    // char* nomeGeoSemExtensao = NULL;
    // //Armazena o nome do arquivo .qry sem extensão
    // char* nomeQrySemExtensao = NULL;
    // //Armazena o nome do arquivo geo com o arquivo qry
    // char* nomeGeoQry = NULL;
    // //Armazena o caminho de saida do SVG do geo+qry
    // char* dirSaidaGeoQry = NULL;
    // //Armazena o nome do arquivo de Log (TXT)
    // char* nomeArquivoLogTxt = NULL;
    // //Armazena o path de saida do arquivo de Log
    // char* dirTxt = NULL;

    CorPadrao cores = criaCorPadrao("0.5", "coral", "saddlebrown", "0.5", "red", "darkred", "0.5", "deeppink", "mediumvioletred", "0.5", "green", "red", "0.5", "0.5");

    //Realiza a leitura dos parâmetros
    for(int i = 1; argc > i; i++){     
        if(strcmp(argv[i], "-e") == 0){     
            dirEntrada = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-f") == 0){        
            arqGeo = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-q") == 0){       
            arqQry = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-o") == 0){     
            dirSaida = buscaParametros(argv, i);
        }
        i++;
    }

    //Verifica se os parâmetros essenciais estão inseridos
    verificaExecucao(arqGeo, dirSaida);


    //Cria Listas
    DoublyLinkedList listas[9];
    for(int i = CIRCULO; i <= DENSIDADEDEMOGRAFICA; i++){
        listas[i] = create();
    }


    //Refatorar trataString para retornar char*
    concatenaCaminhos(dirEntrada, arqGeo, &dirGeo);
    readGeo(listas, dirGeo, cores);
    
    QuadTree quadTrees[8];
    instanciaQts(quadTrees);
    convertToQuadTrees(quadTrees, listas);
    
    return 0;
}