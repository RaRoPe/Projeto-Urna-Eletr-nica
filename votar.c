#include "votar.h"

void votar_estadual(int8_t estado){

	int32_t codigo;
	bool valido;
	FILE *fp;

	switch (estado){
		case DF:
			limpa_tela();

			valido = true;

			printf("\t\t\tVOTO PARA CANDIDATO DISTRITAL\n\n");
			
			while (valido == true){
				printf("Digite o código do candidato que deseja votar: ");
				scanf("%d", &codigo);
				while (codigo > 100 || codigo < 0 || codigo > UINT16_MAX){
					printf("Código inválido. Digite novamente o código do candidato a distrital: ");
					scanf("%d", &codigo);
				}
			//Fazer uma busca no DB pra pedir pro eleitor confirmar o candidato. Caso não seja, digitar outro código.
			valido = false; //Caso o eleitor esteja de acordo, mudar o valor de valido
			}
			//Faz a votação do eleitor no arquivo votos
			fp = fopen("votos.txt","a+");
			fprintf(fp,"%d\n",codigo); //Adaptar para o codigo;nome_do_candidato;codigo_do_partido
			fclose(fp);
			break;
		case GO:
			limpa_tela();

			valido = true;

			printf("\t\t\tVOTO PARA CANDIDATO REGIONAL\n\n");
			
			while (valido == true){
				printf("Digite o código do candidato que deseja votar: ");
				scanf("%d", &codigo);
				while (codigo > 100 || codigo < 0 || codigo > UINT16_MAX){
					printf("Código inválido. Digite novamente o código do candidato a regional: ");
					scanf("%d", &codigo);
				}
			//Fazer uma busca no DB pra pedir pro eleitor confirmar o candidato. Caso não seja, digitar outro código.
			valido = false; //Caso o eleitor esteja de acordo, mudar o valor de valido
			}
			//Faz a votação do eleitor no arquivo votos
			fp = fopen("votos.txt","a+");
			fprintf(fp,"%d\n",codigo); //Adaptar para o codigo;nome_do_candidato;codigo_do_partido
			fclose(fp);
			break;
		case MS:
			limpa_tela();

			valido = true;

			printf("\t\t\tVOTO PARA CANDIDATO REGIONAL\n\n");
			
			while (valido == true){
				printf("Digite o código do candidato que deseja votar: ");
				scanf("%d", &codigo);
				while (codigo > 100 || codigo < 0 || codigo > UINT16_MAX){
					printf("Código inválido. Digite novamente o código do candidato a regional: ");
					scanf("%d", &codigo);
				}
			//Fazer uma busca no DB pra pedir pro eleitor confirmar o candidato. Caso não seja, digitar outro código.
			valido = false; //Caso o eleitor esteja de acordo, mudar o valor de valido
			}
			//Faz a votação do eleitor no arquivo votos
			fp = fopen("votos.txt","a+");
			fprintf(fp,"%d\n",codigo); //Adaptar para o codigo;nome_do_candidato;codigo_do_partido
			fclose(fp);
			break;
	}
}

void votar_federal(){

	int32_t codigo;

}

void votar(){
	
	int8_t estado;
	
	estado = saberEstado();

	votar_estadual(estado);
	votar_federal();
}
