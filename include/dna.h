#ifndef dna_h
#define dna_h
#include <vector>

using namespace std;

class Dna{
public:
static int* tip;
int gene[16];
int fitness;

Dna();
Dna(int* tip);
Dna crossover(Dna);

};



#endif