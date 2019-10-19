#include "dna.h"
#include <iostream>

using namespace std;

int main(){
	Dna::tip = new int[16];
	int test[16] = {2,1,0,0,0,3,2,0,0,0,0,4,1,0,0,0};
	int answer[16] = {2,1,4,3,4,3,2,1,3,2,1,4,1,4,3,2};
	Dna::tip = test;

	Dna ind(answer);
	ind.testFitness();

	for(int i=0;i<16;i++){
		cout<<ind.gene[i]<<' ';
	}
	cout<<endl;
	
	cout<<"fitness: "<< ind.fitness <<endl;
	

	return 0;
}