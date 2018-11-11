#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define MAX_VALUE 8376535
#define ZERO 0

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

//Fazer a função comprimir o arquivo texto
//void compress(FILE *fp){
//	char c;
  

//}

//Função de descomprimir o arquivo .lz78
void compress(FILE **fp, FILE **fp2, char *nome_arquivo){
	
	char c, char_lido;
	long long int index = 0, index_aux = 0, linha = 1, OFFSET = 0;
	//int64_t linha = 1;
	int ret;
	
 	*fp = fopen(nome_arquivo, "r");
	
	//Verifica existência do arquivo de leitura
 	if (*fp == NULL){
 		printf("[-] Arquivo inexistente.\n");
 		exit(0);
 	}
	
 	*fp2 = fopen("compress.lz78", "w");
	
	while ((c = getc(*fp)) != EOF){
		while (ret != EOF){
			ret = fscanf(*fp2, "%lld,%c", &index, &char_lido);
			if (c == char_lido && index_aux == index){
				index_aux = linha;
				break; //Quebra o loop para procurar pela próxima letra lida do arquivo1.
			}
			linha +=1;
		}
		fprintf(*fp2, "%lld,%c", index_aux, c);
		rewind(*fp2);
		linha = 0;
	}
	
	/*
	fp2 = fopen("compress.lz78", "a");
	
	//Percorre o arquivo para saber a quantidade de caracteres dele
  	while ((c = getc(fp2)) != EOF){
 		printf("OFFSET = %lld\n", OFFSET);
 		OFFSET += 1;
  	}
	
	//Volta na posição do EOF e printa o último caracter no arquivo
  	fseek(fp2, OFFSET, SEEK_SET);
	
	//Printa o último caracter no dicionário
 	fprintf(fp2, "\n%lld,", index_aux);
	
 	fclose(fp2);*/
	
}

int main(int argc, char *argv[]){
	
	FILE *fp, *fp2;
	
	compress(&fp, &fp2, argv[1]);
	
 	fclose(fp);
 	fclose(fp2);
	return 0;
}