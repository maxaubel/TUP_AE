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

// initialize an individual with its own chromosome
Individual::Individual(std::vector<std::vector<int>> chromosome) {
    this-> chromosome = chromosome;
    fitness = cal_fitness();
}

// mate 2 individuals: parent1.mate(parent2)
Individual Individual::mate(Individual par2) {

    std::vector<std::vector<int>> child_chromosome;
    int len = chromosome.size();
    //int nTeams = (chromosome.size()+2)/2;

    for (int i = 0; i < len; i++)
    {
        // random probability
        float p = random_num(0, 100);

        // insert gene from parent 1 if p<0.45
        if (p < 45)
            child_chromosome.push_back(chromosome[i]);

        // insert gene from parent 2 if 0.45 < p < 0.90
        else if (p < 90)
            child_chromosome.push_back(par2.chromosome[i]);

        // insert random gene if 0.90 < p
        else
            child_chromosome.push_back(mutated_genes(home_venues[i]));
    }

    return Individual(child_chromosome);
}

// calculate the fitness of an individual by adding up its total distance
// constraints are considered as a fitness penalization
int Individual::cal_fitness() {
    fitness = 0;
    //int len = chromosome.size();

    for (int i = 0; i < chromosome[0].size(); ++i)
        for (int j = 0; j < chromosome.size()-1; ++j)
            fitness += dist[ chromosome[j][i]-1 ][ chromosome[j+1][i]-1 ];

    fitness += home_venue_constraint(chromosome);
    fitness += q1_constraint(chromosome);
    fitness += q2_constraint(chromosome);
    
    return fitness;

}

void Individual::print_umpires() {
    for (int i = 0; i < chromosome[0].size(); ++i)
    {
        printf("\nUmpire %d:   ", i);
        for (int j = 0; j < chromosome.size(); ++j)
            printf("%d ", chromosome[j][i]);
    }
    return;
}