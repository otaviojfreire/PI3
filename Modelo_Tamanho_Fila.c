/*
 ============================================================================
 Name        : Modelo Tamanho de Fila
 Author      : Otávio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Modelo de semáforo com a política de abertura e
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
//define a quantidade de períodos de simulação
#define X 240
//define o número de vezes que será simulado(tentativas)
#define Y 100

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
//varíavel de incremento, representando cada período de tempo
int i =0;
int open_A=0,open_B=0;
//variáveis para somar a quantidade de veículos presente nas filas
// durante o período de tempo total de simulação
int soma=0,soma_b=0;

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

/* O controlador recebe uma informação do ambiente de observação
 * A informação é referente ao tamanho das filas das ruas(A e B)
 * Se a obs == 1 então quer dizer que a fila_A>fila_B, o controlador decide deixar
 * aberto o samáforo A neste momento
 * Se a obs == 2 então quer dizer que a fila_B>fila_A, o controlador decide deixar
 * aberto o samáforo B neste momento
 * Caso obs == 3 quer dizer que as filas são iguais então o controlador
 * realiza um sorteio para decidir qual semáforo estará aberto neste momento
 */
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


/*Esta função observa o ambiente das duas filas
 * e verifica qual fila é maior e então returna um valor de acordo
 * com a observação
 * Caso as filas forem iguais então ele retorna 3
 * Esta informação retornada será utilizada no controlador de
 * trânsito
 */
int ambiente_observacao(){
	if(fila_A>fila_B){
		return 1;
	}

	else if(fila_B>fila_A)
		return 0;

	else
		return 3;
}



/*Este ambiente representa a entrada de veículos no sistema(taxa de entrada) e
 * a saída de veículos do sistema(taxa de sáida), as taxas reresentam veículos/período de tempo
 * O ambiente de simulação recebe char*, o qual é decisão do controlador
 * Quando o semáforo está aberto para a fila de veículos A Há taxa de entrada e saída de veículos do sistema
 * representado pela fila A(veículos/período de tempo) e no sistema da fila B há apenas
 * taxa de entrada de veículos(veículos/período de tempo)
 *  * Quando o semáforo está aberto para a fila de veículos B Há taxa de entrada e saída de veículos do sistema
 * representado pela fila B(veículos/período de tempo) e no sistema da fila A há apenas
 * taxa de entrada de veículos(veículos/período de tempo)
 *
 */
int ambiente_simul(char* acao){
	if (strcmp(acao,"aberto A")==0){
		/*Se a fila A está vazia
		 * ela terá apenas taxa de entrada de veículos
		 * e a fila B terá também taxa de entrada de
		 * veículos
		 */
		if(fila_A<0){
			/*É gerado uma taxa de entrada
			 */
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
			i++;


		}
		else{
			/*É gerado uma taxa de saída
			 */
			taxa_saida_veiculo();
			/*É retirado veículos por período na fila A
			 */
			fila_A -= taxa_saida;
			fila_vazia_A();
			/*Varíavel para calcular a média de veículos no total de períodos
			de simulação na fila A
			 */

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
			i++;

		}
		open_A++;

	}
	else if(strcmp(acao,"aberto B")==0){
		if(fila_B<0){
			/*É gerado uma taxa de entrada
			 */
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
			i++;


		}
		else{
			/*É gerado uma taxa de saída
			 */
			taxa_saida_veiculo();
			/*É retirado veículos por período na fila A
			 */
			fila_B -= taxa_saida;
			fila_vazia_B();
			/*Varíavel para calcular a média de veículos no total de períodos
			de simulação na fila A
			 */




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
			i++;
		}
		open_B++;
	}
	else{

	}
	return fila_A + fila_B;
}



int main(void) {
	int sa=0,sb=0;
	int  obs = 0,h=0;
	//semente para gerar números aleatórios
	srand(time(NULL));
	//gera veículos iniciais para a fila
	gerador_veiculo();
	fila_A += taxa_entrada;
	soma = soma + fila_A;
	gerador_veiculo();
	fila_B += taxa_entrada;
	soma_b = soma_b + fila_B;




	while(h!=Y){
		soma = 0;
		soma_b = 0;
		i =0;
		gerador_veiculo();
		fila_A += taxa_entrada;
		soma = soma + fila_A;
		gerador_veiculo();
		soma_b = soma_b + fila_B;




		//printf("Fila_A=%d,Fila_B=%d\n",fila_A,fila_B);

		while(i!=X){
			//verificar se as filas estão vazias
			fila_vazia_A();
			fila_vazia_B();
			//observar o ambiente
			obs = ambiente_observacao();
			/*eviar a observação ao controlador e o
			 * controlador irá decidir qual semáforo deixará aberto
			 * ambiente_simul simula a situação do cruzamento em X
			 */
			ambiente_simul(controlador(obs));
			//verifica se as filas estão vazias
			fila_vazia_A();
			fila_vazia_B();
			//printf("Tempo = %d, situação %s, A = %d,B = %d\n",i,controlador(obs),fila_A,fila_B);






		}
		//calcular a média de vaículos da fila A em relação ao total de perídos simulados
		sa+= soma/i;
		//calcular a média de vaículos da fila A em relação ao total de perídos simulados
		sb +=soma_b/i;
		fila_A = A;
		fila_B = B;




		h++;
		//impressão da média de veículos das filas em cada tentativa de simulação
		printf("Tentativa( %d)  Média Veículo A: %f,Média Veiculo B: %f por %d periodos de tempo\n",h,(float)soma/i,(float)soma_b/i,X);


	}
	//impressão da média de veículos nas filas em relação a todas as tentativas
	printf("Média Veículo A: %f,Média Veiculo B: %f por %d períodos de tempo em %d tentativas\n",(float)sa/h,(float)sb/h,X,Y);
	return 0;

}
