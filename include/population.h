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

	void initializePop(int);
	void calcFitness();
	//void generatePartners();
	void addToPartners(int);
	void repopulatePartners();

	void makeGeneration();
	int  findFitest();
	int  poolCountGenerator(int);

	Population();

};


#endif