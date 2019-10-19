#include <iostream>
#include "dna.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


#define LEVEL 2 //sqrt do size
#define SIZE 4  //quantidade de linhas, colunas, etc
#define MAXINPUT 4 //mesmo que size, mas pra contexto de numero
#define CELLCOUNT 16 // size ao quadrado, nº de celulas

int* Dna::tip = NULL;

Dna::Dna(){
	for(int i=0; i < CELLCOUNT; i++){
		if(tip[i]!=0){
			gene[i] = tip[i];
		}else{
			srand (time(NULL));
			gene[i] = rand() % MAXINPUT + 1;

		}
	}
}

Dna Dna::crossover(Dna partner){
	srand (time(NULL));
	Dna child;
	for(int i=0; i < CELLCOUNT; i++){
		if(tip[i]!=0){
			child.gene[i] = tip[i];
		}else{
			if(rand() % 2 == 0){
				child.gene[i] = gene[i];
			}else{
				child.gene[i] = partner.gene[i];
			}
		}
	}

	return child;
}

bool Dna::cellBreaksRow(int index){
	int floor = (index/SIZE)*SIZE;
	int ceiling = floor + SIZE;

	for(int i =floor;i<ceiling;i++){
		if(gene[i]==gene[index]){
			if(i!=index){ 
				cout<<"index: "<<index<<endl;
				cout<<"breaks row"<<endl;
				return true;
			}
		}
	}
	return false;
}

bool Dna::cellBreaksCol(int index){
	int rowIndex = index%SIZE;
	int rowElements[SIZE];
	int current;

	for(int i = 0;i < SIZE; i++){
		rowElements[i] = rowIndex + i*SIZE;
	}

	for(int i = 0;i < SIZE ;i++){
		current = rowElements[i];
		if( gene[ current ]==gene[index]){
			if(current!=index){ 
				cout<<"index: "<<index<<endl;
				cout<<"breaks col"<<endl;
				return true;
			}
		}
	}
	return false;
}



bool Dna::cellBreaksBlock(int index){
	int rowIndex   = (index/SIZE)*SIZE; //a linha a que pertence
	int colIndex   =  index%SIZE;       //a coluna a que pertence
	int blockIndex = ((rowIndex/LEVEL)*LEVEL + colIndex/LEVEL); //o bloco a que pertence
	int current; //o indice do elemento sendo avalado dentro do laço

	//auxilio para calcular a celula onde iniciar a busca
	int blockCol = blockIndex%LEVEL;
	int blockRow = blockIndex/LEVEL;

	//diz o número de linhas para pular a cada linha de bloco
	//é a célula que inicia o bloco
	int startCellIndex = blockRow*LEVEL*SIZE + blockCol*LEVEL;

	int i;//linha de bloco
	int j;//coluna de bloco
	for(i = 0;i < LEVEL; i ++){//cada "i" que aumenta vai pular SIZE blocos
		for(j = 0; j < LEVEL;j++){
			current = startCellIndex + (SIZE*i + j); //avançar SIZE coloca você na coluna abaixo da sua
			if( gene[ current ]==gene[index]){ //checa se é igual ao valor da celula
				if(current!=index){ 
					cout<<"index: "<<index<<endl;
					cout<<"breaks block"<<endl;
					return true;
				}
			}
		}
		j=0;//volta pra colina zero
	}

	
	return false;
}

void Dna::testFitness(){
	int score = 0;
	for(int i = 0;i < CELLCOUNT;i++){
		if(!cellBreaksRow(i))   score++;
		if(!cellBreaksCol(i))   score++;
		if(!cellBreaksBlock(i)) score++;
	}
	fitness = score;
}

Dna::Dna(int *init){
	for(int i = 0;i< CELLCOUNT; i++){
		gene[i] = init[i];
	}
}