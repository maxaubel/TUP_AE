#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int myrandom(int i) { return rand()%i;}

void printf_vector(vector<int> v) {
    int i=0;
    for (; i < v.size()-1; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("%d\n", v[i]);
    return;
}

bool home_venue_constraint(vector<vector<int>> chromosome) {


    vector< vector<int> > chromosome_T(chromosome[0].size(), vector<int>(chromosome.size()));

    for (vector<int>::size_type i(0); i < chromosome[0].size(); ++i)
        for (vector<int>::size_type j(0); j < chromosome.size(); ++j)
            chromosome_T[i][j] = chromosome[j][i];


    for (int i = 0; i < chromosome.size(); ++i) {
        printf_vector(chromosome[i]);    
    }

    for (int i = 0; i < chromosome_T.size(); ++i) {
        printf_vector(chromosome_T[i]);    
    }

    printf("chromosome_T.size(): %d\n", chromosome_T.size());
    printf("chromosome_T[0].size(): %d\n", chromosome_T[0].size());

    for (int i = 0; i < chromosome_T.size(); ++i)
    {
        for (int j = 1; j < chromosome_T[i].size(); ++j)
        {
            printf("is %d in the vector:\n", j);
            printf_vector(chromosome_T[i]);
            if(not (find(chromosome_T[i].begin(), chromosome_T[i].end(), j) != chromosome_T[i].end()) )
                return false;
        }
    }

    printf("por fin alguna wea buena xd\n");
    return true;

}


int random_num(int start, int end) {

    int range = (end - start) + 1;
    int random_int = start + (rand()%range);
    return random_int;
}

int main(){
    srand((unsigned)(time(0)));

    int menor45 = 0;
    int menor90 = 0;
    int mayor = 0;

    for (int i = 0; i < 1000; ++i)
    {
        float p = random_num(0, 100);
        cout << p << endl;;
        if (p<45) menor45++;
        if (45<=p and p<90) menor90++;
        if (90<=p and p<100) mayor++;
        //sum += p*100;
        //cout << "random_num(0,50) " << random_num(0, 50) << endl;
    }
    printf("menor45: %d\n", menor45);
    printf("menor90: %d\n", menor90);
    printf("mayor: %d\n", mayor);



    return 0;





    vector<vector<int>> chromosome = {{1, 5}, {2, 4}, {3, 3}, {4, 2}, {5, 1}} ;
    printf("Home venue constraint?: %s\n", (home_venue_constraint(chromosome) ? "true" : "false"));

    return 0;







    srand ( unsigned (time(0)));
    vector<vector<int>> ve;
    for (int i = 0; i < 10; ++i)
    {
        vector<int> v2;
        for (int j = 0; j < 3; ++j)
        {
            v2.push_back(j);
        }
        ve.push_back(v2);

    }


    for (int i = 0; i < ve.size(); ++i)
    {
        random_shuffle(ve[i].begin(), ve[i].end());
    }


    for (int i = 0; i < ve.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%d ", ve[i][j]);
        }
        printf("\n");
    }





    return 0;

    int nTeams = 11;
    int nUmpires = static_cast<int>(ceil(nTeams/2));

    printf ( "%d\n", nUmpires );

	vector<int> v = {3, 5, 2, 1, 5, 2, 5, 0, 4};
	int q1 = 2;

	for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 1; j <= q1 and i+j<v.size(); ++j)
        {
        	// printf("i: %d j: %d v[i=%d]: >%d<  && v[i+j=%d]: >%d<\n", i, j, i, v[i], i+j, v[i+j]);
            printf("%d vs %d\n", v[i], v[i+j]);
            if (v[i] == v[i+j]) printf("fuck\n");
        }
        printf("\n");
    }

	return 0;

}