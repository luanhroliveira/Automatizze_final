#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "programa.h"
#include "verificacao.h"
#include "menu.h"

PROGRAMA p;
VERIFICADOR v;

void menu(){

	system("cls");
	while( 1 ){
		switch( tela() ){
			case 1:
			 		exe_programa(&p);	
					menu();
				break;
			case 2: listar_programas();
				break;
			case 0: exit(0);		//sai do programa
				break;
			default: printf("Informe uma opção válida!\n");
		
		}
	}
}


int tela(){

	int op;
	puts("........................AUTOMATIZZE.....................");
	puts("\n1 - Executar");
	puts("2 - Listar programas");
	puts("0 - Sair");
	scanf("%d", &op);
	
	return op;
}

void listar_programas() {
	int op;
	system("cls");
	printf("\n1 - Mozila Firefox\n2 - Google Chrome\n3 - Winrar\n4 - Java\n5 - Flash Player\n\n6 - Voltar\n0 - Sair\n");
	scanf("%d", &op);
	
	if(op = 6) {
		menu();
	}else {
		exit(0);
	}

}