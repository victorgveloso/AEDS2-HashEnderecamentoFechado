#include "hashComArquivo.h"
Table* leArquivo(){
	FILE* arquivo;
	if ((arquivo = fopen(NOMEARQUIVO,"r")) == NULL){
		printf("Leitura falhou\n");
		return NULL;
	}
	Table *table;
	char temp_nome[40];
	Item itemTemp;
	int chave_sz;
#ifndef TAMHASH
		//initHash(&table,calcM(chave_sz+1));TODO:Repensar isso aqui
		initHash(&table,calcM(30));
#else
		initHash(&table,TAMHASH);
#endif

	while (!feof(arquivo)) {
		fscanf(arquivo,"%u - %s\n",
				&itemTemp.dados.matricula,
				temp_nome
				);
		for(chave_sz = 0; temp_nome[chave_sz] != '\0'; chave_sz++){} 	//Capturando tamanho do nome
		itemTemp.val = (Chave)malloc((chave_sz+1)*sizeof(char));				//Alocando espaço para o nome
		itemTemp.val[chave_sz] = '\0';							//Determinando fim da string
		for(chave_sz = 0; temp_nome[chave_sz] != '\0'; chave_sz++){
			itemTemp.val[chave_sz] = temp_nome[chave_sz];			//copiando valor da string
		}
		 									//criando No e inserindo à arvore
		addi(table,itemTemp);
											//add item AGORA
	}

	fclose(arquivo);
	return table;
}