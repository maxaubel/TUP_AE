#include <bits/stdc++.h>
#include <iostream>
#include <regex>
#include <vector>

//#include <string>
//#include <string.h>
//#include <algorithm>
using namespace std;

vector<vector <int>> dist;
vector<vector <int>> opponents;

# define POPULATION_SIZE 100

int random_num(int start, int end) {
    int range = (end - start) + 1;
    int random_int = start + (rand()%range);
    return random_int;
}

int mutated_genes(int nTeams) {
    int r = random_num(0, nTeams-1);
    return r;
}

// create a chromosome (random sequence of genes)
int* create_gnome(int nTeams) {
    int nRounds = 2*nTeams - 2;
    int* gnome = new int[nRounds];
    for (int i = 0; i < nRounds; ++i)
        gnome[i] = mutated_genes(nRounds);

    return gnome;

}

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

// class to represent an individual from in a population
class Individual {
public: 
    int* chromosome;
    int fitness;
    Individual (int* chromosome, int nRounds);
    Individual mate(Individual parent2);
    int cal_fitness();
    int nRounds;
};

// initialize an individual with its own chromosome
Individual::Individual(int* chromosome, int nRounds) {
    this-> chromosome = chromosome;
    fitness = cal_fitness();
    this-> nRounds = nRounds;
}

Individual Individual::mate(Individual par2) {
    // int len =  sizeof(chromosome)/sizeof(chromosome[0]);
    int* child_chromosome = new int[nRounds];  

    for (int i = 0; i < nRounds; i++)
    {
        // random probability
        float p = random_num(0, 100) / 100;

        // insert gene from parent 1 if p<0.45
        if (p < 0.45)
            child_chromosome[i] = chromosome[i];

        // insert gene from parent 2 if 0.45 < p < 0.90
        else if (p < 0.90)
            child_chromosome[i] = par2.chromosome[i];

        // insert random gene if 0.90 < p
        else
            child_chromosome[i] = mutated_genes(nRounds);
    }

    return Individual(child_chromosome, nRounds);
}

int Individual::cal_fitness() {
    int fitness = 0;
    int nTeams = (nRounds+2) / 2;

    for (int i = 0; i < nTeams; ++i)
    {
        for (int j = 0; j < nTeams; ++j)
        {
            cout << dist[i][j] << ", ";
        }
        cout << endl;
        fitness ++;
    }



    return fitness;
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
    //int dist[nTeams][nTeams];
    //int opponents[nRounds][nTeams];
    

    while( fgets(buffer, buffer_size, fp) ){

        if( buffer[0] == 'd' ){

            for (int i = 0; i < nTeams; ++i)
            {
                vector<int> v;
                fgets(buffer, buffer_size, fp);
                int* one_line = tokenize(buffer, nTeams);
                for (int j = 0; j < nTeams; ++j)
                    v.push_back(one_line[j]);
                    //dist[i][j] = one_line[j];
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
                    //opponents[i][j] = one_line[j];
                opponents.push_back(v);
            }
        }
    }
    fclose(fp);


    for (int i = 0; i < opponents.size(); ++i)
    {
        for (int j = 0; j < opponents[i].size(); ++j)
        {
            cout << opponents[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

    int generation = 0;
    srand((unsigned)(time(0)));
    vector<Individual> population;

    // Generate first generation
    for (int i = 0; i < POPULATION_SIZE; ++i)
    {
        int* gnome = create_gnome(nTeams);
        population.push_back(Individual(gnome, nRounds));
    }

    for (int i = 0; i < nRounds; ++i)
        cout << population[0].chromosome[i] << ", ";
    
    cout << endl;
    for (int i = 0; i < nRounds; ++i)
        cout << population[1].chromosome[i] << ", ";
    cout << endl;
    
    
    Individual child = population[0].mate(population[1]);
    
    for (int i = 0; i < nRounds; ++i)
        cout << child.chromosome[i] << ", ";
    


    return 0;
}







