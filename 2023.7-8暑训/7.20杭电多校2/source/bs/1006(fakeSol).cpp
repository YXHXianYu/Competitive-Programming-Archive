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
	
	a = convexHull(a);
	n = a.size() - 1;
	
	b = convexHull(b);
	m = b.size() - 1;
	
//	cout << "a: " << endl;
//	for(int i = 1; i <= n; i++) {
//		cout << "   " << i << ": " << a[i].x << ", " << a[i].y << endl;
//	}
//	cout << "b: " << endl;
//	for(int i = 1; i <= m; i++) {
//		cout << "   " << i << ": " << b[i].x << ", " << b[i].y << endl;
//	}
	
	auto judge = [&](P p1, P p2) -> bool {
		for(int i = 1; i <= m; i++) {
			if(crossOp(p1, p2, b[i]) <= 0) {
				return false;
			}
		}
		return true;
	};
	
	// -1
	bool inside = true;
	for(int i = 1; i <= n; i++) {
		P u = a[i], v = a[i % n + 1];
		inside = judge(u, v);
		if(!inside) break;
	}
	if(!inside) {
		cout << -1 << endl;
		return;
	}
	
	int ans = n;
	for(int i = 1; i <= n; i++) {
		vector<P> ps;
		ps.push_back(a[i]);
		P u = a[i];
		for(int j = 2; j <= n; j++) {
			P v = a[(i + j - 1) % n + 1];
			if(!judge(u, v)) {
				ps.push_back(a[(i + j - 2) % n + 1]);
				u = a[(i + j - 2) % n + 1];
			}
		}
		ans = min(ans, ((int)(ps.size())));
//		if(ans == 3) {
//			cout << 3 << ": " << endl;
//			for(auto x: ps) {
//				cout << " ~ " << x.x << ", " << x.y << endl;
//			}
//		}
	}
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
