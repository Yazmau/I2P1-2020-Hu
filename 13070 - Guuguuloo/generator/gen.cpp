#include "../testlib.h"
using namespace std;
struct op {
	int type,val;
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int N,Q;
	vector<int> arr;
	vector<op> ops;

	if(testNumber == 1) {
		N = 6;
		arr = {1,5,2,7,9,10};
		Q = 5;
		ops = {op{2,1},op{1,2},op{2,2},op{1,9},op{2,10}};
	}
	else {
		N = (subtask == 1 ? rnd.next(500,1000) : 100000);
		Q = (subtask == 1 ? rnd.next(500,1000) : 100000);

		set<int> arrSet;
		while((int)arrSet.size() < N)	arrSet.insert(rnd.next(1,(testNumber <= 4 ? 1000 : 1000000000)));
		for(int val : arrSet)	arr.push_back(val);

		int d = 1, u = (testNumber <= 3 ? 1000 : 1000000000);

		int num = rnd.next(1,Q);
		vector<int> opX;
		if(testNumber != 2 && testNumber != 7 && testNumber != 9)
			opX = {arr.front(),arr.back()};
		if(testNumber == 2 || testNumber == 5 || testNumber == 6 || testNumber == 8) {
			set<int> temp;
			for(int val : opX)	temp.insert(val);
			opX.clear();

			while((int)temp.size() < num) {
				int j = 0, val = (rnd.next(0,1) == 0 ? arr[rnd.next(1,N-2)] : rnd.next(d,u));
				for(;j < 10 && temp.count(val) == 1;j++)
					if(rnd.next(0,1) == 0)
						val = arr[rnd.next(1,N-2)];
					else
						val = rnd.next(d,u);
				if(j == 10)	break;
				temp.insert(val);
			}
			for(int val : temp)	opX.push_back(val);
			num = (int)opX.size();
		}
		else {
			while((int)opX.size() < num) {
				if(rnd.next(0,1) == 0)
					opX.push_back(arr[rnd.next(1,N-2)]);
				else
					opX.push_back(rnd.next(d,u));
				while((int)opX.size() < num && rnd.next(0,99) == 0)
					opX.push_back(opX.back());
			}
			sort(opX.begin(),opX.end());
		}

		num = Q - num;
		vector<int> opY;
		if(testNumber == 2 || testNumber == 5 || testNumber == 6 || testNumber == 8) {
			set<int> temp;
			while((int)temp.size() < num) {
				int j = 0, val = (rnd.next(0,1) == 0 ? arr[rnd.next(1,N-2)] : rnd.next(d,u));
				for(;j < 10 && temp.count(val) == 1;j++)
					if(rnd.next(0,1) == 0)
						val = arr[rnd.next(0,N - 1)];
					else
						val = rnd.next(d,u);
				if(j == 10)	break;
				temp.insert(val);
			}
			for(int val : temp)	opY.push_back(val);
			num = (int)opY.size();
		}
		else {
			while((int)opY.size() < num) {
				if(rnd.next(0,1) == 0)
					opY.push_back(arr[rnd.next(0,N-1)]);
				else
					opY.push_back(rnd.next(d,u));
				while((int)opY.size() < num && rnd.next(0,99) == 0)
					opY.push_back(opY.back());
			}
			sort(opY.begin(),opY.end());
		}

		if(testNumber == 2 || testNumber == 5) {
			int p1 = 0, sz1 = (int)opX.size(), p2 = 0, sz2 = (int)opY.size();
			while(p1 < sz1 || p2 < sz2) {
				if(p1 < sz1 && (p2 == sz2 || opX[p1] < opY[p2]))
					ops.push_back(op{1,opX[p1]}), p1++;
				else
					ops.push_back(op{2,opY[p2]}), p2++;
			}
		}
		else {
			while(!opX.empty() || !opY.empty()) {
				if(!opX.empty() && (opY.empty() || rnd.next(0,1) == 0))
					ops.push_back(op{1,opX.back()}), opX.pop_back();
				else
					ops.push_back(op{2,opY.back()}), opY.pop_back();
			}
			reverse(ops.begin(),ops.end());
		}
		Q = (int)ops.size();

		shuffle(arr.begin(),arr.end());
	}
	
	cout << N << '\n';
	for(int i=0;i<(int)arr.size();i++) {
		if(i != 0)	cout << " ";
		cout << arr[i];
	}
	cout << '\n';
	cout << Q << '\n';
	for(op now : ops)
		cout << now.type << " " << now.val << '\n';
	return 0;
}
