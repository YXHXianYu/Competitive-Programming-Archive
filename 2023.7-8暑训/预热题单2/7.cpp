#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n, K;
	cin >> n >> K;

	int lim = (1 << n);

	vector<int> cnt(lim);
	for(int i = 0; i < lim; i++) {
		int x = i;
		while(x) {
			cnt[i] += x & 1;
			x >>= 1;
		}
	}

	// for(int i = 0; i < lim; i++) {
	// 	cout << i << ": " << cnt[i] << endl;
	// }

	vector<vector<vector<int>>> f(2, vector<vector<int>>(lim, vector<int>(K + 1)));

	int S = 0;
	for(int j = 0; j < lim; j++) {
		if(j & (j << 1)) continue;
		if(cnt[j] > K) continue;
		f[S][j][cnt[j]] = 1;
		// cout << j << " += " << cnt[j] << endl;
	}

	for(int i = 2; i <= n; i++) {
		// cout << i << ": " << endl;
		int T = S ^ 1;
		for(int j = 0; j < lim; j++) {
			if(j & (j << 1)) continue;
			for(int k = 0; k <= K; k++) {
				f[T][j][k] = 0;
			}
		}
		for(int j = 0; j < lim; j++) {
			if(j & (j << 1)) continue;
			for(int k = 0; k <= K; k++) {
				if(f[S][j][k] == 0) continue;
				for(int p = 0; p < lim; p++) {
					if(
						(j & p) || ((j >> 1) & p) || ((j << 1) & p)
						|| (p & (p << 1)) || (k + cnt[p] > K)
					) {
						continue;
					}
					f[T][p][k + cnt[p]] += f[S][j][k];
					// cout << "f[" << T << "][" << p << "][" << k+cnt[p] << "] += " << ", " << j << ", " << k << ", " << cnt[j] << ": " << f[S][j][k] << endl; 
				}
			}
		}
		S = T;
	}

	int ans = 0;
	for(int j = 0; j < lim; j++) {
		ans += f[S][j][K];
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
