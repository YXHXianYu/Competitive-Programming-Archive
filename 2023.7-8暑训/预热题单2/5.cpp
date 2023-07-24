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

	int mx = 4e6;
	set<int> f;
	vector<int> g;
	for(int i = 1; i <= n; i++) {
		vector<int> h;

		if(a[i] <= mx) {
			h.push_back(a[i]);
		}
		for(auto& j: g) {
			int v = lcm(j, a[i]);
			if(v <= mx) {
				h.push_back(v);
			}
		}

		sort(h.begin(), h.end());
		h.erase(unique(h.begin(), h.end()), h.end());

		// cout << i << ": ";
		// for(auto& x: h) cout << x << " ";
		// cout << endl;
		
		g = h;
		for(auto& j: g) {
			f.insert(j);
		}
	}

	int cnt = 1;
	for(const auto& x: f) {
		if(x == cnt) {
			cnt++;
		} else {
			cout << cnt << endl;
			return;
		}
	}
	// f is empty
	cout << cnt << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		work();
	}
	
	return 0;
}
