#ifdef __linux__
	#define OS 0
#elif _WIN32 || _WIN64
	#define OS 1
#elif __APPLE__
	#define OS 2
#endif

#if !defined(DF) || !defined(GO) || !defined(MS)
	#define DF 1
	#define GO 2
	#define MS 3
#endif

int8_t printa_menu();
int8_t saberEstado();
void limpa_tela();
void main();
