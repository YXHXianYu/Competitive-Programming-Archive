#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;

/**
 * 1. 线段树暴力维护线性基 O(nlogn*w^2)（能合并就能维护，合并时将一个节点的线性基插入另一个节点）
 * 2. 分治求出nlogn*w个区间的线性基，然后查询时合并两个线性基 O(nwlogn + qw^2)
 * 3. 
*/

void work() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	while(q--) {
		int u, v;
		cin >> u >> v;

		
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while(t--) {
		work();
	}
	
	return 0;
}
