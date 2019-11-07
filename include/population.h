#ifndef POPULATION_H
#define POPULATION_H

#include "dna.h"
#include <string>


using namespace std;


class Population{
public:
	vector<Dna*> popArray;
	vector<int>  partners;
	int generations;
	bool finished;
	int worstScore; //pior score (quanto mais alto pior)
	int popSize;

	void initializePop();
	void calcFitness();
	//void generatePartners();
	void addToPartners(int);
	void repopulatePartners();
	void clearGeneration();
	void makeGeneration();
	void printGeneration();
	void mutateGeneration();

	int  findFitest();
	int  poolCountGenerator(int);

	Dna* crossover(int,int);

	void updateTip(string);
	

	Population();
	Population(int,float,string,int);


};


#endif