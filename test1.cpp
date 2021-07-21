#include <iostream>

//#include <string>
//#include <string.h>
//#include <algorithm>
using namespace std;

int main(){

	int random_int = 0;
	for (int i = 0; i < 1000; ++i)
	{
    	random_int += (rand()%2);
    	printf("%d\n", random_int);
	}

}