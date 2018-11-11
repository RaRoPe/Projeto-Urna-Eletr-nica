#if !defined(DF) || !defined(GO) || !defined(MS)
	#define DF 1
	#define GO 2
	#define MS 3
#endif

char *muda_partido(char partido[3]);
void localizar_candidato(FILE *fp, char numero[10]);
void print_file(FILE *fp);
void por_estado();
void por_numero();
void do_estado();
