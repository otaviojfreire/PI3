/*
 ============================================================================
 Name        : Modelo Tamanho de Fila
 Author      : Otávio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define gerador 5
#define saida 10
#define ciclo 40
#define X 200
#define A 0
#define B 10


int  fila_A = A;
int fila_B = B;
int tx_A =0;
int tx_B =0;
char acao[15];
int open_A=0,open_B=0;




void gerador_veiculo_A(){

	fila_A = fila_A +  (rand()%gerador);

}

void gerador_veiculo_B(){

	fila_B = fila_B + (rand()%gerador);
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

void ambiente_simul(){
	int A_aberto=15,A_fechado=0;
	int B_aberto=15,B_fechado = 0;

	//aberto para fila A por 15 ciclos
	while(A_aberto--){
		fila_vazia_A();
		if(fila_A==0)
			A_aberto=0;

		if(fila_A>10)
			fila_A = 10;

		tx_A = (rand()%saida);
		fila_A -= tx_A;
		fila_vazia_A();
		gerador_veiculo_A();

		if(fila_A>10)
			fila_A = 10;

		gerador_veiculo_B();

		if(fila_B>10)
			fila_B = 10;
		B_fechado++;

	}


	//aberto para fila B por 15 ciclos
	while(B_aberto--){
		//verifica fila vazia
		fila_vazia_B();
		//fila vazia sair do loop
		if(fila_B==0)
			B_aberto=0;
		//proteção para não passar de 10 na fila
		if(fila_B>10)
			fila_B = 10;
		tx_B = (rand()%saida);
		fila_B -= tx_B;
		fila_vazia_B();
		gerador_veiculo_B();
		if(fila_B>10)
			fila_B = 10;
		gerador_veiculo_A();
		if(fila_A>10)
			fila_A = 10;


		A_fechado++;

	}




}



int main(void) {
	int i=1,m=1,soma_A=0,soma_B=0;
	//int  obs = 0;

	printf("Fila_A=%d,Fila_B=%d\n",fila_A,fila_B);

	srand(time(NULL));

	while(m<=X){
		while(i<=ciclo){

			fila_vazia_A();
			fila_vazia_B();
			ambiente_simul();
			printf("Tempo = %d, A = %d,B = %d\n",i,fila_A,fila_B);


			i++;
		}

		printf("\n");
		soma_A += fila_A;
		soma_B += fila_B;
		fila_A = A;
		fila_B = B;
		printf("Fila_A=%d,Fila_B=%d\n",fila_A,fila_B);
		i = 1;
		m++;

	}

	printf("Media A: %f, Media B: %f: \n",(float)soma_A/m,(float)soma_B/m);
	return 0;

}

