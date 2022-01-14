/*
 ============================================================================
 Name        : Controlador de Semáforo(Tamanho de Fila,IN e OUT fixo)
 Author      : Otávio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Controlador de Trânsito com a seguinte política: O semáforo estará
 aberto para rua que apresentará a maior fila de carros.
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
/*Taxa de Saída A*/
int tx_out_A = 5;
/*Taxa de Saída B*/
int tx_out_B = 5;
/*Taxa de entrada A*/
int tx_in_A = 2;
/*Taxa de entrada B*/
int tx_in_B = 2;
/*Ação do controlador*/
char acao[15];

/*controlador de trânsito*/
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


/*ambiente de observação verifica a maior fila de carros*/
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
	/*Controlador retornou sua decisão, Aberto A*/
	if (strcmp(acao,"aberto A")==0){
		/*Fila A vazia, apenas há entrada de carros na fila A*/
		if(carro_A<0){
			carro_A += 2;

		}
		/* Caso contrário, há entrada e saída no sitema*/
		else{
			carro_A -= tx_out_A;
			carro_A += tx_in_A;
		}

	}
	/*Controlador retornou sua decisão, Aberto B*/
	else if(strcmp(acao,"aberto B")==0){
		/*fila vazia B, há apenas entrada na fila*/
		if(carro_B<0){
			carro_B += tx_in_B;

		}
		/*caso contrário, há entrada e saída da fila*/
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


	/*o laço acontecerá até a fila A e fila B zerarem*/
	while(carro_A>0||carro_B>0){
		/*Proteção de fila vazia*/
		fila_vazia_A();
		fila_vazia_B();
		/*ambiente de observação envia sua verificação do sistema*/
		obs = ambiente_observacao();
		/*controlador realiza uma ação baseado na observação e acontece alterações no sistema*/
		ambiente_simul(controlador(obs));
		/*proteção de fila vazia*/
		fila_vazia_A();
		fila_vazia_B();
		i++;
		printf("Tempo = %d, situação %s, A = %d,B = %d\n",i,controlador(obs),carro_A,carro_B);


	}

	return 0;
}
