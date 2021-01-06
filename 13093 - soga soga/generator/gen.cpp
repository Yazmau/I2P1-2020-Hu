#include "../testlib.h"
using namespace std;
struct que {
	int type,dir = 0;
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int N,Q;
	vector<int> arr;
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
			if(now.type == 1)	scanf("%d",&now.dir);
			ques.push_back(now);
		}

		fclose(stdin);
	}
	else {
		/* set N and Q */
		N = (subtask == 2 ? 1000 : (testNumber == 10 ? 200000 : 500000));
		Q = (subtask == 2 ? 1000 : 500000);

		/* set range of a */
		int MINV = 0, MAXV = 1000000000;
		
		/* set a */
		set<int> aSet;
		for(int i=1;i<=N;i++) {
			int val = rnd.next(MINV, MAXV);
			if(i == 1 && testNumber % 2 == 0)	val = 0;	// hey hey
			while(subtask == 2 && aSet.count(val) == 1)	val = rnd.next(MINV, MAXV);
			arr.push_back(val);	
			aSet.insert(val);
		}

		/* set flag */
		int flag = (testNumber == 10 ? -1 : (testNumber - 2) % 4);

		/* set query */
		{
			/* remove some elements first */
			int op3Num = (testNumber == 10 ? N / 2 : N / 10);
			for(int i=0;i<op3Num;i++)	ques.push_back(que{3,-1});
			inf.ensuref((int)ques.size() < Q, "remove too many elements");

			/* move to mid - 1 and output sometimes */
			int num = N - op3Num;
			int pos = 1, mid = (num - + 1) / 2;
			while(pos + 1 < mid) {
				ques.push_back(que{1,1});
				pos++;
				if(pos % (int)sqrt(num) == 0)	ques.push_back(que{2,-1});
			}
			inf.ensuref((int)ques.size() < Q, "move/output too many times");
			
			/* random */
			int numLimit = 1 + (flag >= 0 ? 1 : 0);
			while((int)ques.size() + 1 < Q && num > 1) {
				que now;
				int j = 0;
				for(;j < 30;j++) {
					int type = (num == numLimit ? rnd.next(1,2) : rnd.next(1,3));
					if(type == 1) {
						int dir = 1 + -2 * rnd.next(0,1);
						if(pos + dir < 1 || pos + dir > num || (flag == 0 && pos + dir >= mid))
							dir = 0 - dir;
						inf.ensuref(pos + dir >= 1 && pos + dir <= num && (flag != 0 || pos + dir < mid), "op1 is invalid");
					
						now.dir = dir;
						pos += dir;
					}
					else if(type == 3) {
						if(0 <= flag && flag <= 2) {
							if(pos >= mid + (flag == 2 ? 1 : 0))
								continue;
						}
						
						if(pos > mid)	pos--;
						num--;
						mid = (num + 1) / 2;
					}
					now.type = type;
					break;
				}
				inf.ensuref(j < 30, "some error happend when random generate queries");
			
				ques.push_back(now);
			}
			inf.ensuref(testNumber != 10 || num == 1, "test case is not good enought = =");
			while((int)ques.size() < Q)
				ques.push_back(que{2,-1});
		}
	}
	
	cout << N << '\n';
	for(int i=0;i<(int)arr.size();i++)
		cout << arr[i] << " \n"[i == (int)arr.size() - 1];
	cout << Q << '\n';
	for(que now : ques) {
		cout << now.type;
		if(now.type == 1)	cout << " " << now.dir;
		cout << '\n';
	}
	return 0;
}
