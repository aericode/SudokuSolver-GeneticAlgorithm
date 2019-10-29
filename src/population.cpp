#include "population.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>
#include <vector>
#include "dna.h"


#define PERFECTSCORE 48
#define MAXADD 100 //qual o maximo de copias a adicionar na breeding pool
#define DEFAULTPOP 50 //população padrão

using namespace std;

Population::Population(){}

Population::Population(int level_, float mutationFaction_, string tip_, int popSize_){
	popSize = popSize_;
	finished = false;

	Dna::level     = level_;
	Dna::size      = level_*level_;
	Dna::maxInput  = level_*level_;
	Dna::cellCount = (Dna::size)*(Dna::size);

	updateTip(tip_);

	for(int i = 0; i<Dna::cellCount; i++){
		cout<<Dna::tip[i]<<' ';
	}
	cout<<endl;
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
		if(popArray[i]->fitness == PERFECTSCORE){
			finished = true;
			cout<<"RESPOSTAAAAAAAAAAAA: ";
			popArray[i]->sayGene();
			cout<<endl;
		}
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

		child = crossover(indexA, indexB);

		nextGen.push_back(child);
	}

	clearGeneration();

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


void Population::mutateGeneration(){
	for(int i=0;i<popSize;i++){
		popArray[i]->mutate();
	}
}

void Population::updateTip(string tip_){
	if(Dna::tip)delete Dna::tip;
	Dna::tip = new int[Dna::cellCount];

	for (int i = 0; i<Dna::cellCount; i++) { 
    	Dna::tip[i] = tip_[i] - 48;
    }
}