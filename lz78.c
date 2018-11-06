#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <inttypes.h>

#include "flush_in.c"

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
 * 2,\s
*/

//Fazer a função comprimir o arquivo texto
//void compress(FILE *fp){
//	char c;
  

//}

//Função de descomprimir o arquivo .lz78
void compress(FILE **fp, char *nome_arquivo){
	
	FILE *fp2;
	
	char c, char_lido;
	long long int index = 0, index_aux = 0, linha = 1;
	int ret = 1;
	
 	*fp = fopen(nome_arquivo, "r");
	
	//Verifica existência do arquivo de leitura
 	if (*fp == NULL){
 		printf("[-] Arquivo inexistente.\n");
 		exit(0);
 	}
	
  	fp2 = fopen("compress.lz78", "w+");
	
	while ((c = getc(*fp)) != EOF){
		while (fscanf(fp2, "%lld,%c\n", &index, &char_lido) != EOF){
    			printf("INDEX,CHAR_LIDO = %lld,%c\n", index, char_lido);	
   			if ((c == char_lido) && (index_aux == index)){
   				index_aux = linha;
				ret = 0;
   				break; //Quebra o loop para procurar pela próxima letra lida do arquivo1.
   			}
   			linha +=1;
		}
		printf("\n");
		if (ret == 1) {//Se não achou uma dupla no dicionário escreve
			fprintf(fp2, "%lld,%c\n", index_aux, c);
			index_aux = 0;
		}
//   		fseek(*fp2, 0 , SEEK_SET);
  		rewind(fp2); //Pode colocar dentro do if do ret
 		linha = 1;
 		ret = 1;
//  		getchar();
	}
	fclose(fp2);
}

int main(int argc, char *argv[]){
	
 	flush_in_std();
	
	FILE *fp;
	
	compress(&fp, argv[1]);
	
 	fclose(fp);
	return 0;
}