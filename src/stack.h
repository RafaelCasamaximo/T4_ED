#ifndef __STACK_H
#define __STACK_H

typedef void* Stack;
typedef void* InfoStack;

//cria Stack
Stack createStack();

//verifica se a stack esta vazia
int isEmptyStack(Stack stack);

//tamanho da stack
int sizeStack(Stack stack);

//retorna o elemento do topo da stack
InfoStack topStack(Stack stack);

//insere um novo elemento no topo da stack
void pushStack(Stack stack, InfoStack info);

//retira um elemento do topo da stack
void popStack(Stack stack, int flag);


void removeStack(Stack stack, int flag);

#endif