#include "dna.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define SIZE 4
#define MAXINPUT 4
#define CELLCOUNT 16

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
			if(i!=index) return true;
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
			if(current!=index)return true;
		}
	}
	return false;
}