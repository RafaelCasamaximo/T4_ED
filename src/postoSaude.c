#include <stdio.h>
#include <stdlib.h>

#include "postoSaude.h"



typedef struct{
    float x, y;
}PostoSaudeStruct;


//Create
PostoSaude criaPostoSaude(float x, float y){
    PostoSaudeStruct* ps = (PostoSaudeStruct*)malloc(sizeof(PostoSaudeStruct));

    ps->x = x;
    ps->y = y;

    return ps;
}


//Setters
void postoSaudeSetX(PostoSaude posto, float x){
    PostoSaudeStruct* ps = (PostoSaudeStruct*)posto;

    ps->x = x;
}

void postoSaudeSetY(PostoSaude posto, float y){
    PostoSaudeStruct* ps = (PostoSaudeStruct*)posto;

    ps->y = y;
}


//Getters
float postoSaudeGetX(PostoSaude posto){
    PostoSaudeStruct* ps = (PostoSaudeStruct*)posto;

    return ps->x;
}

float postoSaudeGetY(PostoSaude posto){
    PostoSaudeStruct* ps = (PostoSaudeStruct*)posto;

    return ps->y;
}
