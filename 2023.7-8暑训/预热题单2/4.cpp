#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> cnt(m + 1);
	int sum = 0;
	int L = 1, R = 0;
	while(sum < m && R < n) {
		R += 1;
		cnt[a[R]]++;
		if(cnt[a[R]] == 1) {
			sum += 1;
		}
	}	

	int ansv = R - L + 1;
	int ans1 = L;
	int ans2 = R;
	cnt[a[R]]--;
	for(; R <= n; R++) {
		cnt[a[R]]++;
		while(cnt[a[L]] >= 2) {
			cnt[a[L]]--;
			L++;
		}
		if(R - L + 1 < ansv) {
			ansv = R - L + 1;
			ans1 = L;
			ans2 = R;
		}
	}
	cout << ans1 << " " << ans2 << endl;
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
