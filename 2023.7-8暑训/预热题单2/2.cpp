#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n, K;
	cin >> n >> K;

	vector<array<int, 5>> a(n + 1);
	vector<array<int, 5>> b(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		a[i][3] = 1; // cnt
		a[i][4] = 0; // ans
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	int cnt = 0;
	b[++cnt] = a[1];
	for(int i = 2; i <= n; i++) {
		if(a[i-1][0] == a[i][0] && a[i-1][1] == a[i][1] && a[i-1][2] == a[i][2]) {
			b[cnt][3]++;
		} else {
			b[++cnt] = a[i];
		}
	}
	int N = n;
	n = cnt;
	for(int i = 1; i <= n; i++) {
		a[i] = b[i];
	}

	vector<int> bit(K + 1);
	auto lowbit = [&](int x) {
		return x&-x;
	};
	auto add = [&](int x, int v) {
		for(; x <= K; x += lowbit(x)) bit[x] += v;
	};
	auto query = [&](int x) {
		int ans = 0; for(; x; x -= lowbit(x)) ans += bit[x]; return ans;
	};
	
	function<void(int, int)> cdq = [&](int l, int r) {
		if(l == r) return;
		
		int mid = l + r >> 1;
		cdq(l, mid);
		cdq(mid+1, r);

		// cout << l << ", " << r << ": " << endl;
		// cout << " - "; for(int i = l; i <= mid; i++) cout << "(" << a[i][1] << "," << a[i][2] << "," << a[i][3] << ") "; cout << endl;
		// cout << " - "; for(int i = mid+1; i <= r; i++) cout << "(" << a[i][1] << "," << a[i][2] << ") "; cout << endl;

		int i = l;
		int j = mid + 1;
		// cout << "init: " << query(3) << endl;
		for(; j <= r; j++) {
			while(i <= mid && a[i][1] <= a[j][1]) {
				add(a[i][2], a[i][3]);
				// cout << "add: " << a[i][2]<< ", " << a[i][3] << ", k=" << 3 << ", s=" << query(3) << endl;
				i++;
			}
			a[j][4] += query(a[j][2]);
			// if(a[j][4] == 15) cout << "---" << a[j][2] << ", " << query(a[j][2]) << endl;
		}
		for(; i > l; i--) {
			add(a[i-1][2], -a[i-1][3]);
			// cout << "add: " << a[i-1][2] << ", " << -a[i-1][3] << endl;
		}
		// cout << "end: " << query(3) << endl;

		i = l;
		j = mid + 1;
		int k = l;
		while(i <= mid && j <= r) {
			if(a[i][1] <= a[j][1]) {
				b[k++] = a[i++];
			} else {
				b[k++] = a[j++];
			}
		}
		while(i <= mid) b[k++] = a[i++];
		while(j <= r) b[k++] = a[j++];
		for(k = l; k <= r; k++) a[k] = b[k];
	};

	cdq(1, n);

	// for(int i = 1; i <= n; i++) cout << a[i][4] << ": " << a[i][3] << endl;

	vector<int> ans(N + 1);
	for(int i = 1; i <= n; i++) ans[a[i][4] + a[i][3] - 1] += a[i][3];
	for(int i = 0; i < N; i++) cout << ans[i] << endl;
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
