#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm = 1e5 + 10;

int b[2];
int MOD[2];
int bp[2][maxm * 2];
int bpi[2][maxm * 2];

int Pow(int a, int n, int MOD) {
	int ans = 1;
	while(n) {
		if(n & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	return ans;
};

int f[2][maxm];
int h[maxm];

void work() {
	int n, m;
	cin >> n >> m;
	
	vector<string> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for(int t = 0; t <= 1; t++) {
		for(int i = 1; i <= n; i++) {
			h[0] = a[i][0];
			for(int j = 1; j < m; j++) {
				h[j] = h[j - 1] + a[i][j] * bp[t][j] % MOD[t];
				h[j] %= MOD[t];
			}
			int cnt = h[m - 1];
			h[m] = h[m - 1];
			for(int j = 0; j < m; j++) {
				h[m] = h[m] + a[i][j] * bp[t][j + m] % MOD[t] - a[i][j] * bp[t][j] % MOD[t] + MOD[t];
				h[m] %= MOD[t];
				cnt = min(cnt, h[m] * bpi[t][j + 1] % MOD[t]);
			}
			f[t][i] = cnt;
		}
	}
	
	int Q;
	cin >> Q;
	for(int i = 1; i <= Q; i++) {
		int u, v;
		cin >> u >> v;
		
		if(f[0][u] == f[0][v] && f[1][u] == f[1][v]) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	b[0] = 171;
	b[1] = 17771;
	MOD[0] = 1e9 + 7;
	MOD[1] = 998244353;
	
	int M = 2e5;
	for(int i = 0; i <= 1; i++) {
		bp[i][0] = 1;
		for(int j = 1; j <= M; j++) {
			bp[i][j] = bp[i][j - 1] * b[i] % MOD[i];
			bpi[i][j] = Pow(bp[i][j], MOD[i] - 2, MOD[i]);
		}
	}
	
	int t = 1;
	 cin >> t;
	while(t--) {
		work();
	}
	
	return 0;
} 