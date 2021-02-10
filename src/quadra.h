#ifndef __QUADRA_H
#define __QUADRA_H

typedef void* Quadra;

//Função responsável para criar Quuadra. Retorna um pointer instanciado.
Quadra criaQuadra(char* cep, float x, float y, float w, float h, char* cb, char* cp, int arredondado);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void quadraSetCep(Quadra quadra, char* cep);
void quadraSetX(Quadra quadra, float x);
void quadraSetY(Quadra quadra, float y);
void quadraSetWidth(Quadra quadra, float w);
void quadraSetHeight(Quadra quadra, float h);
void quadraSetCorBorda(Quadra quadra, char* cb);
void quadraSetCorPreenchimento(Quadra quadra, char* cp);
void quadraSetArredondado(Quadra quadra, int arredondado);
void quadraSetPoint(Quadra quadra, Point point);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* quadraGetCep(Quadra quadra);
float quadraGetX(Quadra quadra);
float quadraGetY(Quadra quadra);
float quadraGetWidth(Quadra quadra);
float quadraGetHeight(Quadra quadra);
char* quadraGetCorBorda(Quadra quadra);
char* quadraGetCorPreenchimento(Quadra quadra);
int quadraGetArredondado(Quadra quadra);
float quadraGetArea(Quadra quadra);
Point quadraGetPoint(Quadra quadra);

void quadraSwap(Quadra q1, Quadra q2);

#endif
