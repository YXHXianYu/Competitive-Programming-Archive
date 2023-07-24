#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n;
	cin >> n;

	vector<vector<int>> e(n + 1, vector<int>());
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	vector<int> sg(n + 1);
	function<void(int, int)> dfs1 = [&](int x, int fa) {
		sg[x] = 0;
		for(auto y: e[x]) {
			if(y == fa) continue;
			dfs1(y, x);
			sg[x] ^= sg[y] + 1;
		}
	};

	dfs1(1, 0);

	vector<int> fsg(n + 1);
	fsg[1] = sg[1];

	function<void(int, int, int)> dfs2 = [&](int x, int fa, int faSg) {
		if(x != 1) {
			fsg[x] = faSg + 1;
			for(auto y: e[x]) {
				if(y == fa) continue;
				fsg[x] ^= sg[y] + 1;
			}
			// if(x == 6) cout << "(" << fsg[x] << ")" << endl;
		}
		for(auto y: e[x]) {
			if(y == fa) continue;
			dfs2(y, x, fsg[x] ^ (sg[y] + 1));
		}
	};

	dfs2(1, 0, -1);

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(fsg[i] > 0) {
			ans++;
		}
	}

	const int MOD = 1e9 + 7;
	auto Pow = [](int a, int n) {
		int ans = 1;
		while(n) {
			if(n & 1) ans = ans * a % MOD;
			a = a * a % MOD;
			n >>= 1;
		}
		return ans;
	};

	cout << ans * Pow(n, MOD - 2) % MOD << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		work();
	}
	
	return 0;
}
