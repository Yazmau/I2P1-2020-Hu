#include "../testlib.h"
using namespace std;
string gen(int xPos,int val) {
	string ret = "";
	for(int i=0;i<10;i++) {
		if(i == xPos)
			ret += "x";
		else {
			ret += (char)('0' + (val & 1));
			val >>= 1;
		}
	}
	return ret;
}
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int _n[] = {6,10,30,100,1000,5000,10000,50000,100000,100000};
	int n = _n[testNumber - 1];
	
	vector<string> strs;
	
	const int digitNum = 10;
	const int maxVal = (1 << (digitNum - 1));
	vector<string> strPool;
	for(int xPos=0;xPos<10;xPos++)
		for(int val=0;val<=maxVal;val++)
			strPool.push_back(gen(xPos,val));
	shuffle(strPool.begin(),strPool.end());
	
	int strPoolSize = min(n, rnd.next((int)strPool.size() / 2, (int)strPool.size()));
	strPool.erase(strPool.begin() + strPoolSize, strPool.end());
	int uniStrNum = max(1, strPoolSize / 10);

	for(int i=0;i<uniStrNum;i++)
		strs.push_back(strPool[i]);
	for(int i=uniStrNum;i<n;i++)
		strs.push_back(strPool[rnd.next(uniStrNum, strPoolSize - 1)]);
	shuffle(strs.begin(),strs.end());

	cout << n << '\n';
	for(string s : strs)
		cout << s << '\n';
	return 0;
}
