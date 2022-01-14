/*
 ============================================================================
 Name        : Controlador de Sem�foro(Pol�tica Aleat�ria,IN e OUT fixo)
 Author      : Ot�vio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Controlador de Tr�nsito com a seguinte pol�tica: A decis�o para abertura e fechamento
 � feito de forma aleat�ria.
  ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int carro_A = 15;
int carro_B = 15;
char acao[15];
/*controlador de tr�nsito: Abertura de forma aleat�ria*/
char*  controlador(int obs){

	if(obs==1){
		return "aberto A";
	}
	else
		return "aberto B";


}


/*� feito um sorteio na observa��o*/
int ambiente_observacao(){
	int obs = (rand()%2);
	printf("obs=%d\n",obs);
	return obs;
}



/*representa o comportamento do sistema*/
int ambiente_simul(char* acao){
	if (strcmp(acao,"aberto A")==0){
		if(carro_A<0){
			carro_A += 9;

		}
		else{
			carro_A -= (rand()%40)+1;
			carro_A += 9;
		}

	}
	else if(strcmp(acao,"aberto B")==0){
		if(carro_B<0){
			carro_B += 9;

		}
		else{
			carro_B -= (rand()%40)+1;
			carro_B += 9;
		}
	}
	else{

	}
	return carro_A + carro_B;
}
/*Evitar valores negativos para a fila A*/
int fila_vazia_A(){
	if(carro_A<0)
		carro_A=0;
	return carro_A;
}
/*Evitar valores negativos para a fila B*/
int fila_vazia_B(){
	if(carro_B<0)
		carro_B=0;
	return carro_B;
}

int main(void) {
	int i=0;
	int  obs = 0;

	printf("Fila_A=%d,Fila_B=%d\n",carro_A,carro_B);
	/*A semente para evitar valores repetidos*/
	srand(time(NULL));


	/*o la�o acontecer� at� a fila A e fila B zerarem*/
	while(carro_A>0||carro_B>0){
		/*Prote��o de fila vazia*/
		fila_vazia_A();
		fila_vazia_B();
		/*ambiente de observa��o envia sua verifica��o do sistema*/
		obs = ambiente_observacao();
		/*controlador realiza uma a��o baseado na observa��o e acontece altera��es no sistema*/
		ambiente_simul(controlador(obs));
		fila_vazia_A();
		fila_vazia_B();
		i++;
		printf("Tempo = %d, situa��o %s, A = %d,B = %d\n",i,controlador(obs),carro_A,carro_B);

	}

	return 0;
}
