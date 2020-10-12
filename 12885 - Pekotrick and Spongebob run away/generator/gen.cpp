#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int test_number = atoi(argv[2]);

	if(subtask <= 2)
		cout << subtask << " " << rnd.next(1,15) * 2 << endl;
	else {
		int n[] = {9,40,93,230,499};
		int m[] = {30,50,100,250,500};
		cout << n[test_number - 6] << " " << m[test_number - 6] << endl;
	}
	return 0;
}
