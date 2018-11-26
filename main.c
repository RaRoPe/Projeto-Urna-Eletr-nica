#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "flush_in.c"
#include "interface.c"
#include "votar.c"
#include "validarCPF.c"
#include "busca.c"
#include "multiplicador.c"

#define BUFFERCPF 12

void main(){
	
	int8_t opcao = 0, i;
	char CPF_aux[BUFFERCPF], CPF[BUFFERCPF];
	bool valido = FALSE;
	
	limpa_tela();

	printf("Digite o seu CPF para prosseguir com a votação: ");
	scanf("%s", CPF);
	
	if ((OS == 0) || (OS == 2))
		flush_in_std();
	else 
		fflush(stdin);
	
	//printf("CPF = |%s|\n", CPF);
	valido = valida_CPF(CPF);

	while (valido == FALSE){
		printf("[-] CPF inválido.\nDigite o seu CPF para prosseguir com a votação: ");
		scanf("%s", CPF);
		
		if ((OS == 0) || (OS == 2))
			flush_in_std();
		else 
			fflush(stdin);
		
		//printf("CPF = |%s|\n", CPF);
		valido = valida_CPF(CPF);
	}
	
	printf("[+] CPF validado com sucesso!\n    Aperte ENTER para continuar");
	
	getchar();

	while (opcao != 6){
		opcao = printa_menu();
		
		switch(opcao){
			case 1:
				por_estado();
				break;
			case 2:
				por_numero();
				break;
			case 3:
				do_estado();
				break;
			case 4:
				votar(CPF);
				limpa_tela();
				printf( "\n"
					"\t\t***************************\n"
					"\t\tVoto computado com sucesso!\n"
					"\t\t***************************\n\n");
				exit(0);
			case 5:
				multiplicar();
				break;
			case 6:
				exit(0);
				break;
		}
		if ((OS == 0) || (OS == 2))
			flush_in_std();
		else 
			fflush(stdin);
	}
}
