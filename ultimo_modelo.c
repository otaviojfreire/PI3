/*
 ============================================================================
 Name        : Último Modelo Veículos Diferentes.c
 Author      : Otávio Augusto Joenck Freire
 Version     :
 Copyright   : Your copyright notice
 Description : Simulação de Tráfego com veículos de tipo diferente.
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int carro_A = 0;
int carro_B = 0;
int tx_A_car =0,tx_A_caminhao=0,tx_A_moto=0;
int tx_B_car=0,tx_B_caminhao =0,tx_B_moto=0;
int in_A_car=0,in_A_caminhao=0,in_A_moto=0;
int in_B_car=0,in_B_caminhao=0,in_B_moto=0;
char acao[15];
int car_A=0, car_B=0;
int caminhao_A=0,caminhao_B=0;
int moto_A=0,moto_B=0 ;

int fila_car_A_vazia(){
	if(in_A_car<0){
		in_A_car = 0;

	}
	return 1;
}

int fila_caminhao_A_vazia(){
	if(in_A_caminhao<0){
		in_A_caminhao = 0;

	}
	return 1;
}

int fila_moto_A_vazia(){
	if(in_A_moto<0){
		in_A_moto = 0;

	}
	return 1;
}

int fila_car_B_vazia(){
	if(in_B_car<0){
		in_B_car = 0;

	}
	return 1;
}

int fila_caminhao_B_vazia(){
	if(in_B_caminhao<0){
		in_B_caminhao = 0;

	}
	return 1;
}

int fila_moto_B_vazia(){
	if(in_B_moto<0){
		in_B_moto = 0;

	}
	return 1;
}

void gerador_caminhao_A(){

	caminhao_A = (rand()%10);


}

void gerador_caminhao_B(){


	caminhao_B = (rand()%10);


}

char*  controlador(int obs){

	if(obs==3){
		obs = (rand()%5);
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



int ambiente_observacao(){
	if(carro_A>carro_B&&caminhao_A>caminhao_B){
		return 1;
	}




	else if(carro_B>carro_A&&caminhao_B>caminhao_A){

		return 0;


	}
	else if(carro_A>carro_B&&car_A>car_B){
		return 1;
	}




	else if(carro_B>carro_A&&car_B>car_A){

		return 0;


	}
	else if(carro_A>carro_B&&moto_A>moto_B){
		return 1;
	}




	else if(carro_B>carro_A&&moto_B>moto_A){

		return 0;


	}

	else if(carro_A==carro_B&&caminhao_A>caminhao_B){
		return 1;
	}




	else if(carro_B==carro_A&&caminhao_B>caminhao_A){

		return 0;


	}
	else if(carro_A==carro_B&&car_A>car_B){
		return 1;
	}




	else if(carro_B==carro_A&&car_B>car_A){

		return 0;


	}
	else if(carro_A==carro_B&&moto_A>moto_B){
		return 1;
	}




	else if(carro_B==carro_A&&moto_B>moto_A){

		return 0;


	}
	else if(carro_A>carro_B){
		return 1;
	}



	else if(carro_B>carro_A){
		return 0;
	}

	else
		return 3;
}


void gerador_car_A(){

	car_A = (rand()%10);

}

void gerador_car_B(){


	car_B = (rand()%10);


}

void gerador_moto_A(){

	moto_A = (rand()%10);

}

void gerador_moto_B(){


	moto_B = (rand()%10);

}

void gerador_car_out_A(){


	tx_A_car = (rand()%15);

}

void gerador_car_out_B(){



	tx_B_car = (rand()%15);


}

void gerador_caminhao_out_A(){

	tx_A_caminhao = (rand()%15);

}

void gerador_caminhao_out_B(){


	tx_B_caminhao = (rand()%15);

}
void gerador_moto_out_A(){


	tx_A_moto = (rand()%15);


}

void gerador_moto_out_B(){


	tx_B_moto = (rand()%15);

}

int fila_infinita_B(){
	if(carro_B>=50){

		return 1;

	}
	else
		return 0;
}

int fila_infinita_A(){
	if(carro_A>=50){
		return 1;
	}
	else
		return 0;
}

int ambiente_simul(char* acao){
	if (strcmp(acao,"aberto A")==0){

		if(carro_A<0){
			gerador_car_A();
			in_A_car = in_A_car + car_A;
			carro_A += car_A;
			gerador_caminhao_A();
			in_A_caminhao += caminhao_A;
			carro_A +=caminhao_A;
			gerador_moto_A();
			in_A_moto +=moto_A;
			carro_A +=moto_A;


		}
		else{



			gerador_car_A();
			in_A_car = in_A_car + car_A;
			carro_A += car_A;
			gerador_caminhao_A();
			in_A_caminhao += caminhao_A;
			carro_A +=caminhao_A;
			gerador_moto_A();
			in_A_moto +=moto_A;
			carro_A +=moto_A;

			gerador_car_out_A();
			carro_A -= tx_A_car;
			in_A_car -=tx_A_car;
			fila_car_A_vazia();
			gerador_caminhao_out_A();
			carro_A -=tx_A_caminhao;
			in_A_caminhao -=tx_A_caminhao;
			fila_caminhao_A_vazia();
			gerador_moto_out_A();
			carro_A -=tx_A_moto;
			in_A_moto -=tx_A_moto;
			fila_moto_A_vazia();


		}

	}

	else if(strcmp(acao,"aberto B")==0){

		if(carro_B<0){
			gerador_car_B();
			in_B_car = in_B_car + car_B;
			carro_B += car_B;
			gerador_caminhao_B();
			in_B_caminhao += caminhao_B;
			carro_B +=caminhao_B;
			gerador_moto_B();
			in_B_moto +=moto_B;
			carro_B +=moto_B;


		}

		else{



			gerador_car_B();
			in_B_car = in_B_car + car_B;
			carro_B += car_B;
			gerador_caminhao_B();
			in_B_caminhao += caminhao_B;
			carro_B +=caminhao_B;
			gerador_moto_B();
			in_B_moto +=moto_B;
			carro_B +=moto_B;

			gerador_car_out_B();
			carro_B -= tx_B_car;
			in_B_car -=tx_B_car;
			fila_car_B_vazia();
			gerador_caminhao_out_B();
			carro_B -=tx_B_caminhao;
			in_B_caminhao -=tx_B_caminhao;
			fila_caminhao_B_vazia();
			gerador_moto_out_B();
			carro_B -=tx_B_moto;
			in_B_moto -=tx_B_moto;
			fila_moto_B_vazia();

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
int fila_vazia_B(){
	if(carro_B<0)
		carro_B=0;
	return carro_B;
}



int main(void) {
	int i=1;
	int  obs = 0;


	srand(time(NULL));

	gerador_car_A();
	in_A_car += car_A;
	carro_A = carro_A + car_A;
	gerador_car_B();
	in_B_car += car_B;
	carro_B = carro_B + car_B;

	gerador_caminhao_A();
	in_A_caminhao += caminhao_A;
	carro_A = carro_A + caminhao_A;
	gerador_caminhao_B();
	in_B_caminhao += caminhao_B;
	carro_B = carro_B + caminhao_B;

	gerador_moto_A();
	in_A_moto += moto_A;
	carro_A = carro_A + moto_A;
	gerador_moto_B();
	in_B_moto += moto_B;
	carro_B = carro_B + moto_B;


	obs = ambiente_observacao();



	printf("Fila_A=%d,Fila_B=%d\n",carro_A,carro_B);





	while(carro_A>0||carro_B>0){
		obs = ambiente_observacao();
		fila_infinita_A();
		fila_infinita_B();
		fila_vazia_A();
		fila_vazia_B();
		ambiente_simul(controlador(obs));
		fila_infinita_A();
		fila_infinita_B();
		fila_vazia_A();
		fila_vazia_B();
		printf("Tempo = %d, situação %s,FILA A = %d,FILA B = %d\n",i,controlador(obs),carro_A,carro_B);
		i++;
	}



	return 0;
}



