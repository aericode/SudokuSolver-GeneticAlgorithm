#include "population.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>

Population::Population(){}

void Population::initializePop(int popSize){
	for(int i=0;i<popSize;i++){
		popArray.push_back(new Dna());
	}

	for(int i=0;i<popSize;i++){
		popArray[i]->sayGene();
	}
}