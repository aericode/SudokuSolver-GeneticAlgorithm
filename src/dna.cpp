#include "dna.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
	int childGene[16];
	for(int i=0; i < CELLCOUNT; i++){
		if(tip[i]!=0){
			childGene[i] = tip[i];
		}else{
			if(rand() % 2 == 0){
				childGene[i] = gene[i];
			}else{
				childGene[i] = partner.gene[i];
			}
		}
	}
	child.gene = childGene;

	return child;
}