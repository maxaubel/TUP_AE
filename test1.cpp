#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	vector<int> v = {0, 0, 2, 3, 4, 1, 2, 3};
	int q1 = 2;

	for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 1; j <= q1 and i+j<v.size(); ++j)
        {
        	printf("i: %d j: %d v[i=%d]: >%d<  && v[i+j=%d]: >%d<\n", i, j, i, v[i], i+j, v[i+j]);
            if (v[i] == v[i+j]) printf("fuck\n");
        }
    }

	return 0;

}