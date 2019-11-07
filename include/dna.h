#ifndef dna_h
#define dna_h
#include <vector>
#include <time.h>

using namespace std;

class Dna{
private:
void cellBreaksRow(int);
void cellBreaksCol(int);
void cellBreaksBlock(int);

public:
static int* tip; //dica dada pelo sudoku
static float mutationFactor; //chance de mutação

static int level;
static int size;
static int maxInput;
static int cellCount;


int* gene;
int  fitness;

Dna();
~Dna();
Dna(int*);
//Dna* crossover(Dna*);


void testFitness();
void mutate();
void sayGene();
int getGene(int);

};



#endif