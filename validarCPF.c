#include "validarCPF.h"

char* itoa(int64_t i, char b[]) {
	char const digit[] = "0123456789";
	char *p = b;
	
	if (i<0) {
		*p++ = '-';
		i = -i;
	}
	
	int shifter = i;
	
	do {
		++p;
		shifter = shifter/10;
	} while (shifter);
	
	*p = '\0';
	
	do {
		*--p = digit[i%10];
		i = i/10;
	} while (i);
	
	return b;
}

bool verifica_quantidade_simbolos(char *CPF){
	int16_t tamanho_CPF;
	
	tamanho_CPF = strlen(CPF);
 	//printf("Tamanho CPF = %hd\n", tamanho_CPF);
	if (tamanho_CPF != 11)
// 	printf("CPF = %ld\n", CPF);
	//if (CPF < 10000000000 || CPF > 99999999999)
		return FALSE;
	else
		return TRUE;
}

bool verifica_primeiro_digito(char CPF[12]){
	
	int16_t resultado, tamanho_CPF = 0;
	
	int16_t DEC_digit;
	
	resultado = (CPF[0]-'0')*10 + (CPF[1]-'0')*9 + (CPF[2]-'0')*8 + (CPF[3]-'0')*7 + (CPF[4]-'0')*6 + (CPF[5]-'0')*5 + (CPF[6]-'0')*4 + (CPF[7]-'0')*3 + (CPF[8]-'0')*2;
	
	resultado *= 10;
	resultado %= 11;
	
	if (resultado == 10)
		resultado = 0;
	
	DEC_digit = CPF[9]-'0'; //Convert char to int
	
	//printf("Resultado = %hd, %d\n", resultado, DEC_digit);
	
	if (resultado == DEC_digit)
		return TRUE;
	
	return FALSE;
	
}

bool verifica_segundo_digito(char CPF[12]){
	
	int16_t resultado, tamanho_CPF = 0;
	
	int16_t DEC_digit;
	
	resultado = (CPF[0]-'0')*11 + (CPF[1]-'0')*10 + (CPF[2]-'0')*9 + (CPF[3]-'0')*8 + (CPF[4]-'0')*7 + (CPF[5]-'0')*6 + (CPF[6]-'0')*5 + (CPF[7]-'0')*4 + (CPF[8]-'0')*3 + (CPF[9]-'0')*2;
	
	//printf("RES = %hd\n", resultado/10);
	
	resultado *= 10;
	resultado %= 11;
	
	if (resultado == 10)
		resultado = 0;
	
	DEC_digit = CPF[10]-'0'; //Convert char to int
	
	//printf("Resultado = %hd, %d\n", resultado, DEC_digit);
	
	if (resultado == DEC_digit)
		return TRUE;
	
	return FALSE;
	
}

bool valida_CPF(char *CPF){
	
	bool validacao = TRUE;
	
	validacao = verifica_quantidade_simbolos(CPF);
	
	if (validacao == FALSE)
		return FALSE;
	
	validacao = verifica_primeiro_digito(CPF);
	
	if (validacao == FALSE)
		return FALSE;
	
	validacao = verifica_segundo_digito(CPF);
	
	if (validacao == FALSE)
		return FALSE;
	
	return TRUE;
}
