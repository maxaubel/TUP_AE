#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void tokenize(string s, string del = " ")
{
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        cout << s.substr(start, end - start) << endl;
        start = end + del.size();
        end = s.find(del, start);
    }
    cout << s.substr(start, end - start);
}

int main(){

	//int nTeams, dist, opponents;

    std::string nTeams_arg = "8";
    int nTeams = stoi(nTeams_arg);

    std::ifstream input("instancias/umps" + nTeams_arg + ".txt");
    std::string line; getline( input, line );

    //printf("%d\n", nTeams);


	
    for( std::string line; getline( input, line ); )
	{ 
        tokenize(line, " ");
	}
    return 0;


    return 0;
}




