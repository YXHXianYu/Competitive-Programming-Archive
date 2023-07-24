#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef double db;
const int maxn = 2e5 + 10;
const db EPS = 1e-3;


void work() {
	int n;
	scanf("%lld", &n);

	vector<pair<db, db>> a(n + 1);
	for(int i = 1; i <= n; i++) {
		// cin >> a[i].first >> a[i].second;
		scanf("%lf%lf", &a[i].first, &a[i].second);
	}

	db L = a[1].first;
	db R = a[1].first;
	for(int i = 2; i <= n; i++) {
		L = min(L, a[i].first);
		R = max(R, a[i].first);
	}

	auto solve = [&](db x) {
		db ans = 0;
		for(int i = 1; i <= n; i++) {
			db S = abs(x - a[i].first);
			ans += a[i].second * S * S * S;
		}
		return ans;
	};

	for(int i = 1; i <= 300; i++) {
		// cout << L << ", " << R << endl;
		db delta = (R - L) / 3.0;
		db mid1 = L + delta;
		db mid2 = L + 2.0 * delta;
		db v1 = solve(mid1);
		db v2 = solve(mid2);
		if(v1 <= v2) {
			R = mid2;
		} else {
			L = mid1;
		}
	}

	int ans;
	L = (L + R) / 2.0;
	L = solve(L);
	if(L - ((int)(L)) < 0.5) {
		ans = ((int)(L));
	} else {
		ans = ((int)(L)) + 1;
	}
	// cout << ans << endl;
	printf("%lld\n", ans);
}

signed main() {
	
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		printf("Case #%d: ", i);
		work();
	}
	
	return 0;
}
