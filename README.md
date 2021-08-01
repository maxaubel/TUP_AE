# Traveling Umpire Problem
## Evolutionary Algorithm

This approach solves the TUP with an EA.


### To compile:
	
	$ make

### To run:
	
	$ TUP <instance file> <q1> <q2> <number of iterations> <optional: population size>

### Example:

	$ TUP instances/umps16.txt 3 2 10000 100

This will find solutions for the instance stored in ``instances/umps16.txt`` with ``q1=3``,  ``q2=3``, it will iterate 10000 times, and the population size for each generation will be 100. The programm will run up to 2 hours only, if you want to run it longer, you will need to edit this value (7200 seconds) in ``main.cpp``.