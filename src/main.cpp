#include "dna.h"
#include "population.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <string>

using namespace std;

int main(){
	srand(time(NULL));

	Population population(2,0.4,"2100032000041000",100);
	//Population population(3,0.3,"600120384008459072000006005000264030070080006940003000310000050089700000502000190",20);

	population.initializePop();

	while(!population.finished){
		population.calcFitness();
		population.repopulatePartners();

		population.makeGeneration();
		population.mutateGeneration();
		population.calcFitness();

		if(population.generations%10 == 0){
			cout<<population.generations<<endl;
			population.printGeneration();
		}
	}

	return 0;
}