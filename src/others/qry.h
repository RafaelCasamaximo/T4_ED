#ifndef __QRY_H
#define __QRY_H

#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "densidadeDemografica.h"
#include "doublyLinkedList.h"
#include "postoSaude.h"

//T1_ED
/*
Função responsável pelo i?
PRE: Parâmetros do i?
POS: -1: Impossivel/ 0: Externo/ 1: Interno/ 2: Borda
*/
int inside(DoublyLinkedList* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY, FILE* fileTxt);

//o?
/*
Verifica se um circulo sobrepõe um retângulo
PRE: Circulo c, Retangulo r
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlayCirculoRetangulo(Circulo c, Retangulo r);

/*
Verifica se um circulo sobrepõe um retângulo
PRE: Circulo c, Retangulo r
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlayCirculoCirculo(Circulo c1, Circulo c2);

/*
Verifica se um circulo sobrepõe um retângulo
PRE: Circulo c, Retangulo r
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2);

/*
Função responsável pelo o?
PRE: Parâmetros do o?
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlay(DoublyLinkedList* listas, int j, int k, float* x, float* y, float* w, float* h, FILE* fileTxt);

//pnt e pnt*
/*
Função responsável pelo pnt. Altera a cor de uma figuras entre j e k.
PRE: ID j e novas cores da figura
*/
void pnt(DoublyLinkedList* listas, int j, char* cb, char* cp, FILE* fileTxt);

/*
Função responsável pelo pnt. Altera a cor de n figura.
PRE: IDs j e k e novas cores da figura
*/
void pntAst(DoublyLinkedList* listas, int j, int k, char* cb, char* cp, FILE* fileTxt);

//delf e delf*
/*
Função responsável pelo delf. Remove uma figura.
PRE: ID j da figura que será removida.
*/
void delf(DoublyLinkedList* listas, int j, FILE* fileTxt);

/*
Função responsável pelo delf. Remove uma figura.
PRE: IDs j e k da figura que será removida.
*/
void delfAst(DoublyLinkedList* listas, int j, int k, FILE* fileTxt);


//T2_ED
/*
Deleta um equipamento urbano ou quadra.
PRE: cep ou id da quadra ou equipamento urbano
*/
void del(DoublyLinkedList* listas, char* cep, FILE* fileTxt);

/*
Muda a cor da borda para cb de todas as quadras que estiverem inteiramente contidas dentro do círculo de centro em (x,y) e de raio r.
PRE: Coordenadas do circulo, nova cor da borda, listas e arquivo txt
*/
void cbq(DoublyLinkedList* listas, float x, float y, float r, char* cb, FILE* fileTxt);

/*
Imprime no arquivo .txt as coordenadas e a espécie do equipamento urbano de um determinado cep ou com uma determinada identificação.
PRE: Id ou Cep do equipamento urbano ou quadra em questão, listas e arquivo txt
*/
void crd(DoublyLinkedList* listas, char* id, FILE* fileTxt);

/*
Calcula a área total das quadras e equipamentos urbanos que estiverem inteiramente dentro do retângulo (x,y,w,h).
PRE: Coordenadas do retangulo, id para a criação de novas figuras, listas e arquivo txt
*/
void car(DoublyLinkedList* listas, float x, float y, float w, float h, int id, FILE* fileTxt);

/*
remove todas quadras que estivere inteiramente dentro a uma distância de no máximo r do equipamento urbano identificado por id. O parâmetro # pode estar ausente.
PRE: id do equipamento, raio do circulo, flag hashtag (1: possui/ 0: não possui), int id para a criação de novas figuras, listas e arquivo txt
*/
void dq(DoublyLinkedList* listas, char* id, float r, int hashtag, int identificadorFigura, FILE* fileTxt);


//T3_ED

/*
Foram detectados n casos de COVID-19 no endereço cep,face,num. DesenhaSvgGeo um quadrado laranja com o número dentro do endereço pasado.
PRE: numero de casos, endereço cep, face, num e listas
*/
void cv(DoublyLinkedList* listas, int n, char* cep, char face, int num);

/*
Morador do endereço cep,face,num precisa de atendimento. Determine os k postos de atendimento mais próximos. Traça umma linha do endereço até os k postos de saúde mais próximos.
PRE: k postos, endereço cep, face e num, listas e arquivo txt
*/
void soc(DoublyLinkedList* listas, int k, char* cep, char face, int num, FILE* fileTxt);

/*
Calcula se um circulo está inteiramente dentro de uma figura do tipo DensidadeDemografica
PRE: Objeto densidadeDemografica, coordanadas do circulo
POS: 1: está inteiramente dentro/ 0: está fora
*/
int circInsideDensidadeDemografica(DensidadeDemografica dd, float x, float y, float r);



PostoSaude centroide(DoublyLinkedList l, float area);
/*
Determinar a região de incidência relativa aos casos (comando cv) reportados dentro da região delimitada pela circunferência de
cento em (x,y) e raio r. Determinar a categoria da região. Se necessário sugerir um posto de atendimento no centróide da
região.
DesenhaSvgGeo um circulo sem preencimento e com borda grossa verde. DesenhaSvgGeo a região de incidência (envoltória convexa)
Usa borda grossa na cor vermelha e preencher com fundo ransparente na cor relativa à respectiva categoria.
PRE: coordenadas do circulo, listas e arquivo txt
*/
void ci(DoublyLinkedList* listas, float x, float y, float r, FILE* fileTxt);

#endif
