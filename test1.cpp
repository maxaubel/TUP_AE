#include <bits/stdc++.h>
#include <iostream>
#include <regex>
#include <vector>

//#include <string>
//#include <string.h>
//#include <algorithm>
using namespace std;

vector<vector <int>> A;

void foo() {
	cout << A[0][0];
}
int main(){
	std::vector<int> a;
	a.push_back(10);
	A.push_back(a);
	foo();
}