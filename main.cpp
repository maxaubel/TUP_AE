#include <bits/stdc++.h>
#include <iostream>
#include <regex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

#include "individual.h"
#include "utils.h"
#include "common.h"

/*vector<vector <int>> dist;
vector<vector <int>> opponents;
vector<vector <int>> home_venues;
int q1;
int q2;
int POPULATION_SIZE;*/

int main(int argc, char const *argv[]){

    POPULATION_SIZE = 100;
    int nIter;
    if (argc == 6)
        POPULATION_SIZE = stoi( argv[5] );

    string filename = argv[1];
    q1 = stoi( argv[2] );
    q2 = stoi( argv[3] );
    nIter = stoi( argv[4] );

    // READ FILE
    FILE *fp;
    fp = fopen(filename.c_str(), "r");
    int buffer_size = 1000;
    char buffer [buffer_size];
    fgets(buffer, buffer_size, fp);
    int nTeams = stoi(regex_replace(buffer, regex("[^0-9]*([0-9]+).*"), string("$1")));
    int nRounds = 2*nTeams-2;
    // int nUmpires = static_cast<int>(ceil(nTeams/2));

    while( fgets(buffer, buffer_size, fp) ) {
        if( buffer[0] == 'd' ) {
            for (int i = 0; i < nTeams; ++i) {
                vector<int> v;
                fgets(buffer, buffer_size, fp);
                int* one_line = tokenize(buffer, nTeams);
                for (int j = 0; j < nTeams; ++j)
                    v.push_back(one_line[j]);
                dist.push_back(v);
            }
        }

        if( buffer[0] == 'o' ) {
            for (int i = 0; i < nRounds; ++i) {
                vector<int> v;
                fgets(buffer, buffer_size, fp);
                int* one_line = tokenize(buffer, nTeams);
                for (int j = 0; j < nTeams; ++j)
                    v.push_back(one_line[j]);
                opponents.push_back(v);
            }
        }
    }
    fclose(fp);

    // tuples of home venues for each round
    home_venues = generate_home_venues(); // OK for nUmpires

    // Actual AE:
    // int generation = 0;
    srand((unsigned)(time(0)));
    vector<Individual> population;

    // Generate first generation
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        vector<vector<int>> gnome = create_gnome();
        population.push_back(Individual(gnome));
    }

    int current_iter = 0;
    time_t stop;
    time_t start = time(NULL);

    printf("generation;fitness;q1;q2;home_venue;fitness_sum\n");

    while(current_iter <= nIter) {
        
        sort( population.begin(), population.end());

        // Generate a new generation
        vector<Individual> new_generation;

        // Elitism, 10% of best population goes to the next generation
        int s = (10 * POPULATION_SIZE) / 100;
        for (int i = 0; i < s; i++)
            new_generation.push_back( population[i] );


        // Mate 50% of the remaining population
        s = (90 * POPULATION_SIZE) / 100;

        for (int i = 0; i < s; i++) {
            int len = population.size()*0.5;
            
            int r = random_num(0, len);
            Individual parent1 = population[r];
            
            r = random_num(0, len);
            Individual parent2 = population[r];

            Individual child = parent1.mate(parent2);
            new_generation.push_back( child );
        }
        population = new_generation;
        current_iter++;


        /*int i = 0;
        printf("\nGeneration: %d && ", current_iter);
        printf("Fitness individual %d: %d, home_venue: %d", i, population[i].fitness, home_venue_constraint(population[i].chromosome));
        printf(", q1: %d", q1_constraint(population[0].chromosome));
        printf(", q2: %d", q2_constraint(population[0].chromosome));
        */

        int fitness_sum = 0;
        for (int i = 0; i < population.size(); ++i)
            fitness_sum += population[i].fitness;

        printf("%d;%d;%d;%d;%d;%d\n", 
            current_iter, 
            population[0].fitness, 
            q1_constraint(population[0].chromosome), 
            q2_constraint(population[0].chromosome), 
            home_venue_constraint(population[0].chromosome),
            fitness_sum);

        stop = time(NULL);

        if (stop-start >= 7200) { //7200 s = 2 h
            printf("\n\nMaximum run time of 2 hours reached before reaching %d!!\n", nIter);
            break;
        }
    }
    //auto stop = high_resolution_clock::now(); /////////
    //auto duration = duration_cast<microseconds>(stop - start);

    sort( population.begin(), population.end());

    printf("\nGeneration: %d\n~~~~~~~~~~~~~~~~", current_iter);

    printf("\n\nFitness: %d", population[0].fitness);
    population[0].print_umpires();
 
    printf("\n\nHome venue constraint?: %d", home_venue_constraint(population[0].chromosome));
    printf("\nQ1 (Q1=%d) constraint?: %d", q1, q1_constraint(population[0].chromosome));
    printf("\nQ2 (Q2=%d) constraint?: %d\n", q2, q2_constraint(population[0].chromosome));

    printf("Population Size: %d\n", POPULATION_SIZE);
    printf("Time taken by loop: %ld seconds\n",  stop-start);
    printf("Average time per generation: %ld microseconds, or around %ld miliseconds\n", (stop-start)/(1000000*current_iter), (stop-start)/(1000*current_iter));

    return 0;
}
