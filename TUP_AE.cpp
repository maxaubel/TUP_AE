#include <bits/stdc++.h>
#include <iostream>
#include <regex>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector <int>> dist;
vector<vector <int>> opponents;
vector<vector <int>> home_venues;
int q1;
int q2;


# define POPULATION_SIZE 200
# define HOME_VENUE_PENALIZATION 5000
# define Q1_PENALIZATION 5000
# define Q2_PENALIZATION 5000


/*
* for nTeams = 4 and q1 = 1:
    pop_size: 50
    home venue penalization and q1 values: 10000


* for nTeams <= 18:
    home venue penalization and q1 values: 10000
for nTeams <= 20:
    home venue penalization and q1 values: 100000
    Max_iter = 10000 o más

for nTeams <= 30:
    home venue penalization and q1 values: 
    Max_iter = 

*/


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

////////////////////////////////////////////////////////////////////////////////////////////////////



void printf_vector(vector<int> v) {
    int i=0;
    for (; i < v.size()-1; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("%d\n", v[i]);
    return;
}

// each umpire must visit each venue at least once
int home_venue_constraint(vector<vector<int>> chromosome) {

    vector< vector<int> > chromosome_T(chromosome[0].size(), vector<int>(chromosome.size()));

    for (vector<int>::size_type i(0); i < chromosome[0].size(); ++i)
        for (vector<int>::size_type j(0); j < chromosome.size(); ++j)
            chromosome_T[i][j] = chromosome[j][i];

    int n = 0; // number of times where constraint is not met

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
        //printf_vector(chromosome_T[0]);
        for (int j = 0; j < chromosome_T[i].size(); ++j)
        {
            for (int k = 1; k <= q2 and j+k<chromosome_T[i].size(); k++)
            {   
                int current_local = abs(chromosome_T[i][j]);
                int current_visitor = abs(opponents[i][chromosome_T[i][j]-1]);

                int future_local = abs(chromosome_T[i][j+k]);
                int future_visitor = abs(opponents[i][chromosome_T[i][j+k]-1]);

                //printf("i: %d, j: %d, k: %d -> ", i, j, k);
                //printf("%d, %d, %d, %d\n", current_local, current_visitor, future_local, future_visitor);

                if ((current_local == future_local) or
                    (current_local == future_visitor) or
                    (current_visitor == future_local) or
                    (current_visitor == future_visitor))

                    //printf("failed!\n");
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

        //random_shuffle(gnome[i].begin(), gnome[i].end());
    }

    return gnome;
}

// class to represent an individual from in a population
class Individual {
public: 
    vector<vector<int>> chromosome;
    int fitness;
    Individual (vector<vector<int>> chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();
    void print_umpires();
};

// initialize an individual with its own chromosome
Individual::Individual(vector<vector<int>> chromosome) {
    this-> chromosome = chromosome;
    fitness = cal_fitness();
}

// mate 2 individuals: parent1.mate(parent2)
Individual Individual::mate(Individual par2) {

    vector<vector<int>> child_chromosome;
    int len = chromosome.size();
    int nTeams = (chromosome.size()+2)/2;

    // cout << "fitness: " << fitness << endl;


    for (int i = 0; i < len; i++)
    {
        // random probability
        float p = random_num(0, 100);

        // insert gene from parent 1 if p<0.45
        if (p < 45) {
            child_chromosome.push_back(chromosome[i]);
        }

        // insert gene from parent 2 if 0.45 < p < 0.90
        else if (p < 90){
            child_chromosome.push_back(par2.chromosome[i]);
        }

        // insert random gene if 0.90 < p
        else{
            child_chromosome.push_back(mutated_genes(home_venues[i]));
        }
    }


    return Individual(child_chromosome);
}

// calculate the fitness of an individual by adding up its total distance
// constraints are considered as a fitness penalization
int Individual::cal_fitness() {
    fitness = 0;
    int len = chromosome.size();

    for (int i = 0; i < chromosome[0].size(); ++i)
    {
        for (int j = 0; j < chromosome.size()-1; ++j)
        {
            fitness += dist[ chromosome[j][i]-1 ][ chromosome[j+1][i]-1 ];
        }
    }

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

int main(int argc, char const *argv[]){

    int nIter;

    if (argc != 5) {
        printf("Incorrect number of parameters. Expected 5, received %d!!!\n\n", argc);
        return -1;
    }

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
    int nUmpires = static_cast<int>(ceil(nTeams/2));

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

    int generation = 0;
    srand((unsigned)(time(0)));
    vector<Individual> population;



    // Generate first generation
    for (int i = 0; i < POPULATION_SIZE; ++i)
    {
        vector<vector<int>> gnome = create_gnome();
        population.push_back(Individual(gnome));


    }




    int current_iter = 0;

    while(current_iter <= nIter) {
        
        sort( population.begin(), population.end());

        // generate a new generation
        vector<Individual> new_generation;


        // Elitism, 10% of best population goes to the next generation
        int s = (10 * POPULATION_SIZE) / 100;
        for (int i = 0; i < s; i++)
            new_generation.push_back( population[i] );


        // Mate the 50% of the remaining population
        s = (90 * POPULATION_SIZE) / 100;
        for (int i = 0; i < s; i++)
        {
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


        printf("\nGeneration: %d && ", current_iter);

        int i = 0;
        printf("Fitness individual %d: %d, home_venue: %d", i, population[i].fitness, home_venue_constraint(population[i].chromosome));
        printf(", q1: %d", q1_constraint(population[0].chromosome));
        printf(", q2: %d", q2_constraint(population[0].chromosome));

    }
    sort( population.begin(), population.end());

    printf("\nGeneration: %d\n~~~~~~~~~~~~~~~~", current_iter);
    
    printf("\nq1: %d", q1);

    printf("\n\nFitness individual %d: %d", 0, population[0].fitness);
    population[0].print_umpires();

 
    printf("\nHome venue constraint?: %d", home_venue_constraint(population[0].chromosome));
    printf("\nQ1 constraint?: %d", q1_constraint(population[0].chromosome));
    printf("\nQ2 constraint?: %d\n", q2_constraint(population[0].chromosome));

    return 0;
}
