#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;



void work() {
	int n, m;
	cin >> n >> m;

	vector<string> a(n + 1, string(m + 1, 0));
	for(int i = 1; i <= n; i++) {
		string t;
		cin >> t;
		for(int j = 1; j <= m; j++) {
			a[i][j] = t[j - 1];
		}
	}

	int mod = 1e9 + 7;
	vector<int> b{31, 37};
	vector<vector<int>> bp(2, vector<int>(n + m + 1));
	vector<vector<int>> h(n + 1, vector<int>(m + 1));
	vector<vector<int>> g(n + 2, vector<int>(m + 2));

	bp[0][0] = bp[1][0] = 1;
	for(int i = 1; i <= n + m; i++) bp[0][i] = bp[0][i - 1] * b[0] % mod;
	for(int i = 1; i <= n + m; i++) bp[1][i] = bp[1][i - 1] * b[1] % mod;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			h[i][j] = (h[i][j - 1] * b[0] + a[i][j]) % mod;
	
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= m; j++)
			h[i][j] = (h[i - 1][j] * b[1] + h[i][j]) % mod;
	
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--)
			g[i][j] = (g[i][j + 1] * b[0] + a[i][j]) % mod;

	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--)
			g[i][j] = (g[i + 1][j] * b[1] + g[i][j]) % mod;
	
	auto check = [&](int x, int y, int x1, int y1, int r) {
		int v1 = h[x1][y1]
			- h[x1-r][y1] * bp[1][r]
			- h[x1][y1-r] * bp[0][r]
			+ h[x1-r][y1-r] * bp[1][r] % mod * bp[0][r];
		int v2 = g[x][y]
			- g[x+r][y] * bp[1][r]
			- g[x][y+r] * bp[0][r]
			+ g[x+r][y+r] * bp[1][r] % mod * bp[0][r];
		
		v1 = (v1 % mod + mod) % mod;
		v2 = (v2 % mod + mod) % mod;
		
		// cout << " - " <<  v1 << ", " << v2 << endl;

		return v1 == v2;
	};

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int L = 1, R = min(min(i, n-i+1), min(j, m-j+1)) + 1;
			while(R - L >= 2) {
				int mid = L + R >> 1;
				// cout << i << ", " << j << ": " << L << ", " << R << " - " << mid << endl;
				if(check(i-mid+1, j-mid+1, i+mid-1, j+mid-1, 2*mid-1)) L = mid;
				else R = mid;
			}
			ans += L;
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int L = 0, R = min(min(i, n-i), min(j, m-j)) + 1;
			while(R - L >= 2) {
				int mid = L + R >> 1;
				if(check(i-mid+1, j-mid+1, i+mid, j+mid, 2*mid)) L = mid;
				else R = mid;
			}
			ans += L;
		}
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
