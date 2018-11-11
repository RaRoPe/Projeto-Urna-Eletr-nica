#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main(int argc, char *argv[]){
	
	FILE *fp;

	char char_lido;
	int ret = 0;
	long long int index;

	fp = fopen("a.txt", "r");

	fprintf(fp, "%lld,%c\n", index, char_lido);
 	fprintf(fp, "%lld,%c\n", index, char_lido);
	rewind(fp);
	fscanf(fp, "%lld,%c", &index, &char_lido);
	printf("--INDEX,CHAR_LIDO = %lld,%c\n", index, char_lido);
//	fprintf(fp, "%lld,%c\n", index_aux, c);
//  		fseek(*fp2, 0 , SEEK_SET);
	rewind(fp);
	fclose(fp);

	return 0;
}
