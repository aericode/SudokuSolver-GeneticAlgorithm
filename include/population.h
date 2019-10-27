#ifndef POPULATION_H
#define POPULATION_H

#define CELLCOUNT 16

#include "dna.h"


using namespace std;


class Population{
public:
	vector<Dna*> popArray;
	vector<int>  partners;
	int generations;
	bool finished;
	int perfectScore = CELLCOUNT*3;
	int popSize;

	void initializePop();
	void calcFitness();
	//void generatePartners();
	void addToPartners(int);
	void repopulatePartners();
	void clearGeneration();
	void makeGeneration();
	void printGeneration();

	int  findFitest();
	int  poolCountGenerator(int);

	Dna* crossover(int,int);
	

	Population();


};


#endif