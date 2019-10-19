#include "dna.h"
#include <iostream>

using namespace std;

int main(){
	Dna::tip = new int[16];
	int test[16] = {2,1,0,0,0,3,2,0,0,0,0,4,1,0,0,0};
	Dna::tip = test;
	
	cout<<"hello world"<<endl;
	

	return 0;
}