#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	unsigned int matricula;
} Info;
typedef char * Chave;
typedef struct _Item{
	struct _Item *prox;
	Chave val;
	Info dados;
} Item;
typedef struct{
	int sz;
	Item *itens;
	unsigned int *pesos;
} Table;
void add(Table *t, Chave *c, int tam);
void transf(Table *t, Chave c);
void antiColisoes(Item *i,Chave c);
int peso(int i);
int calcM(int n);
void initHash(Table *t,int M);
void print(Table *t);
#endif
