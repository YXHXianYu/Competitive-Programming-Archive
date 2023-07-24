#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M = 3e3;
vector<int> g[M + 2];
int n, m;

int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return d;
}

int fa[M + 1][13];
int dep[M + 1];
void build(int u, int f) {
	fa[u][0] = f;
	for(int i = 1; i < 13; i++) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for(int e : g[u]) {
		if(e == f) continue;
		dep[e] = dep[u] + 1;
		build(e, u);
	}
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	int d = dep[v] - dep[u];
	for(int i = 0; d; d >>= 1, i++) {
		if(d & 1) v = fa[v][i];
	}
	if(u == v) return v;
	for(int i = 12; i > -1; i--) {
		if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}

bool vis[M + 1];
int last[M + 1];
vector<int> path1, path2;
void bfs(int s, int t, int f) {
	memset(vis, 0, (n + 1) * sizeof(bool));
	queue<int> qu;
	qu.push(s);
	vis[s] = true;
	while(!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		for(int e : g[cur]) {
			if(vis[e]) continue;
			vis[e] = true;
			last[e] = cur;
			qu.push(e);
		}
	}
	if(f == 1) {
		path1.clear();
		while(t != s) {
			path1.push_back(t);
			t = last[t];
		}
		path1.push_back(s);
		reverse(path1.begin(), path1.end());
	} else if(f == 2) {
		path2.clear();
		while(t != s) {
			path2.push_back(t);
			t = last[t];
		}
		path2.push_back(s);
		reverse(path2.begin(), path2.end());
	}
}

signed main() {
//	freopen("D:/CPP/cases/1001.in", "r", stdin);
	int t;
	cin >> t;
	int a, b;
	int sa, ta, sb, tb;
	while(t--) {
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for(int i = 1; i < n; i++) {
			scanf("%lld%lld", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		build(1, 0);
		
		while(m--) {
			scanf("%lld%lld%lld%lld", &sa, &ta, &sb, &tb);
			
			bfs(sa, ta, 1);
			bfs(sb, tb, 2);
			
			int r1a = lca(sa, ta), r2a = lca(sb, tb);
			int len1 = dep[r1a] - dep[sa] + dep[r1a] - dep[ta], len2 = dep[r2a] - dep[sb] + dep[r2a] - dep[tb];
			len1 = -len1, len2 = -len2;
			int as[4] = {lca(sa, sb), lca(sa, tb), lca(ta, sb), lca(ta, tb)};
			sort(as, as + 4, [] (int a, int b) { return dep[a] > dep[b]; });
			int st1, ed1, st2, ed2;
			int stp1, edp1, stp2, edp2;
			if(as[0] == as[1]) {
				if(dep[as[0]] < dep[r1a] || dep[as[0]] < dep[r2a]) {
					puts("-1");
					continue;
				} else {
					int x = lca(sa, as[0]);
					if(x == as[0]) st1 = ed1 = dep[as[0]] - dep[sa];
					else st1 = ed1 = dep[x] - dep[sa] + dep[x] - dep[as[0]];
					st1 = -st1, ed1 = -ed1;
					
					x = lca(sb, as[0]);
					if(x == as[0]) st2 = ed2 = dep[as[0]] - dep[sb];
					else st2 = ed2 = dep[x] - dep[sb] + dep[x] - dep[as[0]];
					stp1 = stp2 = edp1 = edp2 = as[0];
					st2 = -st2, ed2 = -ed2;
				}
			} else {
				int x = lca(sa, as[0]);
				if(x == as[0]) st1 = dep[as[0]] - dep[sa];
				else st1 = dep[x] - dep[sa] + dep[x] - dep[as[0]];
				x = lca(sa, as[1]);
				if(x == as[1]) ed1 = dep[as[1]] - dep[sa];
				else ed1 = dep[x] - dep[sa] + dep[x] - dep[as[1]];
				stp1 = as[0], edp1 = as[1];
				st1 = -st1, ed1 = -ed1;
				if(st1 > ed1) swap(st1, ed1), swap(stp1, edp1);
				
				x = lca(sb, as[0]);
				if(x == as[0]) st2 = dep[as[0]] - dep[sb];
				else st2 = dep[x] - dep[sb] + dep[x] - dep[as[0]];
				x = lca(sb, as[1]);
				if(x == as[1]) ed2 = dep[as[1]] - dep[sb];
				else ed2 = dep[x] - dep[sb] + dep[x] - dep[as[1]];
				stp2 = as[0], edp2 = as[1];
				st2 = -st2, ed2 = -ed2;
				if(st2 > ed2) swap(st2, ed2), swap(stp2, edp2);
			}
			
			int ans = -1, anslen = 5e8;
			
			len1 *= 2, len2 *= 2;
			int x1, x2;
			exgcd(len1, len2, x1, x2);
			x2 = -x2;
			int g = __gcd(len1, len2);
			int s1 = len2 / g, s2 = len1 / g;
			int st11 = len1 - ed1, ed11 = len1 - st1, st21 = len2 - ed2, ed21 = len2 - st2;
			if(stp1 == stp2) {
				int c = st2 - st1;
				if(c % g == 0) {
					int y = c / g;
					int cx1 = x1 * y, cx2 = x2 * y;
					cx1 += len2 * n * 2, cx2 += len1 * n * 2;
//					cout << cx1 << ' ' << cx2 << '\n';
					assert(cx1 > 0 && cx2 > 0);
					int down = min(cx1 / s1, cx2 / s2);
					cx1 -= s1 * down;
					int curlen = cx1 * len1 + st1;
					if(anslen > curlen) {
						anslen = curlen;
						ans = stp1;
					}
				}
				
				c = st21 - st11;
				if(c % g == 0) {
					int y = c / g;
					int cx1 = x1 * y, cx2 = x2 * y;
					cx1 += len2 * n * 2, cx2 += len1 * n * 2;
					assert(cx1 > 0 && cx2 > 0);
					int down = min(cx1 / s1, cx2 / s2);
					cx1 -= s1 * down;
					int curlen = cx1 * len1 + st11;
					if(anslen > curlen) {
						anslen = curlen;
						ans = edp1;
					}
				}
				
				for(int i = st1, j = ed21; i <= ed1; i++, j--) {
					c = j - i;
					if(c % g == 0) {
						int y = c / g;
						int cx1 = x1 * y, cx2 = x2 * y;
						cx1 += len2 * n * 2, cx2 += len1 * n * 2;
						assert(cx1 > 0 && cx2 > 0);
						int down = min(cx1 / s1, cx2 / s2);
						cx1 -= s1 * down;
						int curlen = cx1 * len1 + i;
						if(anslen > curlen) {
							anslen = curlen;
							ans = path1[i];
						}
					}
				}
				
				for(int i = st2, j = ed11; i <= ed2; i++, j--) {
					c = i - j;
					if(c % g == 0) {
						int y = c / g;
						int cx1 = x1 * y, cx2 = x2 * y;
						cx1 += len2 * n * 2, cx2 += len1 * n * 2;
						assert(cx1 > 0 && cx2 > 0);
						int down = min(cx1 / s1, cx2 / s2);
						cx1 -= s1 * down;
						int curlen = cx1 * len1 + j;
						if(anslen > curlen) {
							anslen = curlen;
							ans = path2[i];
						}
					}
				}
			} else {
				int c = st21 - st1;
				if(c % g == 0) {
					int y = c / g;
					int cx1 = x1 * y, cx2 = x2 * y;
					cx1 += len2 * n * 2, cx2 += len1 * n * 2;
					assert(cx1 > 0 && cx2 > 0);
					int down = min(cx1 / s1, cx2 / s2);
					cx1 -= s1 * down;
					int curlen = cx1 * len1 + st1;
					if(anslen > curlen) {
						anslen = curlen;
						ans = stp1;
					}
				}
				
				c = st2 - st11;
				if(c % g == 0) {
					int y = c / g;
					int cx1 = x1 * y, cx2 = x2 * y;
					cx1 += len2 * n * 2, cx2 += len1 * n * 2;
					assert(cx1 > 0 && cx2 > 0);
					int down = min(cx1 / s1, cx2 / s2);
					cx1 -= s1 * down;
					int curlen = cx1 * len1 + st11;
					if(anslen > curlen) {
						anslen = curlen;
						ans = edp1;
					}
				}
				
				for(int i = st1, j = ed2; i <= ed1; i++, j--) {
					c = j - i;
					if(c % g == 0) {
						int y = c / g;
						int cx1 = x1 * y, cx2 = x2 * y;
						cx1 += len2 * n * 2, cx2 += len1 * n * 2;
						assert(cx1 > 0 && cx2 > 0);
						int down = min(cx1 / s1, cx2 / s2);
						cx1 -= s1 * down;
						int curlen = cx1 * len1 + i;
						if(anslen > curlen) {
							anslen = curlen;
							ans = path1[i];
						}
					}
				}
				
				for(int i = st21, j = ed11; i <= ed21; i++, j--) {
					c = i - j;
					if(c % g == 0) {
						int y = c / g;
						int cx1 = x1 * y, cx2 = x2 * y;
						cx1 += len2 * n * 2, cx2 += len1 * n * 2;
						assert(cx1 > 0 && cx2 > 0);
						int down = min(cx1 / s1, cx2 / s2);
						cx1 -= s1 * down;
						int curlen = cx1 * len1 + j;
						if(anslen > curlen) {
							anslen = curlen;
							ans = path2[len2 - i];
						}
					}
				}
			}
			
			printf("%lld\n", ans);
		}
	}
	return 0;
}
