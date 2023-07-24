#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;


void work() {
	int n;
	cin >> n;
	int r1, c1, r2, c2;
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	vector<vector<int>> a(n + 2, vector<int>(n + 2, 1));
	for(int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for(int j = 1; j <= n; j++) {
			a[i][j] = str[j - 1] - '0';
		}
	}	

	int mx[4] = {0, 0, 1, -1};
	int my[4] = {1, -1, 0, 0};
	auto bfs = [&](int sx, int sy, int col) {
		queue<pair<int, int>> q;
		q.push({sx, sy});
		a[sx][sy] = col;
		while(!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for(int i = 0; i <= 3; i++) {
				int cx = x + mx[i];
				int cy = y + my[i];
				if(a[cx][cy] != 0) continue;
				q.push({cx, cy});
				a[cx][cy] = col;
			}
		}
	};

	bfs(r1, c1, 2);
	if(a[r2][c2] == 2) {
		cout << 0 << endl;
		return;
	}

	bfs(r2, c2, 3);

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= n; j++) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	const int INF = 1LL << 60;
	int ans = INF;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] != 2) continue;
			for(int k = 1; k <= n; k++) {
				for(int p = 1; p <= n; p++) {
					if(a[k][p] != 3) continue;
					ans = min(ans, (i-k)*(i-k)+(j-p)*(j-p));
				}
			}
		}
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
