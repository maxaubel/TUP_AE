# Traveling Umpire Problem
## Evolutionary Algorithm

This approach solves the TUP with an EA.


### To compile:
	
	$ make

### To run:
	
	$ TUP <instance file> <q1> <q2> <number of iterations> <optional: population size>

### Example:

	$ TUP instances/umps16.txt 3 2 10000 100

This will find solutions for the instance stored in ``instances/umps16.txt`` with ``q1=3``,  ``q2=2``, it will iterate 10000 times, and the population size for each generation will be 100. The programm will run up to 2 hours only, if you want to run it longer, you will need to edit this value (7200 seconds) in ``main.cpp``.

## Input

The input for each instance mmust have this format:
	
	nTeams=N;
	dist= [
	    [ 0 D12 D13 D14 ... D1N]
		[ D21 0 D23 D24 ... D2N]
		[ D31 D32 0 D34 ... D3N]
		[ D41 D42 D43 0 ... D4N]
		[ ... ... ... ... ... ...]
		[ DN1 DN2 DN3 DN4 ... 0 ]
		];
	opponents=[
	[ O11 O12 O13 O14 ... O1N]
	[ O21 O22 O23 O24 ... O2N]
	[ O31 O32 O33 O34 ... O3N]
	[ O41 O42 O43 O44 ... O4N]
	[ ... ... ... ... ... ...]
	[ OR1 OR2 OR3 OR4 ... ORN]
	];


## Output

The program will first print the following lines. You can take this and pipe it to a text file to test its performance

	generation;fitness;q1;q2;home_venue;fitness_sum
	1;1836576;430000;285000;345000;182624438
	2;1690332;335000;260000;310000;178157176
	3;1668551;330000;225000;345000;175103714
	4;1606437;310000;265000;260000;172337219
	5;1597485;310000;285000;250000;168815962
	6;1537768;290000;240000;235000;168182719
	...

After the 2 hours have passed or the maximum iterations have been reached, the program will print a summary of the result, for example:

	Fitness: 36482
	Umpire 0:   9 7 3 2 3 2 4 10 8 10 6 5 1 5 3 2 4 2 
	Umpire 1:   6 4 6 8 9 6 5 1 7 3 2 9 8 10 7 3 2 4 
	Umpire 2:   4 6 4 3 2 10 8 7 1 7 9 6 5 8 10 8 9 10 
	Umpire 3:   1 5 1 7 10 9 6 8 10 9 4 2 4 1 6 7 3 5 
	Umpire 4:   5 1 7 10 8 5 1 5 3 2 3 4 6 7 1 9 8 9 

	Home venue constraint?: 0
	Q1 (Q1=1) constraint?: 0
	Q2 (Q2=1) constraint?: 0
	Population Size: 1000
	Time taken by loop: 55 seconds
	Average time per generation: 55882 microseconds, or around 55 miliseconds

If the value of a constraint is 0, it means that the constraint is fully satisfied.


## Scripts

I added some scripts that helped me try many combinations of parameters:

* `script.sh` will just run many instances with the defined parameters sequentially.
* `script_for.sh` will run 3 parallel instances simultaneously to save some time.
* `script_parallel.sh` **don not use this script.** It will probably freeze you computer, because it will start many many parallel instances.
* `script_pop_size.sh` will iterate over a number of predefined population sizes.
