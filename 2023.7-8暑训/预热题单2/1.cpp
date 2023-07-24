#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	map<int, int> f;
	vector<int> b = a;
	sort(b.begin() + 1, b.begin() + n + 1);
	int m = unique(b.begin() + 1, b.begin() + n + 1) - b.begin() - 1;
	for(int i = 1; i <= m; i++) {
		f[b[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		a[i] = f[a[i]];
	}
	// for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

	vector<int> bit(n + 10);
	auto lowbit = [&](int x) {
		return x&-x;
	};
	auto add = [&](int x, int v) {
		for(; x <= n; x += lowbit(x)) {
			bit[x] += v;
		}
	};
	auto query = [&](int x) {
		int ans = 0; for(; x; x -= lowbit(x)) ans += bit[x]; return ans;
	};

	int ans = 0;
	for(int i = n; i >= 1; i--) {
		ans += query(a[i] - 1);
		add(a[i], 1);
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
