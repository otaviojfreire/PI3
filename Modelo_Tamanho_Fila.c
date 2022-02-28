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
//var�avel de incremento, representando cada per�odo de tempo
int i =0;
int open_A=0,open_B=0;
//vari�veis para somar a quantidade de ve�culos presente nas filas
// durante o per�odo de tempo total de simula��o
int soma=0,soma_b=0;

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

/* O controlador recebe uma informa��o do ambiente de observa��o
 * A informa��o � referente ao tamanho das filas das ruas(A e B)
 * Se a obs == 1 ent�o quer dizer que a fila_A>fila_B, o controlador decide deixar
 * aberto o sam�foro A neste momento
 * Se a obs == 2 ent�o quer dizer que a fila_B>fila_A, o controlador decide deixar
 * aberto o sam�foro B neste momento
 * Caso obs == 3 quer dizer que as filas s�o iguais ent�o o controlador
 * realiza um sorteio para decidir qual sem�foro estar� aberto neste momento
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


/*Esta fun��o observa o ambiente das duas filas
 * e verifica qual fila � maior e ent�o returna um valor de acordo
 * com a observa��o
 * Caso as filas forem iguais ent�o ele retorna 3
 * Esta informa��o retornada ser� utilizada no controlador de
 * tr�nsito
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



/*Este ambiente representa a entrada de ve�culos no sistema(taxa de entrada) e
 * a sa�da de ve�culos do sistema(taxa de s�ida), as taxas reresentam ve�culos/per�odo de tempo
 * O ambiente de simula��o recebe char*, o qual � decis�o do controlador
 * Quando o sem�foro est� aberto para a fila de ve�culos A H� taxa de entrada e sa�da de ve�culos do sistema
 * representado pela fila A(ve�culos/per�odo de tempo) e no sistema da fila B h� apenas
 * taxa de entrada de ve�culos(ve�culos/per�odo de tempo)
 *  * Quando o sem�foro est� aberto para a fila de ve�culos B H� taxa de entrada e sa�da de ve�culos do sistema
 * representado pela fila B(ve�culos/per�odo de tempo) e no sistema da fila A h� apenas
 * taxa de entrada de ve�culos(ve�culos/per�odo de tempo)
 *
 */
int ambiente_simul(char* acao){
	if (strcmp(acao,"aberto A")==0){
		/*Se a fila A est� vazia
		 * ela ter� apenas taxa de entrada de ve�culos
		 * e a fila B ter� tamb�m taxa de entrada de
		 * ve�culos
		 */
		if(fila_A<0){
			/*� gerado uma taxa de entrada
			 */
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
			i++;


		}
		else{
			/*� gerado uma taxa de sa�da
			 */
			taxa_saida_veiculo();
			/*� retirado ve�culos por per�odo na fila A
			 */
			fila_A -= taxa_saida;
			fila_vazia_A();
			/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
			de simula��o na fila A
			 */

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
			i++;

		}
		open_A++;

	}
	else if(strcmp(acao,"aberto B")==0){
		if(fila_B<0){
			/*� gerado uma taxa de entrada
			 */
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
			i++;


		}
		else{
			/*� gerado uma taxa de sa�da
			 */
			taxa_saida_veiculo();
			/*� retirado ve�culos por per�odo na fila A
			 */
			fila_B -= taxa_saida;
			fila_vazia_B();
			/*Var�avel para calcular a m�dia de ve�culos no total de per�odos
			de simula��o na fila A
			 */




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
	//semente para gerar n�meros aleat�rios
	srand(time(NULL));
	//gera ve�culos iniciais para a fila
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
			//verificar se as filas est�o vazias
			fila_vazia_A();
			fila_vazia_B();
			//observar o ambiente
			obs = ambiente_observacao();
			/*eviar a observa��o ao controlador e o
			 * controlador ir� decidir qual sem�foro deixar� aberto
			 * ambiente_simul simula a situa��o do cruzamento em X
			 */
			ambiente_simul(controlador(obs));
			//verifica se as filas est�o vazias
			fila_vazia_A();
			fila_vazia_B();
			//printf("Tempo = %d, situa��o %s, A = %d,B = %d\n",i,controlador(obs),fila_A,fila_B);






		}
		//calcular a m�dia de va�culos da fila A em rela��o ao total de per�dos simulados
		sa+= soma/i;
		//calcular a m�dia de va�culos da fila A em rela��o ao total de per�dos simulados
		sb +=soma_b/i;
		fila_A = A;
		fila_B = B;




		h++;
		//impress�o da m�dia de ve�culos das filas em cada tentativa de simula��o
		printf("Tentativa( %d)  M�dia Ve�culo A: %f,M�dia Veiculo B: %f por %d periodos de tempo\n",h,(float)soma/i,(float)soma_b/i,X);


	}
	//impress�o da m�dia de ve�culos nas filas em rela��o a todas as tentativas
	printf("M�dia Ve�culo A: %f,M�dia Veiculo B: %f por %d per�odos de tempo em %d tentativas\n",(float)sa/h,(float)sb/h,X,Y);
	return 0;

}
