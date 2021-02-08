#ifndef __STACK_H
#define __STACK_H

typedef void* Stack;
typedef void* Node;
typedef void* Info;

//cria Stack
Stack createStack();

//verifica se a stack esta vazia
int isEmpty(Stack stack);

//tamanho da stack
int sizeStack(Stack stack);

//retorna o elemento do topo da stack
Info topStack(Stack stack);

//insere um novo elemento no topo da stack
void pushStack(Stack stack, Info info);

//retira um elemento do topo da stack
void popStack(Stack stack);

Stack removeStack(Stack stack);

#endif