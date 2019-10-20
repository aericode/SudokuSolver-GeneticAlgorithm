#ifndef POPULATION_H
#define POPULATION_H

#define CELLCOUNT 16

#include "dna.h"


using namespace std;


class Population{
public:
	vector<Dna*> popArray;
	vector<Dna*> partners;
	int generations;
	bool finished;
	int perfectScore = CELLCOUNT*3;

	void initializePop(int);
	void calcFitness();
	void generatePartners();
	void makeGeneration();
	int  findFitest();

	Population();

};


#endif