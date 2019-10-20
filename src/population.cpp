#include "population.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>
#include <vector>

using namespace std;

Population::Population(){}

void Population::initializePop(int popSize){
	for(int i=0;i<popSize;i++){
		popArray.push_back(new Dna());
	}
	/*
	for(int i=0;i<popSize;i++){
		popArray[i]->sayGene();
	}
	*/
}

void Population::calcFitness(){
	for(int i=0;i<popArray.size();i++){
		popArray[i]->testFitness();
	}


	for(int i=0;i<popArray.size();i++){
		cout<<popArray[i]->fitness<<endl;
	}
}