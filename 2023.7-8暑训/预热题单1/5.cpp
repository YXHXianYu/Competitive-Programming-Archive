#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<pair<int, int>> q(n + 1); // first f; second value; f desc
	int hd = 0;
	int tl = 0;
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		while(hd < tl && q[hd + 1].second * 2 < a[i]) {
			hd++;
		}
		int cnt = 1;
		if(hd < tl) cnt = 1 + q[hd + 1].first;
		while(hd < tl && q[tl].first < cnt) {
			tl--;
		}
		q[++tl] = {cnt, a[i]};
		ans = max(ans, cnt);
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
