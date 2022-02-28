/*
 ============================================================================
 Name        : Modelo Tamanho de Fila
 Author      : Ot�vio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Modelo de sem�foro com a pol�tica de abertura e
 fechamento pelo tamanho de fila
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//define valor inicial para fila A
#define A 0
//define valor inicial para fila B
#define B 0
//define a quantidade de per�odos de simula��o
#define X 240
//define o n�mero de vezes que ser� simulado(tentativas)
#define Y 100
//define per�odo de semaforo A aberto
#define K 100
//define pe�riodo de sem�for B aberto
#define Z 1


//representa a fila de ve�culos da rua A
int fila_A = A;
//representa a fila de ve�culos da rua B
int fila_B = B;
//representa a taxa de sa�da no sistema(ve�culos/per�odo de tempo)
int taxa_saida=0;
//representa a taxa de entrada no sistema(ve�culos/per�odo de tempo)
int taxa_entrada=0;
//representa a decis�o tomada pelo controlador(aberto A/aberto B)
char acao[15];
int open_A=0,open_B=0;



//fun��o de prote��o, evitar fila com valor negativo(A)
int fila_vazia_A(){
	if(fila_A<0)
		fila_A=0;
	return fila_A;
}
//fun��o de prote��o, evitar fila com valor negativo(B)
int fila_vazia_B(){
	if(fila_B<0)
		fila_B=0;
	return fila_B;
}

//Gera um taxa de entrada com valores aleat�rios entre 0-4(ve�culos/per�odo de tempo)
void gerador_veiculo(){

	taxa_entrada = (rand()%5);
}

/*Gera um taxa de sa�da com valores aleat�rios entre 0-9(ve�culos/per�odo de tempo)
 * Primeiramente � sorteado um n�vel de tempo de rea��o dos motoristas em quest�o
 * Se o n�vel sorteedo for 0 ent�o a taxa de sa�da do sistema ser� entre 8-9(ve�culos/per�odo de tempo)
 * Se o n�vel sorteado for 1 ent�o a taxa de sa�da do sistema ser� entre 6-7(ve�culos/per�odo de tempo)
 * Se o n�vel sorteado for 2 ent�o a taxa de sa�da do sistema ser� entre 4-5(ve�culos/per�odo de tempo)
 * Se o n�vel sorteado for 3 ent�o a taxa de sa�da do sistema ser� entre 2-3(ve�culos/per�odo de tempo)
 * Se o n�vel sorteado for 4 ent�o a taxa de sa�da do sistema ser� entre 0-1(ve�culos/per�odo de tempo)
 */
void taxa_saida_veiculo(){
	int temp_rea = rand()%5;
	if(temp_rea==0)
		taxa_saida = rand()%10+8;
	else if(temp_rea==1)
		taxa_saida = rand()%8+6;
	else if(temp_rea==2)
		taxa_saida = rand()%6+4;
	else if(temp_rea==3)
		taxa_saida = rand()%4+2;
	else
		taxa_saida = rand()%2;

}



int main(void) {
	int m=0;
	//vari�veis para somar a quantidade de ve�culos presente nas filas
	// durante o per�odo de tempo total de simula��o
	int soma=0,soma_b=0;
	//vari�veis para somar a as m�dias de ve�culos presente nas filas
	//durante todas tentativa de simula��o
	int sa=0,sb=0;
	//vari�vel de incrente do total de tentativas de simula��o
	int h=0;
	//semente para gerar n�meros aleat�rios
	srand(time(NULL));









	while(h!=Y){

		gerador_veiculo();
		fila_A += taxa_entrada;
		soma = soma + fila_A;
		gerador_veiculo();
		fila_B += taxa_entrada;
		soma_b = soma_b + fila_B;
		m = 0;

		//printf("Fila_A=%d,Fila_B=%d\n",fila_A,fila_B);
		while(m!=X){




			int j = K;
			while(j!=0){
				/*� gerado uma taxa de sa�da
				 */
				taxa_saida_veiculo();
				/*� retirado ve�culos por per�odo na fila A
				 */
				fila_A -= taxa_saida;
				/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
				de simula��o na fila A
				 */
				fila_vazia_A();




				gerador_veiculo();
				/*� adicionado ve�culos por per�odo na fila A
				 */
				fila_A += taxa_entrada;
				/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
				de simula��o na fila A
				 */
				soma = soma + fila_A;
				/*� gerado uma taxa de entrada
				 */
				gerador_veiculo();
				/*� adicionado ve�culos por per�odo na fila B
				 */
				fila_B +=taxa_entrada;
				/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
				de simula��o na fila B
				 */
				soma_b = soma_b + fila_B;
				j--;
				m++;
				if(m>=X){
					m = X;
					j = 0;
				}

				//printf("Tempo = %d, situa��o Aberto A, A = %d,B = %d\n",m,fila_A,fila_B);
			}

			j = Z;


			while(j!=0){
				/*� gerado uma taxa de sa�da
				 */
				taxa_saida_veiculo();
				/*� retirado ve�culos por per�odo na fila A
				 */
				fila_B -= taxa_saida;
				/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
				de simula��o na fila A
				 */
				fila_vazia_B();




				gerador_veiculo();
				/*� adicionado ve�culos por per�odo na fila A
				 */
				fila_B += taxa_entrada;
				/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
				de simula��o na fila A
				 */
				soma_b = soma_b + fila_B;
				/*� gerado uma taxa de entrada
				 */
				gerador_veiculo();
				/*� adicionado ve�culos por per�odo na fila B
				 */
				fila_A +=taxa_entrada;
				/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
				de simula��o na fila B
				 */
				soma = soma + fila_A;
				j--;
				m++;
				if(m>=X){
					m = X;
					j = 0;
				}

					printf("Tempo = %d, situa��o Aberto B, A = %d,B = %d\n",m,fila_A,fila_B);
			}






		}

		sa+= soma/m;
		sb +=soma_b/m;
		fila_A = A;
		fila_B = B;



		h++;
		//impress�o da m�dia de ve�culos das filas em cada tentativa de simula��o
		printf("Tentativa( %d)  M�dia Ve�culo A: %f,M�dia Veiculo B: %f por %d periodos de tempo\n",h,(float)soma/m,(float)soma_b/m,X);
		soma = 0;
		soma_b = 0;


	}
	//impress�o da m�dia de ve�culos nas filas em rela��o a todas as tentativas
	printf("M�dia Ve�culo A: %f,M�dia Veiculo B: %f por %d per�odos de tempo em %d tentativas\n",(float)sa/h,(float)sb/h,X,Y);
	return 0;

}
