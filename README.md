# Monte-Hall-Experiment
An experiment for verifying the solution to Monte Hall problem

The Monty Hall problem is a brain teaser, in the form of a probability puzzle, loosely based on the American television game show Let's Make a Deal and named after its original host, Monty Hall. 

Problem Statement:
Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the others, goats. You pick a door, say No. 1, and the host, who knows what's behind the doors, opens another door, say No. 3, which has a goat. He then says to you, "Do you want to pick door No. 2?" Is it to your advantage to switch your choice?

Answer:
The answer to this problem is based on conditional probability. When we first made the choice, the probability of it being the correct one was 1/3 and therefore the probability that the correct door was one of the other two doors was 2/3. After the gameshow host reveal one of the two bad doors, probability of the 2nd door becomes 2/3 as the probability of the correct door being one of those two doors is still 2/3. Thus we should leave our current choice which has 1/3 chance of winning for the other door which has now 2/3 chance of winning. 
Many people (including me at one point) and even some mathematicians think that both the doors should have an equal chance of winning and thus it makes no difference to change the current choice. 

Let's see what the experiment tells us!

## test.cpp
This file contains code for testing the uniformity of cpp's rand() function
Uniformity has been checked using the following 2 citeria:
1. The occurance of each number in a fixed range should be approximately the same over a large number of iterations
2. The probability of occurance of a number should be independant of the previously generated number
 
## experiment.cpp
After establishing credibility of the random function, we can carry on with the simulation of the experiment
This file has code for generating simulation of the gameshow.The result is calculated using 1000000 simulations.

# Results
## Test Result
![Tests](https://github.com/piyushmathur17/Monte-Hall-Experiment/blob/master/img/testing.png)

## Experiment Result
![Experiment](https://github.com/piyushmathur17/Monte-Hall-Experiment/blob/master/img/experiment.png)

As we can see, the percentage of wins by making the switch is around 66.66% (2/3 chance). So we should make the switch afterall! 
