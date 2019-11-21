#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "verificacao.h"

VERIFICADOR v;

void verificador_arquivo(VERIFICADOR* v){
    
    FILE* f;

    f = fopen("reg_verificador.txt", "r");
    if (f == 0){
        printf("\nArquivo inexistente");
    }

    fscanf(f, "%i %i", &(v->verif_linhas), &(v->verif_colunas));

    verifi_char(v);

    for(int i = 0; i <= v->verif_linhas; i++){
        fscanf(f, " %[^\n]s", v->verif_diretorio[i]);

        v->cont = i;

        printf("\n%s\n", v->verif_diretorio[i]);

        verificar_diretorio(v);

        system("pause");

    }
    libera_verif_char(v);

    fclose(f);
}

void verifi_char(VERIFICADOR* v){
    
    v->verif_diretorio = malloc(sizeof(char*) * v->verif_linhas);    
    for(int i = 0; i < v->verif_linhas; i++){
    v->verif_diretorio[i] = malloc(sizeof(char) * v->verif_colunas + 1);
    }    
}

void libera_verif_char(VERIFICADOR* v){
	
	for(int i = 0; i < v->verif_linhas; i++){
		free(v->verif_diretorio[i]);
	}
	free(v->verif_diretorio);
}

void verificar_diretorio (VERIFICADOR* v){

    char diretorio[512];

    strcpy(diretorio, v->verif_diretorio[v->cont]);

    DIR* fd = opendir(diretorio);

    printf("\n%s\n", diretorio);
    system("pause");

     if(fd == NULL){
        printf("Diretorio nao existe.\n");
        escreve_resultado_0(v);
    }else{
        printf("Diretorio existe.\n");
        escreve_resultado_1(v);
    }
    closedir(fd);
}

void escreve_resultado_1(VERIFICADOR* v){
    FILE* f;

    f = fopen("result_verificacao.txt", "r+w");
    if(f == 0){
        f = fopen("result_verificacao.txt", "w+");
    }

    int qtd;
    fscanf(f, "%i", &qtd);
    qtd++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%i", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s Programa já existente.", v->verif_diretorio[v->cont]);

    fclose(f);
}

void escreve_resultado_0(VERIFICADOR* v){
    FILE* f;

    f = fopen("result_verificacao.txt", "r+w");
    if(f == 0){
        f = fopen("result_verificacao.txt", "w+");
    }

    int qtd;
    fscanf(f, "%i", &qtd);
    qtd++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%i", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s Programa não existente.", v->verif_diretorio[v->cont]);

    fclose(f);
}