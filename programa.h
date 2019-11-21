#ifndef _PROGRAMA_H_
#define _PROGRAMA_H_

struct programa{
	char** nome_programa;
	int qntd_linhas;
	int qntd_colunas;
	int cont;
};
typedef struct programa PROGRAMA;

void aloca_char(PROGRAMA* p);
void escreve_arquivo(PROGRAMA* p);
void exe_programa(PROGRAMA* p);
void libera_char(PROGRAMA* p);

#endif