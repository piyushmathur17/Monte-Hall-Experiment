class Test{
	//class for testing random function before beginning experiments

public:
	bool is_random = true;
	std::vector<int> v = std::vector<int>(10);//for storing the frequency of each number
	double expected_probability = 0.1;
	double threshold = 0.1;

	std::vector<std::vector<int> >mat = std::vector<std::vector<int> >(10,std::vector<int> (10)); // probability matrix: ideally each cell should have 0.1 probability
	
	//number_of_samples is the number of times the experiment is repeated
	const unsigned int number_of_samples = 1000000; 
	


	bool is_uniform(){
		//for testing uniformity of the random function 
	    //i.e. probability of each number occuring should be almost same
	    //we are also testing the independence of each number occuring
		//i.e. if 1 appears first then probability of 1,2,3,...,9,10 occuring
		//in the next turn should be the same

		int last =-1; //stores which number was last generated
		
		for(int i=0;i<number_of_samples;i++){
		    //generating number between 0 and 9
			int j=rand()%10;
			//increasing count of that number
			v[j]++;
			
			if(i!=0){
				//number of times j occured after last
				//to ensure that after each element the chances of occurence of all elements is same
				//thus ensuring independence
			    mat[last][j]++;
			}
			//current element becomes last element for next iteration
			last = j;
		}
		int sum=0;
		std::vector<int> row_sum(10);
	    for(int i=0;i<10;i++){
	        sum+=v[i];
	        for(int j=0;j<10;j++){
	            row_sum[i]+=mat[i][j];
	        }
	    }
	    
		std::cout<<"\nThe probability of each number appearing in testing was :\n";
		for(int i=0;i<10;i++){

			double P = (double)v[i]/(double)sum;

			if(abs(P - expected_probability)> threshold)
	    		is_random = false;
		    
		    std::cout<<i<<": "<<std::setprecision(4)<<P<<", ";
		}

		std::cout<<"\n \nThe probabilities of transitions are: \n";
		
		for(int i=0;i<10;i++){
		    for(int j=0;j<10;j++){

		    	double P = (double)mat[i][j]/(double)row_sum[i];

		    	if(abs(P - expected_probability)> threshold)
	    		is_random = false;	
		        
		        std::cout<<std::setprecision(4)<<P<<"\t";
		    }
		    std::cout<<"\n";
		}

		return is_random;
	}
};
