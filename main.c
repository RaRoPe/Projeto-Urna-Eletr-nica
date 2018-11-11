#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "flush_in.c"
#include "interface.c"
#include "votar.c"
#include "validarCPF.c"
#include "busca.c"

#define BUFFERCPF 12

void main(){
	
	int8_t opcao = 0, i;
	char CPF_aux[BUFFERCPF], CPF[BUFFERCPF];
	bool valido = FALSE; //Condição para a verificação da validade do CPF digitado
	
	limpa_tela();

	printf("Digite o seu CPF para prosseguir com a votação: ");
	scanf("%s", CPF);
	
	//Limpa o buffer do teclado
	if ((OS == 0) || (OS == 2))
		flush_in_std();
	else 
		fflush(stdin);
	
	//printf("CPF = |%s|\n", CPF);
	valido = valida_CPF(CPF);

	while (valido == FALSE){
		printf("[-] CPF inválido.\nDigite o seu CPF para prosseguir com a votação: ");
		scanf("%s", CPF);
		
		//Limpa o buffer do teclado
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
		opcao = printa_menu(); //Printa o menu para o eleitor
		
		switch(opcao){
			case 1: //Consultar todos os candidatos distritais ou regionais dado um estado
				por_estado();
				break;
			case 2: //Fazer busca por um candidato pra saber seu número para votar
				//por_numero();
				break;
			case 3: //Consultar todos os candidatos de um determinado partido de um estado
				do_estado();
				break;
			case 4: //Votar em um candidato federal e regional/distrital
				votar();
				limpa_tela();
				printf( "\n"
					"\t\t***************************\n"
					"\t\tVoto computado com sucesso!\n"
					"\t\t***************************\n\n");
				exit(0);
			case 5: //Multiplicar voto x vezes
				break;
			case 6: //Sair
				exit(0);
				break;
		}
	}
}
