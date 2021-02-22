#ifndef __PESSOA_H_
#define __PESSOA_H_


typedef void* Pessoa; 


Pessoa criaPessoa(char* cpf, char* nome, char* sobrenome, char sexo, char* dataNascimento);


//Setters
void pessoaSetCpf(Pessoa pessoa, char* cpf);
void pessoaSetNome(Pessoa pessoa, char* nome);
void pessoaSetSobrenome(Pessoa pessoa, char* sobrenome);
void pessoaSetSexo(Pessoa pessoa, char sexo);
void pessoaSetNascimento(Pessoa pessoa, char* nascimento);

//Getters
char* pessoaGetCpf(Pessoa pessoa);
char* pessoaGetNome(Pessoa pessoa);
char* pessoaGetSobrenome(Pessoa pessoa);
char pessoaGetSexo(Pessoa pessoa);
char* pessoaGetNascimento(Pessoa pessoa);

#endif