/*
 ============================================================================
 Name        : Controlador de Semáforo(Política Aleatória,IN e OUT fixo)
 Author      : Otávio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Controlador de Trânsito com a seguinte política: A decisão para abertura e fechamento
 é feito de forma aleatória.
  ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int carro_A = 15;
int carro_B = 15;
char acao[15];
/*controlador de trânsito: Abertura de forma aleatória*/
char*  controlador(int obs){

	if(obs==1){
		return "aberto A";
	}
	else
		return "aberto B";


}


/*é feito um sorteio na observação*/
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


	/*o laço acontecerá até a fila A e fila B zerarem*/
	while(carro_A>0||carro_B>0){
		/*Proteção de fila vazia*/
		fila_vazia_A();
		fila_vazia_B();
		/*ambiente de observação envia sua verificação do sistema*/
		obs = ambiente_observacao();
		/*controlador realiza uma ação baseado na observação e acontece alterações no sistema*/
		ambiente_simul(controlador(obs));
		fila_vazia_A();
		fila_vazia_B();
		i++;
		printf("Tempo = %d, situação %s, A = %d,B = %d\n",i,controlador(obs),carro_A,carro_B);

	}

	return 0;
}
