#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	vector<int> v = {0, 1, 2, 3, 4};


	for (int i = 0; i < v.size(); ++i)
	{
		if(std::find(v.begin(), v.end(), i) != v.end()) {
			printf("yes\n");
		} else {
		    printf("no :(\n");
		    break;
		}
		/* code */
	}

	return 0;

}