#include "dna.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  

using namespace std;

int main(){
	Dna::tip = new int[16];
	Dna::mutationFactor = 0.2;
	int test[16] = {2,1,0,0,0,3,2,0,0,0,0,4,1,0,0,0};
	Dna::tip = test;

	int answer[16] = {2,1,4,3,4,3,2,1,3,2,1,4,1,4,3,2};
	

	Dna ind;
	ind.testFitness();

	for(int i=0;i<16;i++){
		cout<<ind.gene[i]<<' ';
	}
	cout<<endl<<ind.fitness<<endl;

	ind.mutate();
	ind.testFitness();
	for(int i=0;i<16;i++){
		cout<<ind.gene[i]<<' ';
	}
	cout<<endl<<ind.fitness<<endl;

	return 0;
}