#define FALSE false
#define TRUE true

char* itoa(int64_t i, char b[]);
bool verifica_quantidade_simbolos(char *CPF);
bool verifica_primeiro_digito(char CPF[12]);
bool verifica_segundo_digito(char CPF[12]);
bool valida_CPF(char *CPF);
