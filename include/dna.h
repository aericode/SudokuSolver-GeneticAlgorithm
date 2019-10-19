#ifndef dna_h
#define dna_h
#include <vector>

using namespace std;

class Dna{
private:
bool cellBreaksRow(int);
bool cellBreaksCol(int);
bool cellBreaksBlock(int);

int rowScore();
int colScore();
int blockScore();

public:
static int* tip;
int gene[16];
int fitness;

Dna();
Dna(int*);
Dna crossover(Dna);

void testFitness();

};



#endif