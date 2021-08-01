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

using namespace std;
using namespace std::chrono;

vector<vector <int>> dist;
vector<vector <int>> opponents;
vector<vector <int>> home_venues;
int q1;
int q2;

int POPULATION_SIZE;

// clean a string from file
string str_cleaner(string line) {
    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    return line;
}

// tokenize a line from the text file
int* tokenize(string line, int nTeams) {

    line = str_cleaner(line);
    string* parsed_line = new string[nTeams];
    int* dist_values = new int[nTeams];
    stringstream ssin(line);
    int i = 0;

    while (ssin.good() && i < nTeams) {
        ssin >> parsed_line[i];
        ++i;
    }

    for (int i = 0; i < nTeams; ++i)
        dist_values[i] = stoi(parsed_line[i]);

    return dist_values;
}


void printf_vector(vector<int> v) {
    int i=0;
    for (; i < v.size()-1; i++)
        printf("%d, ", v[i]);
    printf("%d\n", v[i]);
    return;
}

// each umpire must visit each venue at least once
int home_venue_constraint(vector<vector<int>> chromosome) {

    vector< vector<int> > chromosome_T(chromosome[0].size(), vector<int>(chromosome.size()));
    int n = 0; // number of times where constraint is not met

    for (vector<int>::size_type i(0); i < chromosome[0].size(); ++i)
        for (vector<int>::size_type j(0); j < chromosome.size(); ++j)
            chromosome_T[i][j] = chromosome[j][i];


    for (int i = 0; i < chromosome_T.size(); ++i)
        for (int j = 1; j <= dist.size(); ++j)
            if(not (find(chromosome_T[i].begin(), chromosome_T[i].end(), j) != chromosome_T[i].end()) )
                n++;

    return n*HOME_VENUE_PENALIZATION;
}



int q1_constraint(vector<vector<int>> chromosome) {
    
    int penalization = 0;
    vector< vector<int> > chromosome_T(chromosome[0].size(), vector<int>(chromosome.size()));

    for (vector<int>::size_type i(0); i < chromosome[0].size(); ++i)
        for (vector<int>::size_type j(0); j < chromosome.size(); ++j)
            chromosome_T[i][j] = chromosome[j][i];

    for (int i = 0; i < chromosome_T.size(); ++i)
        for (int j = 0; j < chromosome_T[i].size(); ++j)
            for (int k = 1; k <= q1 and j+k<chromosome_T[i].size(); k++)  
                if (chromosome_T[i][j] == chromosome_T[i][j+k])
                    penalization += Q1_PENALIZATION;

    return penalization;
}


int q2_constraint(vector<vector<int>> chromosome) {

    int penalization = 0;
    vector< vector<int> > chromosome_T(chromosome[0].size(), vector<int>(chromosome.size()));

    for (vector<int>::size_type i(0); i < chromosome[0].size(); ++i)
        for (vector<int>::size_type j(0); j < chromosome.size(); ++j)
            chromosome_T[i][j] = chromosome[j][i];

    for (int i = 0; i < chromosome_T.size(); ++i)
    {
        for (int j = 0; j < chromosome_T[i].size(); ++j)
        {
            for (int k = 1; k <= q2 and j+k<chromosome_T[i].size(); k++)
            {   
                int current_local = abs(chromosome_T[i][j]);
                int current_visitor = abs(opponents[i][chromosome_T[i][j]-1]);
                int future_local = abs(chromosome_T[i][j+k]);
                int future_visitor = abs(opponents[i][chromosome_T[i][j+k]-1]);

                if ((current_local == future_local)   or
                    (current_local == future_visitor) or
                    (current_visitor == future_local) or
                    (current_visitor == future_visitor))

                    penalization += Q2_PENALIZATION;
            }
        }
    }

    return penalization;
}


// generate a random number
int random_num(int start, int end) {
    int range = (end - start) + 1;
    int random_int = start + (rand()%range);
    return random_int;
}

vector<int> mutated_genes(vector<int> round) {
    vector<int> round_c = round;
    random_shuffle(round_c.begin(), round_c.end());
    return round_c;
}

// create a chromosome (random sequence of genes)
vector<vector<int>> create_gnome() {
    vector<vector<int>> gnome = home_venues;
    auto rng = std::default_random_engine {};

    for (int i = 0; i < gnome.size(); ++i) {
        std::shuffle(std::begin(gnome[i]), std::end(gnome[i]), rng);
    }

    return gnome;
}

// overload operator < to easily sort by fitness
bool operator<(const Individual &ind1, const Individual &ind2)
{
    return ind1.fitness < ind2.fitness;
}

// RESTRICTIONS
vector<vector<int>> generate_home_venues() {
    
    vector<vector <int>> home_venues; // the nUmpires home venues for each round
    
    for (int i = 0; i < opponents.size(); ++i) {
        vector<int> round;

        for (int j = 0; j < opponents[i].size(); ++j)
            if (opponents[i][j] < 0)
                round.push_back( -opponents[i][j] );

        home_venues.push_back(round);
    }

    return home_venues;
}
