/*
 ============================================================================
 Name        : Controlador de Sem�foro(Tamanho de Fila,IN e OUT fixo)
 Author      : Ot�vio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Controlador de Tr�nsito com a seguinte pol�tica: O sem�foro estar�
 aberto para rua que apresentar� a maior fila de carros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*fila A*/
int carro_A = 15;
/*fila B*/
int carro_B = 15;
/*Taxa de Sa�da A*/
int tx_out_A = 5;
/*Taxa de Sa�da B*/
int tx_out_B = 5;
/*Taxa de entrada A*/
int tx_in_A = 2;
/*Taxa de entrada B*/
int tx_in_B = 2;
/*A��o do controlador*/
char acao[15];

/*controlador de tr�nsito*/
char*  controlador(int obs){

	if(obs==3){
		srand(time(NULL));
		obs = (rand()%2);
	}

	if(obs==1){
		return "aberto A";
	}
	else if(obs==0){
		return "aberto B";
	}

	else{
		return "igual";

	}

}


/*ambiente de observa��o verifica a maior fila de carros*/
int ambiente_observacao(){
	if(carro_A>carro_B){
		return 1;
	}

	else if(carro_B>carro_A)
		return 0;

	else
		return 3;
}



/*representa o comportamento do sistema*/
int ambiente_simul(char* acao){
	/*Controlador retornou sua decis�o, Aberto A*/
	if (strcmp(acao,"aberto A")==0){
		/*Fila A vazia, apenas h� entrada de carros na fila A*/
		if(carro_A<0){
			carro_A += 2;

		}
		/* Caso contr�rio, h� entrada e sa�da no sitema*/
		else{
			carro_A -= tx_out_A;
			carro_A += tx_in_A;
		}

	}
	/*Controlador retornou sua decis�o, Aberto B*/
	else if(strcmp(acao,"aberto B")==0){
		/*fila vazia B, h� apenas entrada na fila*/
		if(carro_B<0){
			carro_B += tx_in_B;

		}
		/*caso contr�rio, h� entrada e sa�da da fila*/
		else{
			carro_B -= tx_out_B;
			carro_B += tx_in_B;
		}
	}
	else{

	}
	return carro_A + carro_B;
}

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
		/*prote��o de fila vazia*/
		fila_vazia_A();
		fila_vazia_B();
		i++;
		printf("Tempo = %d, situa��o %s, A = %d,B = %d\n",i,controlador(obs),carro_A,carro_B);


	}

	return 0;
}
