#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n, c;
	cin >> n >> c;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	map<int, int> f;
	for(int i = 1; i <= n; i++) {
		f[a[i]] += 1;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int x = a[i];
		int y = a[i] - c;
		// cout << i << ": " << x << ", " << y << endl;
		if(f.count(y) == 0) continue;
		ans += f[y];
	}

	cout << ans << endl;
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
