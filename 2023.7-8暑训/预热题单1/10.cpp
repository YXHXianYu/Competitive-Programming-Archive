#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n;
	cin >> n;

	auto check = [&](int k) {
		int cnt = 0;
		int x = n;
		while(x >= 0) {
			if(x <= k) {
				cnt += x;
				break;
			}
			x -= k;
			cnt += k;
			x -= x / 10;
		}
		return cnt >= (n + 1) / 2;
	};

	int l = 0, r = n;
	while(r - l >= 2) {
		int mid = l + r >> 1;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << endl;
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
