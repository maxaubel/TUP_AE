#ifndef COMMON_H
#define COMMON_H

using namespace std;
using namespace std::chrono;

extern vector<vector <int>> dist;
extern vector<vector <int>> opponents;
extern vector<vector <int>> home_venues;
extern int q1;
extern int q2;

extern int POPULATION_SIZE;

# define HOME_VENUE_PENALIZATION 5000
# define Q1_PENALIZATION 5000
# define Q2_PENALIZATION 5000

#endif