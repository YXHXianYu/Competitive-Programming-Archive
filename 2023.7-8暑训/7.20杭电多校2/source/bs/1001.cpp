#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
k = 2:
k+1 -> (10) 0 1 1 2 2 1 2 2 1 1

k = 3:
k+1 -> (14) 0 1 1 1 2 2 2 1 2 2 2 1 1 1

k = 4:
k+1 -> (18) 0 1 1 1 1 2 2 2 2 1 2 2 2 2 1 1 1 1

k = 5:
k+1 -> (22) 0 5*1 5*2 1 5*2 5*1

*/

void work() {
	int k, n;
	cin >> k >> n;
	
	if(n == 0) {
		cout << "Bob" << endl;
		return;
	}
	if(n <= k) {
		cout << "Alice" << endl;
		return;
	}
	
	int len = 2 + k * 4;
	n = (n - k - 1) % len;
	if(n == 0) {
		cout << "Bob" << endl;
	} else {
		cout << "Alice" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	cin >> T;
	while(T--) {
		work();
	}
	
	return 0;
}
