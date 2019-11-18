#include "dna.h"
#include "population.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <string>

using namespace std;

int main(){

	string examples[] ={"0001400000300200",
						"2100032000041000",
						"1034030020000001",
						"0012010300004020",
						"0230030000012040",
						"4200100001200003",
						"0003400001303020",
						"0320000410000012",
						"4000001002400021",
						"0200002030402001",
						"0001400220040023",
						"4000000220140400",
						"0210003201002001"};
	int choice;
	string tip;
	do{
		cout<<"escolha um dos exemplos para testar 0-12"<<endl;
		cin>>choice;
	}while(choice<0||choice>12);

	tip = examples[choice];

	float mut;

	cout<<"escolha uma taxa de mutação entre 0 e 1"<<endl;
	cout<<"(0.3 foi o usado nos testes)"<<endl;
	cin>>mut;



	srand(time(NULL));

	Population population(2,mut,tip,100);

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