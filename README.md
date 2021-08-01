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

## Scripts

I added some scripts that helped me try many combinations of parameters:

* `script.sh` will just run many instances with the defined parameters sequentially.
* `script_for.sh` will run 3 parallel instances simultaneously to save some time.
* `script_parallel.sh` **don not use this script.** It will probably freeze you computer, because it will start many many parallel instances.
* `script_pop_size.sh` will iterate over a number of predefined population sizes.
