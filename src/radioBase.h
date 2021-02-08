#ifndef __RADIOBASE_H
#define __RADIOBASE_H

typedef void* RadioBase;

// Função responsável para criar RadioBase. Retorna um pointer instanciado.
RadioBase criaRadioBase(char* id, float x, float y);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void radioBaseSetId(RadioBase radiobase, char* id);
void radioBaseSetX(RadioBase radiobase, float x);
void radioBaseSetY(RadioBase radiobase, float y);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* radioBaseGetId(RadioBase radiobase);
float radioBaseGetX(RadioBase radiobase);
float radioBaseGetY(RadioBase radiobase);

#endif
