#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int testnum = atoi(argv[1]);
	
	int bound = 1e8;

	int n[] = {4,4,1,2,3,5,8,9,10,10};
	int l[] = {0,0,0,0,0,0,0,5 * bound,-bound,-10 * bound};
	int r[] = {bound,bound,bound,bound,bound,bound,bound,10 * bound,-1,-5 * bound};

	cout << n[testnum - 1] << '\n';
	for(int i=1;i<=n[testnum - 1];i++) {
		for(int j=1;j<=n[testnum - 1];j++) {
			if(j != 1)	cout << " ";
			cout << rnd.next(l[testnum - 1],r[testnum - 1]);
		}
		cout << '\n';
	}
	return 0;
}
