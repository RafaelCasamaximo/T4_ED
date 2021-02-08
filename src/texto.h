#ifndef __TEXTO_H_
#define __TEXTO_H_

typedef void* Texto;

//Função responsável para criar Texto. Retorna um pointer instanciado.
Texto criaTexto(int id, int size, float x, float y, char* txt, char* cb, char* cp);


/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void textoSetId(Texto texto, int id);
void textoSetX(Texto texto, float x);
void textoSetY(Texto texto, float y);
void textoSetTexto(Texto texto, char* txt, int size);
void textoSetCorBorda(Texto texto, char* cb);
void textoSetCorPreenchimento(Texto texto, char* cp);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
int textoGetId(Texto texto);
float textoGetX(Texto texto);
float textoGetY(Texto texto);
char* textoGetTexto(Texto texto);
char* textoGetCorBorda(Texto texto);
char* textoGetCorPreenchimento(Texto texto);

void textoDeletaTxt(Texto texto);

#endif
