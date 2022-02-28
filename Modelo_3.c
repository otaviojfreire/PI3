/*
 ============================================================================
 Name        : Modelo Tamanho de Fila
 Author      : Otávio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Modelo de semáforo com a política de abertura e
 fechamento com tempo fixo de semáforo aberto
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
//define a quantidade de períodos de simulação
#define X 240
//define o número de vezes que será simulado(tentativas)
#define Y 100
//define período de semaforo A aberto
#define K 100
//define pe´riodo de semáfor B aberto
#define Z 1


//representa a fila de veículos da rua A
int fila_A = A;
//representa a fila de veículos da rua B
int fila_B = B;
//representa a taxa de saída no sistema(veículos/período de tempo)
int taxa_saida=0;
//representa a taxa de entrada no sistema(veículos/período de tempo)
int taxa_entrada=0;
//representa a decisão tomada pelo controlador(aberto A/aberto B)
char acao[15];
int open_A=0,open_B=0;



//função de proteção, evitar fila com valor negativo(A)
int fila_vazia_A(){
	if(fila_A<0)
		fila_A=0;
	return fila_A;
}
//função de proteção, evitar fila com valor negativo(B)
int fila_vazia_B(){
	if(fila_B<0)
		fila_B=0;
	return fila_B;
}

//Gera um taxa de entrada com valores aleatórios entre 0-4(veículos/período de tempo)
void gerador_veiculo(){

	taxa_entrada = (rand()%5);
}

/*Gera um taxa de saída com valores aleatórios entre 0-9(veículos/período de tempo)
 * Primeiramente é sorteado um nível de tempo de reação dos motoristas em questão
 * Se o nível sorteedo for 0 então a taxa de saída do sistema será entre 8-9(veículos/período de tempo)
 * Se o nível sorteado for 1 então a taxa de saída do sistema será entre 6-7(veículos/período de tempo)
 * Se o nível sorteado for 2 então a taxa de saída do sistema será entre 4-5(veículos/período de tempo)
 * Se o nível sorteado for 3 então a taxa de saída do sistema será entre 2-3(veículos/período de tempo)
 * Se o nível sorteado for 4 então a taxa de saída do sistema será entre 0-1(veículos/período de tempo)
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
	//variáveis para somar a quantidade de veículos presente nas filas
	// durante o período de tempo total de simulação
	int soma=0,soma_b=0;
	//variáveis para somar a as médias de veículos presente nas filas
	//durante todas tentativa de simulação
	int sa=0,sb=0;
	//variável de incrente do total de tentativas de simulação
	int h=0;
	//semente para gerar números aleatórios
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
				/*É gerado uma taxa de saída
				 */
				taxa_saida_veiculo();
				/*É retirado veículos por período na fila A
				 */
				fila_A -= taxa_saida;
				/*Varíavel para calcular a média de veículos no total de períodos
				de simulação na fila A
				 */
				fila_vazia_A();




				gerador_veiculo();
				/*É adicionado veículos por período na fila A
				 */
				fila_A += taxa_entrada;
				/*Varíavel para calcular a média de veículos no total de períodos
				de simulação na fila A
				 */
				soma = soma + fila_A;
				/*É gerado uma taxa de entrada
				 */
				gerador_veiculo();
				/*É adicionado veículos por período na fila B
				 */
				fila_B +=taxa_entrada;
				/*Varíavel para calcular a média de veículos no total de períodos
				de simulação na fila B
				 */
				soma_b = soma_b + fila_B;
				j--;
				m++;
				if(m>=X){
					m = X;
					j = 0;
				}

				//printf("Tempo = %d, situação Aberto A, A = %d,B = %d\n",m,fila_A,fila_B);
			}

			j = Z;


			while(j!=0){
				/*É gerado uma taxa de saída
				 */
				taxa_saida_veiculo();
				/*É retirado veículos por período na fila A
				 */
				fila_B -= taxa_saida;
				/*Varíavel para calcular a média de veículos no total de períodos
				de simulação na fila A
				 */
				fila_vazia_B();




				gerador_veiculo();
				/*É adicionado veículos por período na fila A
				 */
				fila_B += taxa_entrada;
				/*Varíavel para calcular a média de veículos no total de períodos
				de simulação na fila A
				 */
				soma_b = soma_b + fila_B;
				/*É gerado uma taxa de entrada
				 */
				gerador_veiculo();
				/*É adicionado veículos por período na fila B
				 */
				fila_A +=taxa_entrada;
				/*Varíavel para calcular a média de veículos no total de períodos
				de simulação na fila B
				 */
				soma = soma + fila_A;
				j--;
				m++;
				if(m>=X){
					m = X;
					j = 0;
				}

					printf("Tempo = %d, situação Aberto B, A = %d,B = %d\n",m,fila_A,fila_B);
			}






		}

		sa+= soma/m;
		sb +=soma_b/m;
		fila_A = A;
		fila_B = B;



		h++;
		//impressão da média de veículos das filas em cada tentativa de simulação
		printf("Tentativa( %d)  Média Veículo A: %f,Média Veiculo B: %f por %d periodos de tempo\n",h,(float)soma/m,(float)soma_b/m,X);
		soma = 0;
		soma_b = 0;


	}
	//impressão da média de veículos nas filas em relação a todas as tentativas
	printf("Média Veículo A: %f,Média Veiculo B: %f por %d períodos de tempo em %d tentativas\n",(float)sa/h,(float)sb/h,X,Y);
	return 0;

}
