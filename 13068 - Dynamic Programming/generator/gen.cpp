#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int N = 100000;
	vector<int> arr;
	for(int i=0;i<N;i++)	arr.push_back(rnd.next(1,100000));
	if(testNumber <= 3)	for(int i=1;i<N;i++)	arr[i] = arr[0];
	if(testNumber <= 6)	sort(arr.begin(),arr.end());

	cout << N << '\n';
	for(int i=0;i<N;i++) {
		if(i != 0)	cout << " " ;
		cout << arr[i];
	}
	cout << '\n';
	return 0;
}
