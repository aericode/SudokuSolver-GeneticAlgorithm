#include "population.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>
#include <vector>

#define PERFECTSCORE 48
#define MAXADD 100

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

void Population::addToPartners(int index){
	int score = popArray.at(index)->fitness;
	int poolCount = (MAXADD*score)/PERFECTSCORE; //regra de três para decidir quantos vão para a pool

	for(int i=0;i<poolCount;i++){
		partners.push_back(i);
	}

}

void Population::repopulatePartners(){
	partners.clear();	

	for(int i=0;i<popArray.size();i++){
		addToPartners(i);
	}
}