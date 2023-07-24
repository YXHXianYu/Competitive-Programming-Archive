#include<bits/stdc++.h>
using namespace std;
#define int long long


void work() {
	
	auto solve = [](int k, int n) {
		vector<int> sg(n + 1);
		sg[0] = 0;
		for(int i = 1; i <= k; i++) {
			sg[i] = 1;
		}
		for(int i = k + 1; i <= n; i++) {
			set<int> s;
			int lim = i - k;
			for(int j = 2; j <= lim; j++) {
				s.insert(sg[j-1] ^ sg[i-(j+k-1)]);
			}
			while(s.count(sg[i])) sg[i]++;
		}
		
		for(int i = 1; i <= n; i++) {
			cout << i << ": " << sg[i] << endl;
		}
//		for(int i = k + 1; i <= n; i++) {
//			printf("%3lld", sg[i]);
//		}
	};
	
	for(int k = 2; k <= 5; k++) {
		cout << k << ": " << endl;
		solve(k, 50);
		cout << endl << endl;
	}
	
}

/*
k = 2:
k+2 -> (10) 0 1 1 2 2 1 2 2 1 1

k = 3:
k+2 -> (14) 0 1 1 1 2 2 2 1 2 2 2 1 1 1

k = 4:
k+2 -> (18) 0 1 1 1 1 2 2 2 2 1 2 2 2 2 1 1 1 1

k = 5:
k+2 -> (22) 0 5*1 5*2 1 5*2 5*1

*/

signed main() {
	
	int T = 1;
//	cin >> T;
	while(T--) {
		work();
	}
	
	return 0;
}
