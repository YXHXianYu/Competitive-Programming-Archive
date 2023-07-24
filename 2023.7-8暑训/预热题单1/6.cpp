#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n;
	cin >> n;
	vector<int> u(n + 1);
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++) cin >> u[i];
	for(int i = 1; i <= n; i++ )cin >> v[i];

	vector<vector<int>> a(n + 1, vector<int>());
	for(int i = 1; i <= n; i++) {
		a[u[i]].push_back(v[i]);
	}

	vector<int> ans(n + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i].size() == 0) continue;
		sort(a[i].begin(), a[i].end());
		reverse(a[i].begin(), a[i].end());

		// cout << i << ": " << endl;
		// for(auto& j: a[i]) {
		// 	cout << j << " ";
		// }
		// cout << endl;

		vector<int> s(a[i].size());
		s[0] = a[i][0];
		for(int j = 1; j < a[i].size(); j++) {
			s[j] = s[j - 1] + a[i][j];
		}
		
		// for(int j = 0; j < a[i].size(); j++) {
		// 	cout << s[j] << " ";
		// }
		// cout << endl;

		for(int j = 1; j <= a[i].size(); j++) {
			int left = a[i].size() % j;
			ans[j] += s[a[i].size() - left - 1];
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
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
