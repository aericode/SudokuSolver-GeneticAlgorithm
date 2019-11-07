#include "dna.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

//#define level 2 //sqrt do size
//#define size 4  //quantidade de linhas, colunas, etc
//#define maxInput 4 //mesmo que size, mas pra contexto de numero
//#define cellCount 16 // size ao quadrado, nº de celulas

int*  Dna::tip = NULL;
float Dna::mutationFactor = 0;
int   Dna::level = 0;
int   Dna::size = 0;
int   Dna::maxInput = 0;
int   Dna::cellCount = 0;

Dna::Dna(){
	gene = new int[cellCount];

	for(int i=0; i < cellCount; i++){
		if(tip[i]!=0){
			gene[i] = tip[i];
		}else{
			int randomTest = rand();
			gene[i] = rand() % maxInput + 1;

		}
	}
}

Dna::~Dna(){
	delete[] gene;
}

/*Dna* Dna::crossover(Dna* partner){
	Dna* child = new Dna;
	for(int i=0; i < cellCount; i++){
		if(tip[i]!=0){
			child->gene[i] = tip[i];
		}else{
			if(rand() % 2 == 0){
				child->gene[i] = this->gene[i];
				//child->gene[i] = 1;
			}else{
				//child->gene[i] = partner->gene[i];
				child->gene[i] = 2;
			}
		}
	}

	return child;
}*/

void Dna::cellBreaksRow(int index){
	int floor = (index/size)*size;
	int ceiling = floor + size;

	for(int i =floor;i<ceiling;i++){
		if(gene[i]==gene[index]){
			if(i!=index){ 
				fitness++;
			}
		}
	}
}

void Dna::cellBreaksCol(int index){
	int rowIndex = index%size;
	int rowElements[size];
	int current;

	for(int i = 0;i < size; i++){
		rowElements[i] = rowIndex + i*size;
	}

	for(int i = 0;i < size ;i++){
		current = rowElements[i];
		if( gene[ current ]==gene[index]){
			if(current!=index){ 
				fitness++;
			}
		}
	}
}



void Dna::cellBreaksBlock(int index){
	int rowIndex   = (index/size)*size; //a linha a que pertence
	int colIndex   =  index%size;       //a coluna a que pertence
	int blockIndex = ((rowIndex/level)*level + colIndex/level); //o bloco a que pertence
	int current; //o indice do elemento sendo avalado dentro do laço

	//auxilio para calcular a celula onde iniciar a busca
	int blockCol = blockIndex%level;
	int blockRow = blockIndex/level;

	//diz o número de linhas para pular a cada linha de bloco
	//é a célula que inicia o bloco
	int startCellIndex = blockRow*level*size + blockCol*level;

	int i;//linha de bloco
	int j;//coluna de bloco
	for(i = 0;i < level; i ++){//cada "i" que aumenta vai pular size blocos
		for(j = 0; j < level;j++){
			current = startCellIndex + (size*i + j); //avançar size coloca você na coluna abaixo da sua
			if( gene[ current ]==gene[index]){ //checa se é igual ao valor da celula
				if(current!=index){ 
					fitness++;
				}
			}
		}
		j=0;//volta pra colina zero
	}
}

void Dna::testFitness(){
	fitness = 0;
	for(int i = 0;i < cellCount;i++){
		cellBreaksRow(i);
		cellBreaksCol(i);
		cellBreaksBlock(i);
	}
}

Dna::Dna(int *init){
	for(int i = 0;i< cellCount; i++){
		gene[i] = init[i];
	}
}

void Dna::mutate(){
	float randomMutate;
	int origVal;
	int newVal;
	for(int i = 0; i < cellCount; i++){
		if(tip[i]!=0){
			gene[i] = tip[i];
		}else{
			randomMutate = (float)rand()/(float)RAND_MAX;
			if(randomMutate < mutationFactor){
				gene[i] = origVal;
				do{
					newVal = rand() % maxInput + 1;
				}while(origVal == newVal);

				gene[i] = newVal;
			}
		}
	}
}

void Dna::sayGene(){
	for(int i = 0;i < cellCount;i++){
		cout<<gene[i];
	}
	cout<<endl;
}

int Dna::getGene(int place){
	return gene[place];
}