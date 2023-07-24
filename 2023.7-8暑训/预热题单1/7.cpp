#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;

void work() {
	string s;
	cin >> s;
	int n = s.length();
	s = " " + s;

	for(int i = 1; i <= n; i++) {
		if(s[i] == 'w' || s[i] == 'm') {
			cout << 0 << endl;
			return;
		}
	}


	int ans = 1;
	int cnt = 0;

	vector<int> f(n + 1);
	f[1] = 1;
	f[2] = 2;
	for(int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= MOD;
	}

	for(int i = 2; i <= n; i++) {
		if(s[i - 1] == s[i] && (s[i] == 'u' || s[i] == 'n')) {
			if(cnt == 0) cnt = 2;
			else cnt++;
		} else if(cnt > 0) {
			ans = ans * f[cnt] % MOD;
			cnt = 0;
		}
	}
	// cout << ans << ", " << cnt << endl;
	if(cnt > 0) ans = ans * f[cnt] % MOD;
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
