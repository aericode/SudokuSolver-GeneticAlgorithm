#include "dna.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define MAXINPUT 4
#define CELLCOUNT 16

int* Dna::tip = NULL;

Dna::Dna(){
	for(int i=0; i < CELLCOUNT; i++){
		if(tip[i]!=0){
			gene[i] = tip[i];
		}else{
			srand (time(NULL));
			gene[i] = rand() % MAXINPUT + 1;

		}
	}
}