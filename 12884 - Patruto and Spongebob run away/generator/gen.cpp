#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int test_number = atoi(argv[1]);

	if(test_number <= 4)
		cout << test_number << endl;
	else {
		int n[] = {10,50,120,150,200,250};
		cout << n[test_number - 5] << endl;
	}
	return 0;
}
