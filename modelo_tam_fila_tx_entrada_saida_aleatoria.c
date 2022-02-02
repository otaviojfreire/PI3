/*
 ============================================================================
 Name        : modelo_tam_fila_tx_entrada_saida_aleatoria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int fila_A = 200;
int fila_B = 0;
int tx_A =0;
int tx_B =0;
char acao[15];
int open_A=0,open_B=0;


void gerador_veiculo_A(){

	fila_A = fila_A + (rand()%10);
}

void gerador_veiculo_B(){

	fila_B = fila_B + (rand()%10);
}

char*  controlador(int obs){

	if(obs==3){
		obs = (rand()%2);
	}

	if(obs==1){
		return "aberto A";
	}
	else {
		return "aberto B";
	}



}



int ambiente_observacao(){
	if(fila_A>fila_B){
		return 1;
	}

	else if(fila_B>fila_A)
		return 0;

	else
		return 3;
}




int ambiente_simul(char* acao){
	if (strcmp(acao,"aberto A")==0){
		if(fila_A<0){
			gerador_veiculo_A();
			fila_B +=rand()%3;

		}
		else{
			tx_A = (rand()%15);
			fila_A -= tx_A;
			gerador_veiculo_A();
			fila_B +=rand()%3;

		}
		open_A++;

	}
	else if(strcmp(acao,"aberto B")==0){
		if(fila_B<0){
			gerador_veiculo_B();
			fila_A +=rand()%3;


		}
		else{
			tx_B = (rand()%15);
			fila_B -= tx_B;
			gerador_veiculo_B();
			fila_A +=rand()%3;
		}
		open_B++;
	}
	else{

	}
	return fila_A + fila_B;
}

int fila_vazia_A(){
	if(fila_A<0)
		fila_A=0;
	return fila_A;
}
int fila_vazia_B(){
	if(fila_B<0)
		fila_B=0;
	return fila_B;
}

int main(void) {
	int i=1;
	int  obs = 0;

	printf("Fila_A=%d,Fila_B=%d\n",fila_A,fila_B);

	srand(time(NULL));


	while(fila_A>0||fila_B>0){
		fila_vazia_A();
		fila_vazia_B();
		obs = ambiente_observacao();
		ambiente_simul(controlador(obs));
		fila_vazia_A();
		fila_vazia_B();
		printf("Tempo = %d, situação %s, A = %d,B = %d\n",i,controlador(obs),fila_A,fila_B);

		i++;
	}
	return 0;
}
