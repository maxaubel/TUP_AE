#include <bits/stdc++.h>
#include <iostream>
#include <regex>
//#include <string>
//#include <string.h>
//#include <algorithm>

using namespace std;

# define POPULATION_SIZE = 100

int random_num(int start, int end) {
    int range = (end - start) + 1;
    int random_int = start + (rand()%range);
    return random_int;
}


 

string str_cleaner(string line) {
    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    return line;
}

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




int main(int argc, char const *argv[]){

    int q1, q2, nIter;

    // temporary
    string filename = "instancias/umps4.txt";
    //

    FILE *fp;
    fp = fopen(filename.c_str(), "r");
    int buffer_size = 1000;
    char buffer [buffer_size];
    fgets(buffer, buffer_size, fp);
    int nTeams = stoi(regex_replace(buffer, regex("[^0-9]*([0-9]+).*"), string("$1")));
    int nRounds = 2*nTeams-2;       
    int dist[nTeams][nTeams];
    int opponents[nRounds][nTeams];
    

    while( fgets(buffer, buffer_size, fp) ){

        if( buffer[0] == 'd' ){
            for (int i = 0; i < nTeams; ++i)
            {
                fgets(buffer, buffer_size, fp);
                int* one_line = tokenize(buffer, nTeams);
                for (int j = 0; j < nTeams; ++j)
                    dist[i][j] = one_line[j];
            }
        }

        if( buffer[0] == 'o' ){
            for (int i = 0; i < nRounds; ++i)
            {
                fgets(buffer, buffer_size, fp);
                int* one_line = tokenize(buffer, nTeams);
                for (int j = 0; j < nTeams; ++j)
                    opponents[i][j] = one_line[j];
            }
        }
    }
    fclose(fp);

    

    return 0;
}




