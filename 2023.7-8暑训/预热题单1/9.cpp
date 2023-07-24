#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n, m, q;
	cin >> n >> m >> q;

	int gcd = __gcd(n, m);
	int dn = n / gcd;
	int dm = m / gcd;
	for(int i = 1; i <= q; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		auto getArea = [&](int x, int y) {
			if(x == 1) return (y - 1) / dn;
			else return (y - 1) / dm;
		};

		int sz = getArea(sx, sy);
		int ez = getArea(ex, ey);
		
		// cout << sz << " " << ez << endl;

		if(sz == ez) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
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
