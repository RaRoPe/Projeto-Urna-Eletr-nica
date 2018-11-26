#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <sys/time.h>
//#include <inttypes.h>

#include "flush_in.c"

#define MAXSIZE 800000

/* Exemplo de arquivo .txt
 * wabba wabba 
 * Formato do arquivo comprimido
 * <índice, letra_do_alfabeto>
 * 0,w
 * 0,a
 * 0,b
 * 3,a
 * 0,\s
 * 1,a
 * 2,b
 * 2,
*/

int stack[MAXSIZE];
int top = -1;

int isempty(){
	if(top == -1) return 1;
	else return 0;
}

int isfull(){
	if(top == MAXSIZE) return 1;
	else return 0;
}

int peek(){
	return stack[top];
}

int pop(){
	int data;
	
	if(!isempty()){
		data = stack[top];
		top = top - 1;   
		return data;
	}
	else
		printf("A pilha está vazia!\n");
}

int push(int data){
	if(!isfull()){
		top = top + 1;   
		stack[top] = data;
	}
	else
		printf("A pilha está cheia!\n");
}

void uncompress(FILE **fp, char *nome_arquivo){
	
	FILE *fp2, *fp3;
	
	char c, char_lido;
	long long int index = 0, index_aux = 0, linha_salva = 0, linha = 1, qtd_linhas = 1;
	int ret = 0, executa_pop = 0, parada = 0;
	
	*fp = fopen(nome_arquivo, "r");
	
 	if (*fp == NULL){
 		exit(0);
 	}
 	
 	fp2 = fopen("saida8.txt", "w+");
	
	fp3 = fopen("auxiliar.txt", "w+");
	
 	while (fscanf(*fp, "%lld,%c\n", &index, &char_lido) != EOF){
// 		printf("INDEX = %lld, CHAR_LIDO = %c\n", index, char_lido);
		if (index == 0){
			if (char_lido != '?')
				fprintf(fp2, "%c", char_lido);
			else
				fprintf(fp2, "\n");
// 			printf("INSERIU!\n");
			while ((c = getc(fp3)) != EOF){
				executa_pop = 1;
// 				printf("c = %c", c);
				push(c);
			}
			if (executa_pop == 1){
				while (isempty() != -1){
					c = pop();
					fprintf(fp3, "%c", c);
				}
				fclose(fp3);
				fp3 = fopen("auxiliar.txt", "w+");
			}
			executa_pop = 0;
			qtd_linhas = 1;
		}
		else {
			index_aux = index;
			fprintf(fp3, "%c", char_lido);
			rewind(*fp);
			while (parada == 0){
// 				printf("QTD_LINHAS = %lld\n", qtd_linhas);
				if (qtd_linhas != index_aux){
					fscanf(*fp, "%lld,%c\n", &index, &char_lido);
// 					printf("PROCURA LINHA = %lld,%c\n", index, char_lido);
					qtd_linhas+=1;
				}
				else {
					ret = fscanf(*fp, "%lld,%c\n", &index, &char_lido);
// 					printf("INDEX = %lld, CHAR_LIDO = %c\n", index, char_lido);
					if (ret == EOF){
						exit(0);
					}
					qtd_linhas = 1;
					index_aux = index;
					fprintf(fp3, "%c", char_lido);
					rewind(*fp);
					if (index_aux == 0)
						parada = 1;
// 					getchar();
				}
			}
			rewind(fp3);
// 			printf("String do arquivo = ");
			while ((c = getc(fp3)) != EOF){
				executa_pop = 1;
// 				printf("%c", c);
				push(c);
			}
// 			printf("\n");
			
			if (executa_pop == 1){
				while (isempty() != 1){
					c = pop();
					if (c != '?')
						fprintf(fp2, "%c", c);
					else
						fprintf(fp2, "\n");
				}
			}
			
			executa_pop = 0;
			parada = 0;
			
			fclose(fp3);
			fp3 = fopen("auxiliar.txt", "w+");
// 			linha_salva = linha*4;
//  			printf("LINHA ATUAL = %lld\n", linha);
// 			if (linha_salva == 92)
// 				linha_salva += 4;
// 			fseek(*fp, linha_salva, SEEK_SET);
			rewind(*fp);
			while (linha_salva != linha){
				c=getc(*fp);
				if (c == '\n')
					linha_salva += 1;
				if (c == EOF)
					break;
			}
			linha_salva = 0;
		}
		linha+=1;
//  		getchar();
	}
	
	fclose(*fp);
	fclose(fp2);
	fclose(fp3);
}

void compress(FILE **fp, char *nome_arquivo){
	
	FILE *fp2;
	
	char c, char_lido;
	long long int index = 0, index_aux = 0, linha = 1;
	int ret = 1;
	
 	*fp = fopen(nome_arquivo, "r");
	
 	if (*fp == NULL){
 		printf("[-] Arquivo inexistente.\n");
 		exit(0);
 	}
	
  	fp2 = fopen("compress9.lz78", "w+");
	
	while ((c = getc(*fp)) != EOF){
		while (fscanf(fp2, "%lld,%c\n", &index, &char_lido) != EOF){
   			if ((c == char_lido) && (index_aux == index)){
   				index_aux = linha;
				ret = 0;
   				break;
   			}
   			linha +=1;
		}
		if (ret == 1) {
			if (c != 10)
				fprintf(fp2, "%lld,%c\n", index_aux, c);
			else 
				fprintf(fp2, "%lld,?\n", index_aux);
			index_aux = 0;
		}
  		rewind(fp2);
 		linha = 1;
 		ret = 1;
	}
	fclose(*fp);
	fclose(fp2);
}

int main(int argc, char *argv[]){
	
//  	flush_in_std();
	
	int tempo_inicio, tempo_final, tempo_decorrido;
	
	FILE *fp;
	
	if (argc == 1){
		printf( "\nMenu de ajuda\nA execução deverá ser feita utilizando:"
		"\n./<EXEC> <ARQ> <C/U>\n\t<EXEC>\tNome do executável\n\t"
		"<ARQ>\tNome do arquivo para compactação ou descompactação\n\t"
		"<C/U>\tC = Comprimir. U = Descomprimir\n\n"
		"Para visualizar a ajuda use ./prog -h ou ./prog --help\n\n");
		return 0;
	}
	
	if ((strcmp(argv[1],"-h") == 0)||(strcmp(argv[1],"--help") == 0)||(argc==1)||(argc > 3)){
		printf( "\nMenu de ajuda\nA execução deverá ser feita utilizando:"
		"\n./<EXEC> <ARQ> <C/U>\n\t<EXEC>\tNome do executável\n\t"
		"<ARQ>\tNome do arquivo para compactação ou descompactação\n\t"
		"<C/U>\tC = Comprimir. U = Descomprimir\n\n"
		"Para visualizar a ajuda use ./prog -h ou ./prog --help\n\n");
		return 0;
	}
	
	if (strcmp(argv[2], "C") == 0){
		
		system("clear");
		printf("\t\t\t\tATENÇÃO!!!\n\n"
			"O arquivo a ser compactado não pode ter ? em sua composição.\n"
			"Havendo o caracter, por favor retire-o e substitua por outro caracter.\n"
			"\n\t\t\tDesculpe pelo transtorno.\nObrigado!\n\n"
			"PRESSIONE ENTER PARA CONTINUAR");
		getchar();
		printf("Compactando....\n");
		
// 		tempo_inicio = time(NULL);
		struct timeval start, stop;
		double secs = 0;
		gettimeofday(&start, NULL);
		
		compress(&fp, argv[1]);
		
		gettimeofday(&stop, NULL);
		secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
		
// 		tempo_final = time(NULL);
// 		tempo_decorrido = difftime(tempo_final,tempo_inicio);
		printf("Time taken %f\n",secs);
// 		printf("Tempo decorrido = %ds\n", tempo_decorrido);
	}
	else if (strcmp(argv[2], "U") == 0){
		
		system("clear");
		printf("Descompactando....\n");
		
// 		tempo_inicio = time(NULL);
		struct timeval start, stop;
		double secs = 0;
		gettimeofday(&start, NULL);
		
		uncompress(&fp, argv[1]);
		
		gettimeofday(&stop, NULL);
		secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
		
// 		tempo_final = time(NULL);
// 		tempo_decorrido = difftime(tempo_final,tempo_inicio);
		printf("Time taken %f\n",secs);
	}
	else{
		printf("[-] Invalid Argument!\n");
		return 0;
	}
	
	return 0;
}
