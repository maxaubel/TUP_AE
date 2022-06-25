#include <cuda_runtime.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <regex>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<vector <int>> dist;
vector<vector <int>> opponents;
vector<vector <int>> home_venues;

int q1;
int q2;

int POPULATION_SIZE;

# define HOME_VENUE_PENALIZATION 5000
# define Q1_PENALIZATION 5000
# define Q2_PENALIZATION 5000

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

