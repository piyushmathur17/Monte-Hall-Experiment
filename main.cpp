#include<bits/stdc++.h>
#include "experiment.cpp"
#include "test.cpp"
using namespace std;

int main(){

	int N = 3;//Number of experiments
	
	//test random function
	Test T;
	
	std::cout<<"Conducting Tests: \n\n";
	
	if(T.is_uniform())
	    std::cout<<"The random function is uniform\n\n";
	else 
		std::cout<<"The random function seems skewed, the results may be inaccurate\n\n";

	//perform N experiments
	std::cout<<"\nConducting Experiments: \n\n";

	for(int i=0;i<N;i++){
		Experiment E;
		E.conduct_experiment();
	}

}