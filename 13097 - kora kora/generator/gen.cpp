#include "../testlib.h"
using namespace std;
struct que {
	int type,k = -1;
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int N,Q;
	vector<long long> arr;
	vector<que> ques;

	if(subtask == 1) {	// Sample
		freopen("Sample.in", "r", stdin);

		scanf("%d",&N);
		for(int i=0,val;i<N;i++) {
			scanf("%d",&val);
			arr.push_back(val);
		}
		scanf("%d",&Q);
		for(int i=0;i<Q;i++) {
			que now;
			scanf("%d",&now.type);
			if(now.type == 2)	scanf("%d",&now.k);
			ques.push_back(now);
		}

		fclose(stdin);
	}
	else {
		/* set N and Q */
		int n[] = {100,3000,100000,100000-60+1,50000,50000};
		N = n[testNumber - 2];
		Q = (testNumber == 2 ? 100 : (testNumber == 3 ? 3000 : 100000));

		/* set range of a */
		long long MINV = 0, MAXV = (long long)1e18;
		if(testNumber <= 4)	MAXV = 1e9;
		else if(testNumber == 6)	MAXV = 60;
		
		/* set a */
		for(int i=1;i<=N;i++)	arr.push_back(rnd.next(MINV,MAXV));
		if(testNumber == 2)	sort(arr.begin(),arr.end());
	
		/* set the number of op2 */
		int op2Num = (testNumber <= 5 ? 60 : N + 1);
		
		/* generatae queries */
		for(int i=0;i<op2Num;i++)	ques.push_back(que{2,-1});
		for(int i=(int)ques.size();i<Q;i++)	ques.push_back(que{1,-1});
		shuffle(ques.begin(),ques.end());

		int num = N;
		for(int i=0;i<Q;i++) {
			if(ques[i].type == 1)
				num--;
			else
				ques[i].k = rnd.next(1,num);
		}

		/* ensure edge case for testcase 5, 6 and 7 */
		inf.ensuref(testNumber < 5 || num == 1, "testcase is not good enough = =");
	}
	
	cout << N << '\n';
	for(int i=0;i<(int)arr.size();i++)
		cout << arr[i] << " \n"[i == (int)arr.size() - 1];
	cout << Q << '\n';
	for(que now : ques) {
		cout << now.type;
		if(now.type == 2)	cout << " " << now.k;
		cout << '\n';
	}
	return 0;
}
