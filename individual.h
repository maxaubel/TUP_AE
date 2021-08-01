#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

// class to represent an individual from in a population
class Individual {
public: 
    std::vector<std::vector<int>> chromosome;
    int fitness;
    Individual (std::vector<std::vector<int>> chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();
    void print_umpires();
};

#endif