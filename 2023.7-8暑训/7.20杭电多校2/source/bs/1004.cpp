#include<bits/stdc++.h>
using namespace std;
#define int long long


void work() {
	int n;
	cin >> n;
	
	if(n == 2) {
		cout << 1 << endl;
		return;
	}
	
	const int MOD = 998244353;
	
	auto Pow = [](int a, int n) {
		int ans = 1;
		while(n) {
			if(n & 1) ans = ans * a % MOD;
			a = a * a % MOD;
			n >>= 1;
		}
		return ans;
	};
	
	int ans = Pow(2, n - 1) - 1 + MOD;
	ans %= MOD;
	cout << ans << endl;
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
