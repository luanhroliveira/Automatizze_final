#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "programa.h"
#include "verificacao.h"

PROGRAMA p;
VERIFICADOR v;

void escreve_arquivo(PROGRAMA* p){
	
	FILE* f;

    f = fopen("reg_programas.txt", "r+");
    if(f == NULL) {
    	f = fopen("reg_programas.txt", "w+");
    }

    int qtd;
    fscanf(f, "%i", &qtd);
    qtd++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%i", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s instalado com sucesso!", p->nome_programa[p->cont]);

    fclose(f);
}

void exe_programa(PROGRAMA* p){
	
	FILE* f;
	
	f = fopen("programas_basicos.txt", "r");
	if(f == 0){
		printf("\nArquivo não encontrado!");
		exit(1);
	}
	
	fscanf(f, "%i %i", &(p->qntd_linhas), &(p->qntd_colunas));
	aloca_char(p);
	verificador_arquivo(&v);
	p->cont = 0;
	for(int i = 0; i <= p->qntd_linhas; i++){
		fscanf(f, "%s", p->nome_programa[i]);

	//	system(p->nome_programa[i]);
		escreve_arquivo(p);

		printf("\n\nSai funcao verificar\n\n");
		system("pause");

		MessageBox(NULL, "instalado com sucesso!", "titulo", MB_OK);
		p->cont++;
	}
	fclose(f);
	libera_char(p);
}

void aloca_char(PROGRAMA* p){

	p->nome_programa = malloc(sizeof(char*) * p->qntd_linhas);
	for(int i = 0; i < p->qntd_linhas; i++){
		p->nome_programa[i] = malloc(sizeof(char) * p->qntd_colunas + 1);
	}
}

void libera_char(PROGRAMA* p){

	for(int i = 0; i < p->qntd_linhas; i++){
		free(p->nome_programa[i]);
	}
	free(p->nome_programa);
}