#ifndef dna_h
#define dna_h
#include <vector>
#include <time.h>

using namespace std;

class Dna{
private:
bool cellBreaksRow(int);
bool cellBreaksCol(int);
bool cellBreaksBlock(int);

public:
static int* tip; //dica dada pelo sudoku
static float mutationFactor; //chance de mutação
int gene[16];
int fitness;

Dna();
Dna(int*);
Dna crossover(Dna);

void testFitness();
void mutate();
void sayGene();

};



#endif