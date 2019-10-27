#include "population.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>
#include <vector>

#define PERFECTSCORE 48
#define MAXADD 100
#define DEFAULTPOP 50

using namespace std;


Population::Population(){
	popSize = DEFAULTPOP;
}

void Population::initializePop(){
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

	/*
	for(int i=0;i<popArray.size();i++){
		cout<<popArray[i]->fitness<<endl;
	}
	*/
}

void Population::addToPartners(int index){
	int score = popArray.at(index)->fitness;
	int poolCount = (MAXADD*score)/PERFECTSCORE; //regra de três para decidir quantos vão para a pool

	for(int i=0;i<poolCount;i++){
		partners.push_back(index);
	}

}

void Population::repopulatePartners(){
	partners.clear();	

	for(int i=0;i<popArray.size();i++){
		addToPartners(i);
	}
}

void Population::clearGeneration(){
	for(int i=0;i<popSize;i++){
		delete popArray[i];
	}
}


void Population::makeGeneration(){
	vector<Dna*> nextGen;

	int indexA; 
	int indexB;

	Dna* partnerA;
	Dna* partnerB;

	Dna* child;
	for(int i = 0; i < popSize ; i++){
		indexA = partners[rand()%partners.size()];
		indexB = partners[rand()%partners.size()];

		//partnerA = popArray[indexA];
		//partnerB = popArray[indexB];

		child = crossover(indexA, indexB);

		nextGen.push_back(child);
	}

	//clearGeneration();

	popArray = nextGen;
}


void Population::printGeneration(){
	for(int i=0;i<popArray.size();i++){
		cout<<"index: "<<i<<endl;
		popArray[i]->sayGene();
		cout<<"fitness :"<<popArray[i]->fitness<<endl<<endl;
	}
}

Dna* Population::crossover(int indexA, int indexB){
	cout<<"index A = "<<indexA<<endl;
	cout<<"index B = "<<indexB<<endl;
	Dna* child = new Dna;
	for(int i=0; i < CELLCOUNT; i++){
		if(Dna::tip[i]!=0){
			child->gene[i] = Dna::tip[i];
		}else{
			if(rand() % 2 == 0){
				child->gene[i] = popArray.at(indexA)->getGene(i);
			}else{
				child->gene[i] = popArray.at(indexB)->getGene(i);
			}
		}
	}

	return child;
}