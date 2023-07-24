#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1020;
const int mod = 1e9 + 7;
int n, m;
bitset<N> e[N];
int sum[N];
int calc(int n) {
	return n*(n-1)/2*(n-2)/3*(n-3)/4%mod;
}

void work() {
	cin>>n>>m;
	for(int i = 1; i <= n; ++i) {
		e[i] = 0;
		sum[i] = 0;
	}
	for(int i = 1, u, v; i <= m; ++i) {
		cin>>u>>v;
		e[u][v] = 1;
		e[v][u] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		sum[i] = e[i].count();
		
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			int count = (e[i]&e[j]).count();
			int sumi = sum[i];
			int sumj = sum[j];
			//cout<<i<<" "<<j<<" "<<count<<endl;
			
			if(e[i][j]) {
				sumi--;
				sumj--;	
			}
			if(sumi >= 6) {
				ans += calc(count) * ((sumi- 4)*(sumi-5)/2%mod) %mod;
				ans %= mod;
			}
			if(sumj >= 6) {
				ans += calc(count) * ((sumj- 4)*(sumj-5)/2 % mod)%mod;
				ans %= mod;
			}
		}
	}
	cout<<ans<<"\n";
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	cin >> T;
	while(T--) {
		work();
	}
	
	return 0;
}
