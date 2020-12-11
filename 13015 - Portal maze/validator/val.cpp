/*
1 <= T <= 10
2 <= n,m <= 300
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int T = inf.readInt(1, 10, "T");
	inf.readEoln();

	for(int t=0;t<T;t++) {
		int n = inf.readInt(2, 300, "n");
		inf.readSpace();
		int m = inf.readInt(2, 300, "m");
		inf.readEoln();
	
		bool stExist = false, edExist = false;
		set<char> lowerSet,upperSet;
		
		for(int i=0;i<n;i++) {
			string row = inf.readWord();
			inf.readEoln();

			inf.ensuref((int)row.size() == m, "The lenght of each row must be m");
			for(char c : row) {
				if(c == '$') {
					inf.ensuref(!stExist, "There must be at most one st");
					stExist = true;
				}
				else if(c == '&') {
					inf.ensuref(!edExist, "There must be at most one ed");
					edExist = true;
				}
				else if(isalpha(c)) {
					if(islower(c)) {
						inf.ensuref(lowerSet.count(c) == 0, "There must be at most one in-gate");
						lowerSet.insert(c);
					}
					else {
						inf.ensuref(upperSet.count(c) == 0, "There must be at most one out-gate");
						upperSet.insert(c);
					}
				}
				else {
					inf.ensuref(c == '#' || c == '.', "There is some invalid character");
				}
			}
		}

		inf.ensuref(stExist, "There must be exactly one st");
		inf.ensuref(edExist, "There must be exactly one ed");
		for(char c : lowerSet)
			inf.ensuref(upperSet.count(toupper(c)) == 1, "There must be exactly one out-gate for each in-gate");
		for(char c : upperSet)
			inf.ensuref(lowerSet.count(tolower(c)) == 1, "There must be exactly one in-gate for each out-gate");
	}

	inf.readEof();
	return 0;
}
