#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int N,Q;
	vector<int> arr,ques;

	if(testNumber == 1) {
		N = 7;
		arr = {-2,5,2,5,7,9,10};
		Q = 5;
		ques = {11,10,8,1,-1};
	}
	else {
		/* set N and Q */
		int n[] = {-1,1000,1000,1000,1000,10000,50000,100000,100000,100000};
		int q[] = {-1,1000,1000,1000,1000,100000,100000,100000,100000,100000};
		N = n[testNumber - 1], Q = q[testNumber - 1];

		/* set range of A and x */
		int MINV = -2000000000, MAXV = 2000000000;
		if(testNumber != 9 && testNumber != 10)
			MINV = 0;
		
		/* set flag */
		bool arrSameEnable = (testNumber > 3), xSameEnable = (testNumber != 2 && testNumber != 4);
		
		/* set A */
		for(int i=0;i<N;i++) {
			int val = rnd.next(MINV,MAXV);
			int p = rnd.next(0,9);
			if(i > 0 && p == 0)
				val = arr[rnd.next(0,i - 1)];
			else if(i > 0 && p == 1)
				val = arr[rnd.next(0,i - 1)] + 1;
			arr.push_back(val);
		}
		set<int> arrSet;
		for(int val : arr)	arrSet.insert(val);
		
		/* adjust A according to flag */
		if(!arrSameEnable) {
			arr.clear();
			while((int)arrSet.size() < N) {
				int val = rnd.next(MINV,MAXV);
				arrSet.insert(val);
			}
			for(int val : arrSet)	arr.push_back(val);
		}

		/* shuffle A */
		sort(arr.begin(),arr.end());
		if(testNumber >= 9 || testNumber % 3 == 0)
			shuffle(arr.begin(), arr.end());
		else if(testNumber % 3 == 1)
			shuffle(arr.begin(), arr.begin() + N / 2);
		else if(testNumber % 3 == 2)
			shuffle(arr.begin() + N / 2, arr.end());
	
		/* set x */
		for(int i=0;i<Q;i++) {
			int x = rnd.next(MINV,MAXV);
			int p = rnd.next(0,19);
			if(p <= 2) {
				x = arr[rnd.next(0,N - 1)];
				if(p == 0 && x != MINV)	x--;
				else if(p == 1 && x != MAXV)	x++;
			}
			else if(i > 0 && p == 3)
				x = ques[rnd.next(0,i - 1)];
			ques.push_back(x);
		}

		/* adjust x according to flag */
		if(!xSameEnable) {
			set<int> xSet;
			for(int i=0;i<Q;i++) {
				while(xSet.count(ques[i]) == 1 || arrSet.count(ques[i]) == 1)
					ques[i] = rnd.next(MINV,MAXV);
				xSet.insert(ques[i]);
			}
		}

		sort(ques.begin(),ques.end(),greater<int>());
	}
	
	cout << N << '\n';
	for(int i=0;i<(int)arr.size();i++)
		cout << arr[i] << " \n"[i == (int)arr.size() - 1];
	cout << Q << '\n';
	for(int x : ques)
		cout << x << '\n';
	return 0;
}
