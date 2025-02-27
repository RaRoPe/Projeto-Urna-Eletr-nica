#include "busca.h"

/*char *muda_partido(char partido[3]){
	
	int16_t contador = 0, linha;
	char partido_aux[30], c;
	
	strcpy(partido_aux,"");
	
	FILE *fs;
	
	fs = fopen("lista_partidos_2018.txt", "r");
	
	linha = atoi(partido);
	
	while ((c=getc(fs)) && (linha-1 != contador)){
		if (c == EOF)
			break;
		else
			if (c == '\n')
				contador += 1;
	}
	
	fscanf(partido_aux, "%30[^\n]s", fs);
// 	strcpy(partido_aux,(fgetc(fs)));
	
	fclose(fs);
	
	return partido_aux;
}*/

void localizar_candidato(FILE *fp, char numero[10]){
	
	char numero_aux[10], c, c_aux[1], nome[30], partido[30];
	
	bool primeiro = FALSE;
	
	strcpy(numero_aux, "");
	c_aux[1]='\0';
	
	while (c = getc(fp)){
		if (c == EOF)
			break;
		if ((c != ';')&&(primeiro == FALSE)){
			c_aux[0]=c;
			strcat(numero_aux,c_aux);
			c_aux[0]='\0';
		}
		if (c == ';'){
			primeiro = TRUE;
			if (strcmp(numero,numero_aux) == 0){
				primeiro = FALSE;
				while(c=getc(fp)){
					if (c == '\n')
						break;
					if ((c != ';')&&(primeiro == FALSE))
						c_aux[0]=c;
						strcat(nome,c_aux);
						c_aux[0]='\0';
					if ((c != ';')&&(primeiro==TRUE))
						c_aux[0]=c;
						strcat(partido,c_aux);
						c_aux[0]='\0';
					if (c == ';'){
						primeiro = TRUE;
						strcpy(nome,"");
					}
				}
				break;
				strcpy(partido,muda_partido(partido));
				printf("Nome do candidato: %s\nPartido: %s\n", nome, partido);
			}
		}
		if (c == '\n'){
			strcpy(numero_aux,"");
			primeiro = FALSE;
		}
	}
}

void print_file(FILE *fp){
	
	char c, nome[40], partido[5], numero[6];
	
	int32_t i;
	int64_t atual = 0;
	
	bool primeiroPV = FALSE; //Variável que detectará se já chegou no primeiro ;
	bool segundoPV = FALSE; //Variável que detectará se já chegou no segundo ;
	
	while (c = getc(fp)){
		if (c == EOF)
			break;
		//Condicional que armazenará os partidos e os nomes dos candidatos
		if (primeiroPV == FALSE && segundoPV == FALSE){ //Ainda não chegou no primeiro ;
			numero[i] = c;
			i+=1;
		}
		if (primeiroPV == TRUE && segundoPV == FALSE){ //Passou do primeiro ; no arquivo
			nome[i] = c;
			i+=1;
		}
		if (segundoPV == TRUE){ //Passou do segundo ; no arquivo
			partido[i] = c;
			i+=1;
		}
		
// 		printf("%c", c);
		if (c == ';'){ //Divisor do nome e partido de cada candidato
			if (primeiroPV == TRUE){
				segundoPV = TRUE;
				nome[i] = '\0';
				nome[i-1] = '\0';
				i = 0;
			}	
			else{
				//fseek(fp,atual,SEEK_SET);
				primeiroPV = TRUE;
				numero[i] = '\0';
				numero[i-1] = '\0';
				i = 0;
			}
		}
		
		//Zera as strings correspondentes aos nomes dos candidatos e aos partidos
		if (c == '\n'){
			
			partido[i] = '\0';
			partido[i-1] = '\0';
	
//			strcpy(partido,muda_partido(partido));
			
			printf("PARTIDO = %s\nCANDIDATO = %s\nNUMERO = %s\n-------------------------------------------------\n", partido, nome, numero);
			
			strcpy(nome, "");
			strcpy(partido, "");
			strcpy(numero, "");
			primeiroPV = FALSE;
			segundoPV = FALSE;
			i = 0;
		}
	}
	//printf("\nSaiu\n");
}

//Consulta todos os candidatos distritais ou regionais dado um estado
void por_estado(){
	
	int8_t estado;
	FILE *fp;
	
	limpa_tela();
	
	printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
	scanf("%hhd", &estado);
	
	while ((estado != DF) && (estado != GO) && (estado != MS)){
		printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
		scanf("%hhd", &estado);
		
	}
	
	//Limpa o buffer do teclado
	if ((OS == 0) || (OS == 2))
		flush_in_std();
	else 
		fflush(stdin);
	
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
	
	print_file(fp);
	
	//getchar();
	
	fclose(fp);
}

//Faz a busca por um candidato pra saber seu número para votar
void por_numero(){
	
	int8_t estado;
	FILE *fp;
	char numero[10];
	
	limpa_tela();
	
	printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
	scanf("%hhd", &estado);
	
	while ((estado != DF) && (estado != GO) && (estado != MS)){
		printf("Qual estado deseja consultar?\n(1) Distrito Federal (DF)\n(2) Goiás (GO)\n(3) Mato Grosso do Sul (MS)\nEstado: ");
		scanf("%hhd", &estado);	
	}
	
	printf("Qual o número do candidato que deseja consultar?");
	scanf("%s", numero);
	
	//Limpa o buffer do teclado
	if ((OS == 0) || (OS == 2))
		flush_in_std();
	else 
		fflush(stdin);
	
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
	
	localizar_candidato(fp, numero);
	
	getchar();
	
	fclose(fp);
}

//Consulta todos os candidatos de um determinado partido de um estado
void do_estado(){
	
}
