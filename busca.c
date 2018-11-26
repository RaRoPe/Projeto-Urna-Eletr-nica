#include "busca.h"

void localizar_partido(int8_t estado){
	
	char nome[80], c;
	
	int32_t i = 1, numero, partido_para_consultar, partido;
	
	FILE *fp,*fp2;
	
	fp2 = fopen("lista_partidos_2018.txt", "r");
	
	printf("LISTA DE PARTIDOS:\t\t NUMERO DO PARTIDO:\n");
	while ((c=getc(fp2)) != EOF){
		if (c == '\n'){
			if (i != 35)
				printf("\t\t\t\t\t%d", i);
			else
				printf("\t\t\t\t%d", i);
			i+=1;
		}
		printf("%c", c);
		
	}
	fclose(fp2);
	
	printf("Qual partido deseja consultar?\n");
	scanf("%d", &partido_para_consultar);
	
	while (partido_para_consultar < 0 && partido_para_consultar > 35){
		printf("PARTIDO INVÁLIDO\nQual partido deseja consultar?");
		scanf("%d", &partido_para_consultar);
	}
	
	if (estado == DF){
		fp = fopen("dados_candidatos_DF.txt", "r");
	}
	else{
		if (estado = GO)
			fp = fopen("dados_candidatos_GO.txt", "r");
		else{
			fp = fopen("dados_candidatos_MS.txt", "r");
		}
	}
	
	for (i=0;i<strlen(nome);i++)
		nome[i] = '\0';
	
	while (fscanf(fp, "%d;%[^;];%d", &numero, nome, &partido) != EOF){
		if (partido_para_consultar == partido){
			printf("PARTIDO = %d\nCANDIDATO = %s\nNUMERO = %d\n-------------------------------------------------\n", partido, nome, numero);
		}
	}
 	fclose(fp);
	return;
}

bool localizar_candidato(int32_t numero_para_consulta, int8_t estado, int8_t *partido_candidato){
	
	char nome[80];
	
	int32_t i, numero, partido;
	
	FILE *fp;
	
	switch(estado){
		case DF:
			fp = fopen("dados_candidatos_DF.txt", "r");
			break;
		case GO:
			fp = fopen("dados_candidatos_GO.txt", "r");
			break;
		case MS:
			fp = fopen("dados_candidatos_MS.txt", "r");
			break;
	}
	
	for (i=0;i<strlen(nome);i++)
		nome[i] = '\0';
	
	while (fscanf(fp, "%d;%[^;];%d", &numero, nome, &partido) != EOF){
		if (numero_para_consulta == numero){
			printf("PARTIDO = %d\nCANDIDATO = %s\nNUMERO = %d\n-------------------------------------------------\n", partido, nome, numero);
 			fclose(fp);
			*partido_candidato = partido;
			return TRUE;
		}
			
	}
	printf("NÚMERO NÃO ENCONTRADO!\n");
 	fclose(fp);
	return FALSE;
}

void print_file(int8_t estado){
	
	char nome[80];
	
	int32_t i, numero, partido;
	
	FILE *fp;
	
	if (estado == DF){
		fp = fopen("dados_candidatos_DF.txt", "r");
	}
	else{
		if (estado = GO)
			fp = fopen("dados_candidatos_GO.txt", "r");
		else{
			fp = fopen("dados_candidatos_MS.txt", "r");
		}
	}
	
	for (i=0;i<strlen(nome);i++)
		nome[i] = '\0';
	
	while (fscanf(fp, "%d;%[^;];%d", &numero, nome, &partido) != EOF){
		printf("PARTIDO = %d\nCANDIDATO = %s\nNUMERO = %d\n-------------------------------------------------\n", partido, nome, numero);
	}
	fclose(fp);
}

void por_estado(){
	
	int8_t estado;
	
	limpa_tela();
	
	printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
	scanf("%hhd", &estado);
	
	while ((estado != DF) && (estado != GO) && (estado != MS)){
		printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
		scanf("%hhd", &estado);
		
	}
	
	if ((OS == 0) || (OS == 2))
		flush_in_std();
	else 
		fflush(stdin);
	
	print_file(estado);
	
	printf("\nAPERTE ENTER PRA CONTINUAR");
//	getchar();
}

void por_numero(){
	
	char nome[80];
	int8_t estado, zero = 0;
	int32_t numero;
	bool achou;
	
	limpa_tela();
	
	printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
	scanf("%hhd", &estado);
	
	while ((estado != DF) && (estado != GO) && (estado != MS)){
		printf("ESTADO INVÁLIDO!\nQual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
		scanf("%hhd", &estado);	
	}
	
	printf("Qual o número do candidato que deseja consultar? ");
	scanf("%d", &numero);
	
	achou = localizar_candidato(numero, estado, &zero);
	
	printf("\nAPERTE ENTER PRA CONTINUAR");
	getchar();
}

void do_estado(){
	
	int8_t estado;
	
	limpa_tela();
	
	printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
	scanf("%hhd", &estado);
	
	while ((estado != DF) && (estado != GO) && (estado != MS)){
		printf("ESTADO INVÁLIDO!\nQual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
		scanf("%hhd", &estado);
	}
	
	localizar_partido(estado);
	
	printf("\nAPERTE ENTER PRA CONTINUAR");
	getchar();
}
