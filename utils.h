#ifndef UTILS_H
#define UTILS_H

// clean a string from file
std::string str_cleaner(std::string line);

// tokenize a line from the text file
int* tokenize(std::string line, int nTeams);

void printf_vector(std::vector<int> v);

// each umpire must visit each venue at least once
int home_venue_constraint(std::vector<std::vector<int>> chromosome);

int q1_constraint(std::vector<std::vector<int>> chromosome);

int q2_constraint(std::vector<std::vector<int>> chromosome);

// generate a random number
int random_num(int start, int end);

std::vector<int> mutated_genes(std::vector<int> round);

// create a chromosome (random sequence of genes)
std::vector<std::vector<int>> create_gnome();

// overload operator < to easily sort by fitness
bool operator<(const Individual &ind1, const Individual &ind2);

// RESTRICTIONS
std::vector<std::vector<int>> generate_home_venues();

#endif