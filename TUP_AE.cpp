#include <bits/stdc++.h>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

vector<vector <int>> dist;
vector<vector <int>> opponents;
vector<vector <int>> home_venues;

# define POPULATION_SIZE 100
# define MAX_ITER 200


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


// generate a random number
int random_num(int start, int end) {
    int range = (end - start) + 1;
    int random_int = start + (rand()%range);
    return random_int;
}

int mutated_genes(vector<int> round) {
    int home_venue = round[(rand()%2)]-1;

    return home_venue;
}

// create a chromosome (random sequence of genes)
vector<int> create_gnome(int nTeams) {
    int nRounds = 2*nTeams - 2;
    vector<int> gnome;
    for (int i = 0; i < nRounds; ++i)
        gnome.push_back(mutated_genes(home_venues[i]));

    return gnome;
}


int get_the_other_venue(int round_n, int ump1) { /////////////////////////////////////////////////// TODO

    // int ump2 = -ump1 + 1; // get the alternate home venue


    if (home_venues[round_n][0] == ump1)
        return home_venues[round_n][1];

    return home_venues[round_n][0];
}

// class to represent an individual from in a population
class Individual {
public: 
    vector<int> chromosome;
    int fitness;
    Individual (vector<int> chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();
};

// initialize an individual with its own chromosome
Individual::Individual(vector<int> chromosome) {
    this-> chromosome = chromosome;
    fitness = cal_fitness();
}

// mate 2 individuals: parent1.mate(parent2)
Individual Individual::mate(Individual par2) {

    vector<int> child_chromosome;
    int len = chromosome.size();
    int nTeams = (chromosome.size()+2)/2;

    // cout << "fitness: " << fitness << endl;

    for (int i = 0; i < len; i++)
    {
        // random probability
        float p = random_num(0, 100) / 100;

        // insert gene from parent 1 if p<0.45
        if (p < 0.45)
            child_chromosome.push_back(chromosome[i]);

        // insert gene from parent 2 if 0.45 < p < 0.90
        else if (p < 0.90)
            child_chromosome.push_back(par2.chromosome[i]);            

        // insert random gene if 0.90 < p
        else
            child_chromosome.push_back(mutated_genes(home_venues[i]));
    }

    return Individual(child_chromosome);
}

// calculate the fitness of an individual by adding up its total distance
int Individual::cal_fitness() {
    fitness = 0;
    int len = chromosome.size();

    for (int i = 0; i < len-1; i++) {
        
        // Umpire 1
        fitness += dist[chromosome[i]][chromosome[i+1]];

        // Umpire 2
        int ump2_start = get_the_other_venue(i, chromosome[i]+1);
        int ump2_end = get_the_other_venue(i, chromosome[i+1]+1);

        fitness += dist[ump2_start][ump2_end];
    }
    
    return fitness;
}

// overload operator < to easily sort by fitness
bool operator<(const Individual &ind1, const Individual &ind2)
{
    return ind1.fitness < ind2.fitness;
}


// RESTRICTIONS
vector<vector<int>> generate_home_venues() {
    
    vector<vector <int>> home_venues; // the 2 home venues for each round
    
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

    int q1, q2, nIter;

    // temporary
    string filename = "instancias/umps4.txt";
    //



    // READ FILE
    FILE *fp;
    fp = fopen(filename.c_str(), "r");
    int buffer_size = 1000;
    char buffer [buffer_size];
    fgets(buffer, buffer_size, fp);
    int nTeams = stoi(regex_replace(buffer, regex("[^0-9]*([0-9]+).*"), string("$1")));
    int nRounds = 2*nTeams-2;
    

    while( fgets(buffer, buffer_size, fp) ){

        if( buffer[0] == 'd' ){

            for (int i = 0; i < nTeams; ++i)
            {
                vector<int> v;
                fgets(buffer, buffer_size, fp);
                int* one_line = tokenize(buffer, nTeams);
                for (int j = 0; j < nTeams; ++j)
                    v.push_back(one_line[j]);
                dist.push_back(v);
            }
        }

        if( buffer[0] == 'o' ){
        
            for (int i = 0; i < nRounds; ++i)
            {
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
    home_venues = generate_home_venues();


    //actual AE

    int generation = 0;
    srand((unsigned)(time(0)));
    vector<Individual> population;


    // Generate first generation
    for (int i = 0; i < POPULATION_SIZE; ++i)
    {
        vector<int> gnome = create_gnome(nTeams);
        population.push_back(Individual(gnome));
    }

    int current_iter = 0;

    while(current_iter <= MAX_ITER) {
        
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
            int len = population.size();
            
            int r = random_num(0, 50);
            Individual parent1 = population[r];
            
            r = random_num(0, 50);
            Individual parent2 = population[r];

            Individual child = parent1.mate(parent2);
            new_generation.push_back( child );
        }
        population = new_generation;

        current_iter++;


        printf("Generation: %d && ", current_iter);
        printf("Sequence: ");
        for (int i = 0; i < population[0].chromosome.size(); ++i)
        {
            printf("%d , ", population[0].chromosome[i]);
        }
        int sum = 0;
        for (int i = 0; i < population.size(); ++i)
        {
            sum += population[i].fitness;
        }
        printf(" && Gen total fitness: %d\n", sum);


    }

    printf("Generation: %d && ", current_iter);
    printf("Umpire1: ");
    for (int i = 0; i < population[0].chromosome.size(); ++i)
    {
        printf("%d -> ", population[0].chromosome[i]+1);
    }

    printf("Umpire2: ");
    for (int i = 0; i < population[0].chromosome.size(); ++i)
    {
        printf("%d -> ", get_the_other_venue(i, population[0].chromosome[i]+1));
    }
    printf("&& Fitness: %d\n", population[0].fitness);



    return 0;
}







