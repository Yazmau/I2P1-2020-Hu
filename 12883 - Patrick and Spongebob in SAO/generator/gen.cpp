#include "../testlib.h"
#include <numeric>
using namespace std;
struct que {
	int l,r;
};
class genArr {
	public:
		static vector<int> randomForm(int n) {
			vector<int> ret;
			for(int i=0;i<n;i++)	ret.push_back(rnd.next(1,500));
			return ret;
		}
		static vector<int> stairForm(int n) {	// arithmetic sequence
			vector<int> temp(500);
			iota(temp.begin(),temp.end(),1);
			shuffle(temp.begin(),temp.end());

			vector<int> ret;
			for(int i=0;(int)ret.size() < n;i++)
				for(int j=0;j<=i && (int)ret.size() < n;j++)
					ret.push_back(temp[i]);
			shuffle(ret.begin(),ret.end());
			return ret;
		}
		static vector<int> binomialForm(int n) {
			vector<int> temp(500);
			iota(temp.begin(),temp.end(),1);
			shuffle(temp.begin(),temp.end());

			vector<int> ret;
			for(int i=0,j=1;(int)ret.size() < n;i++,j<<=1)
				for(int k=0;k<j && (int)ret.size() < n;k++)
					ret.push_back(temp[i]);
			shuffle(ret.begin(),ret.end());
			return ret;
		}
};
vector<que> miracleGen(int n,vector<int> arr) {
	int times_cnt[505], val_cnt[505];

	que candidates[505] = {};
	for(int i=0;i<n;i++) {
		memset(times_cnt, 0, sizeof times_cnt);
		memset(val_cnt, 0, sizeof val_cnt);

		int max_times = 0;
		for(int j=i;j<n;j++) {
			int val = arr[j];
			times_cnt[val_cnt[val]]--;
			val_cnt[val]++;
			times_cnt[val_cnt[val]]++;
			
			max_times = max(max_times, val_cnt[val]);
			if(times_cnt[max_times] == 1)	candidates[max_times] = que{i + 1, j + 1};
		}
	}
	vector<que> ret;
	for(que now : candidates)
		if(now.l != 0)
			ret.push_back(now);
	return ret;
}
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int task_number = atoi(argv[2]);

	int n = -1;
	vector<int> arr;
	int q = -1;
	vector<que> ques;

	if(subtask == 1 || subtask == 2) {
		n = rnd.next(1,500);
		for(int i=1;i<=n;i++)
			arr.push_back((subtask == 1 ? 1 : rnd.next(1,2)));
		q = rnd.next(1,500);
		for(int i=1;i<=q;i++) {
			int l = rnd.next(1,n);
			int r = rnd.next(1,n);
			if(l > r)	swap(l,r);
			ques.push_back(que{l,r});
		}
	}
	else if(subtask == 3) {
		n = q = 500;
		if(task_number <= 7) {	// there is exactly one kind of mode for every query
			arr = (task_number == 6 ? genArr::stairForm(n) : genArr::binomialForm(n));

			vector<que> temp = miracleGen(n,arr);
			int sz = (int)temp.size();
			for(int i=0;i<q;i++) {
				int idx = rnd.next(0,sz-1);
				ques.push_back(temp[idx]);
			}
		}
		else {
			if(task_number == 8)
				arr = genArr::randomForm(n);
			else if(task_number == 9)
				arr = genArr::stairForm(n);
			else
				arr = genArr::binomialForm(n);

			for(int i=0;i<q;i++) {
				int l = rnd.next(1,n);
				int r = rnd.next(1,n);
				if(l > r)	swap(l,r);
				ques.push_back(que{l,r});
			}
		}
	}
	
	cout << n << '\n';
	for(int i=0;i<n;i++) {
		if(i != 0)	cout << " ";
		cout << arr[i];
	}
	cout << '\n';
	cout << q << '\n';
	for(que now : ques)
		cout << now.l << " " << now.r << '\n';
	return 0;
}
