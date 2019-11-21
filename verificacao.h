#ifndef _VERIFICACAO_H_
#define _VERIFICACAO_H_

struct verificador{
    char** verif_diretorio;
    int verif_linhas;
    int verif_colunas;
    int cont;
//int verif_cont;
};
typedef struct verificador VERIFICADOR;

void verificador_arquivo(VERIFICADOR* v);
void verifi_char (VERIFICADOR* v);
void libera_verif_char(VERIFICADOR* v);
void verificar_diretorio (VERIFICADOR* v);

//se retornar valor 0
void escreve_resultado_0(VERIFICADOR* v);

//se retornar valor 1
void escreve_resultado_1(VERIFICADOR* v);

#endif