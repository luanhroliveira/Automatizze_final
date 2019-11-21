/*
	Name:  			Automatizze_install
	Copyright:		NULL
	Author: 		Luan Oliveira; Erick Oliveira; Ivan Araújo; André Rocha.
	Date: 			20/11/19 22:21
	Description: 	Este programa foi criado com o intuito de auxiliar a instalação
					de programas básicos para um bom funcionamento do sistema 
					operacional windows 7 e superiores.
*/

#include <stdio.h>
#include <locale.h>
#include "programa.h"
#include "verificacao.h"
#include "menu.h"

PROGRAMA p;
VERIFICADOR v;

int main(){
	setlocale(LC_ALL, "Portuguese");
	menu();
}