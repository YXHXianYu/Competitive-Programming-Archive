#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n, m, levelLim, coef;
	cin >> n >> m >> levelLim >> coef;

	levelLim = min(levelLim, 7LL);

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	vector<int> V(m + 1);
	for(int i = 1; i <= m; i++) cin >> V[i];

	const int INF = 1LL << 60;

	vector<vector<vector<vector<int>>>> f(
		n + 1, vector<vector<vector<int>>>(
			n + 1, vector<vector<int>>(
				levelLim + 1, vector<int>(m + 1, -INF)
			)
		)
	);

	auto Pow = [](int a, int n) {
		int ans = 1;
		while(n) {
			if(n & 1) ans = ans * a;
			a = a * a;
			n >>= 1;
		}
		return ans;
	};

	vector<int> pPow(levelLim + 1);
	pPow[0] = 1;
	for(int i = 1; i <= levelLim; i++) {
		pPow[i] = pPow[i - 1] * coef;
	}

	for(int i = 1; i <= n; i++) {
		f[i][i][0][0] = V[a[i]];
		f[i][i][1][a[i]] = 0;
	}

	for(int len = 2; len <= n; len++) {
		for(int L = 1, lim = n - len + 1; L <= lim; L++) {
			int R = L + len - 1;
			for(int u = 1; u <= levelLim; u++) {
				for(int v = 1; v <= m; v++) {
					for(int j = L; j < R; j++) {
						if(f[L][j][u-1][v] >= 0 && f[j+1][R][u-1][v] >= 0)
							f[L][R][u][v] = max(f[L][R][u][v], f[L][j][u-1][v] + f[j+1][R][u-1][v]);
						if(f[L][j][u][v] >= 0 && f[j+1][R][0][0] >= 0)
							f[L][R][u][v] = max(f[L][R][u][v], f[L][j][u][v] + f[j+1][R][0][0]);
						if(f[L][j][0][0] >= 0 && f[j+1][R][u][v] >= 0)
							f[L][R][u][v] = max(f[L][R][u][v], f[L][j][0][0] + f[j+1][R][u][v]);
					}
					if(f[L][R][u][v] >= 0)
						f[L][R][0][0] = max(f[L][R][0][0], f[L][R][u][v] + pPow[u-1] * V[v]);
					// if(L==6&&R==7&&u==2&&v==3) {
					// 	cout << " - " << f[L][R][u][v] << ", " << f[L][R][0][0] << endl;
					// }
				}
			}
		}
	}

	// for(int L = 1; L <= n; L++) {
	// 	for(int R = 1; R <= n; R++) {
	// 		cout << f[L][R][0][0] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << f[1][n][0][0] << endl;
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
