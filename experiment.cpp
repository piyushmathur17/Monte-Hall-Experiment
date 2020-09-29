
class Experiment{
public: 
	static unsigned int experiment_no;

	void conduct_experiment(){
    	
    	experiment_no++;
	    //simulating the events of the gameshow
		//wins keeps track of how many games were won after switching to other door
		//losses keeps track of how many games were lost after switching other door
		//percentage of wins should be around 66.66% according to theory 
		unsigned int wins=0,losses =0;
		
		//number_of_samples is the number of times the experiment is repeated
		const unsigned int number_of_samples = 1000000; 
		
		for(int i=0;i<number_of_samples;i++){
		    int correct_door = rand()%3;
		    int initial_choice = rand()%3;
		    //gameshow host chooses one of the bad doors to open
		    int incorrect_door;
		    if(initial_choice!=correct_door){
		        incorrect_door = 3 - initial_choice - correct_door;
		    }
		    else {
		        incorrect_door = rand()%2;
		        if(incorrect_door==0 && correct_door==0)incorrect_door++;
		        else if( incorrect_door==1 && (correct_door == 0 || correct_door == 1))
		            incorrect_door++;
		    }
		    
		    //the contestant now chooses the other door 
		    int new_door = 3 - initial_choice - incorrect_door;
		    if(new_door == correct_door)wins += 1;
		    else losses+=1;
		}
		std:: cout<<"Experiment No: "<<experiment_no<<"\n";
		std:: cout<<"wins: "<<wins<<"\t"<<"losses: "<<losses<<std::endl;
		std:: cout<<"winning percentage: "<<std::setprecision(9)<<100.0*wins/(wins+ losses)<<"\n\n";
	}
};

unsigned int Experiment::experiment_no = 0;
