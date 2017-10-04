#include<iostream>
using namespace std;
int knapsack(int nbrOfElements, int weightAllowed, int *value, int *weight){
	int item, currentWeight = 0;
	int optimumTable[nbrOfElements][weightAllowed]; 
	for( item = 0; item < nbrOfElements; item++){
		for(currentWeight = 0; currentWeight < weightAllowed; currentWeight++){
			if (item == 0 || currentWeight == 0){
				optimumTable[item][currentWeight] = 0;
			} else {
				if (weight[item] > currentWeight) {
					optimumTable[item][currentWeight] = optimumTable[item - 1][currentWeight];
				} else {
					optimumTable[item][currentWeight] = max(value[item - 1] + optimumTable[item - 1][currentWeight - weight[item]] , optimumTable[item - 1][currentWeight]);
				}
			}
		}
	}
	return optimumTable[nbrOfElements - 1][weightAllowed - 1];
}
int main()
{
	int nbrOfElements = 3;
	int weightAllowed = 5;
	int value[] = {40, 100, 20};
	int weight[] = {3, 2, 1};
	int total = knapsack(nbrOfElements,weightAllowed,value,weight);
	cout<<total<<endl;
}