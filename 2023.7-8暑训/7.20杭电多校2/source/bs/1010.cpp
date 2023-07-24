#include<bits/stdc++.h>
using namespace std;

int a[20002];
int dp[2][2002][2];
int premin[2002][2002];
const int inf = 1e9;
int mod[20002];
void build(int m) {
	for(int i = 1; i <= 20000; i++) {
		mod[i] = (i - 1) % m + 1;
	}
}

int read() {
	int ans = 0; char ch = getchar(); while(ch < '0' || '9' < ch) ch = getchar();
	while('0' <= ch && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar(); return ans;
}

signed main() {
	int t;
	t = read();
	int n, m;
	while(t--) {
		n = read(); m = read();
		build(m);
		for(int i = 1; i <= n; i++) {
			a[i] = read();
		}
		int k = 0, now = 0;
		for(int i = 1; i <= m; i++) {
			for(int j = 0; j <= m; j++) {
				premin[i][j] = inf;
			}
		}
//		for(int i = 1; i < m; i++) {
//			dp[i][i][0] = 0;
//			dp[i][i][1] = a[i];
//		}
//		
		for(int j = 0; j <= m; j++) {
			dp[k][j][0] = dp[k][j][1] = inf;
			dp[k ^ 1][j][0] = dp[k ^ 1][j][1] = inf;
		}
		dp[k ^ 1][1][0] = 0;
		dp[k ^ 1][1][1] = a[1];
		for(int j = 1; j <= m; j++) {
			premin[1][j] = a[1];
		}
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j < m; j++) {
				if(j > i) break;
				dp[k][j][1] = dp[k ^ 1][j - 1][0] + a[i];
				dp[k][j][0] = premin[mod[i - j]][m - j - 1];
			}
			dp[k][1][1] = min(dp[k][1][1], premin[mod[i - 1]][m - 1] + a[i]);
			premin[mod[i]][0] = inf;
			for(int j = 1; j < m; j++) {
				premin[mod[i]][j] = min(premin[mod[i]][j - 1], dp[k][j][1]);
				dp[k ^ 1][j][0] = dp[k ^ 1][j][1] = inf;
//				cout << i<<" "<<j<<" " << dp[i][j][0] << ' '  << dp[i][j][1] << '\n';
			}
			dp[k ^ 1][0][0] = dp[k ^ 1][0][1] = inf;
			dp[k ^ 1][m][0] = dp[k ^ 1][m][1] = inf;
			k ^= 1;
		}
		
		int ans = premin[mod[n]][m - 1];
		for(int j = 1; j < m; j++) {
			ans = min(ans, dp[k ^ 1][j][0]);
		}
		cout << ans << endl;
	}
	return 0;
}
