#if !defined(DF) || !defined(GO) || !defined(MS)
	#define DF 1
	#define GO 2
	#define MS 3
#endif

char *muda_partido(char partido[3]);
void localizar_partido(int8_t estado);
bool localizar_candidato(int32_t numero, int8_t estado, int8_t *partido_candidato);
void print_file(int8_t estado);
void por_estado();
void por_numero();
void do_estado();
