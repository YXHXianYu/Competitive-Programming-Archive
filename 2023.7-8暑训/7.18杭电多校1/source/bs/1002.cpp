#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1010;
const int inf = 1ll << 60;
int n;
int a[N];
int dp[N][2][2];
vector<int> e[N];


void dfs(int x, int fa) {
	dp[x][0][0] = 0;
	dp[x][0][1] = 0;
	dp[x][1][0] = a[x];
	dp[x][1][1] = a[x];
	int qwq = inf;
	int flag = 0;
	for(auto v: e[x]) {
		if(v == fa) continue;
		
		dfs(v, x);
		
		dp[x][0][1] += min(dp[v][0][0],dp[v][1][0]);
		dp[x][0][0] += min(dp[v][1][0], dp[v][0][0]);
		dp[x][1][0] += min(dp[v][0][1], dp[v][1][1]);
		dp[x][1][1] += min(dp[v][0][1], dp[v][1][1]);
		if(dp[v][1][0] <= dp[v][0][0]) {
			flag = 1;
		}
		
	}

	if(flag == 0) {
		for(auto v: e[x]) {
			if(v == fa) continue;
			qwq = min(qwq, dp[v][1][0] - dp[v][0][0]);
		}
		dp[x][0][0] += qwq;
	}
}

void work() {
	
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i];
		e[i].clear();
	}
	for(int i = 1, u, v; i < n; ++i) {
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = inf;
	dfs(1, 0);
	
	ans = min(dp[1][1][0],dp[1][1][1]);
	ans = min(ans, dp[1][0][0]);
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	cin >> t;
	while(t--) {
		work();
	}
	
	return 0;
} 