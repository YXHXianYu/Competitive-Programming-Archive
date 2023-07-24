#include<bits/stdc++.h>
using namespace std;
#define int long long

typedef long long db;
const db EPS = 1e-9;

inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }

inline int cmp(db a, db b) { return sign(a - b); }

struct P {
	db x, y;
	P(): x(0), y(0) {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) {
		return {x + p.x, y + p.y};
	}
	P operator-(P p) {
		return {x - p.x, y - p.y};
	}
	P operator*(db d) {
		return {x * d, y * d};
	}
	P operator/(db d) {
		return {x / d, y / d};
	}
	
	bool operator<(P p) const {
		int c = cmp(x, p.x);
		if(c) return c == -1;
		return cmp(y, p.y) == -1;
	}
	
	bool operator==(P p) const {
		return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
	}
	
	db dot(P p) {
		return x * p.x + y * p.y;
	}
	db det(P p) {
		return x * p.y - y * p.x;
	}
	
	void read() {
		cin >> x >> y;
	}
	
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
};

#define cross(p1, p2, p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1, p2, p3) (sign(cross(p1, p2, p3)))

vector<P> convexHull(vector<P>& ps) {
	int n = ps.size() - 1;
	if(n <= 1) return ps;
	sort(ps.begin() + 1, ps.begin() + n + 1);
	vector<P> qs(2 * n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; qs[++cnt] = ps[i++]) {
		while(cnt > 1 && crossOp(qs[cnt - 1], qs[cnt], ps[i]) <= 0) cnt--;
	}
	for(int i = n - 1, t = cnt; i >= 1; qs[++cnt] = ps[i--]) {
		while(cnt > t && crossOp(qs[cnt - 1], qs[cnt], ps[i]) <= 0) cnt--;
	}
	qs.resize(cnt);
	return qs;
}



void work() {
	int n, m;
	cin >> n >> m;
	
	vector<P> a(n + 1);
	vector<P> b(m + 1);
	for(int i = 1; i <= n; i++) {
		a[i].read();
	}
	for(int i = 1; i <= m; i++) {
		b[i].read();
	}
	
	b = convexHull(b);
	m = b.size() - 1;
	
	auto judge = [&](P p1, P p2) -> bool {
		for(int i = 1; i <= m; i++) {
			if(crossOp(p1, p2, b[i]) <= 0) {
				return false;
			}
		}
		return true;
	};

	const int INF = 1LL << 60;
	vector<vector<int>> f(n + 1, vector<int>(n + 1, INF));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if(judge(a[i], a[j])) {
				f[i][j] = 1;
			}
		}
	}

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

	int ans = INF;
	for(int i = 1; i <= n; i++) ans = min(ans, f[i][i]);
	if(ans == INF)
		cout << -1 << endl;
	else
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
