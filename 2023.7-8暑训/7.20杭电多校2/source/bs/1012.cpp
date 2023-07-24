#include<bits/stdc++.h>
using namespace std;

const int M = 3000;
const long long inf = 1e18;
int n, m, s, t;
struct node {
	int to, next;
	long long va;
} e[4 * M];

int last[4 * M], tot = 1;
void addEdge(int fm, int to, long long va) {
	e[++tot].to = to;
	e[tot].va = va;
	e[tot].next = last[fm];
	last[fm] = tot;
}
int now[4 * M];

int vis[4 * M];
int d[4 * M];
bool bfs() {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	d[s] = 1;
	now[s] = last[s];
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i = last[x]; i; i = e[i].next) {
			int y = e[i].to;
			if(vis[y] || e[i].va <= 0) continue;
			q.push(y);
			vis[y] = 1;
			d[y] = d[x] + 1;
			now[y] = last[y];
			if(y == t) return 1;
		}
	}
	return 0;
}

long long dinic(int x, long long flow) {
	if(x == t) return flow;
	long long rest = flow;
	for(int i = now[x]; i && rest; i = e[i].next) {
		now[x] = i;
		int y = e[i].to;
		if(e[i].va <= 0 || d[y] != d[x] + 1) continue;
		long long k = dinic(y, min(rest, e[i].va));
		if(k == 0) d[y] = 0;
		
		e[i].va -= k;
		e[i ^ 1].va += k;
		rest -= k;
	}
	return flow - rest;
}

int a[3001];
int p[4 * M];
int idx;
int main() {
	int T;
	cin >> T;
	int k;
	int u, v;
	int b;
	while(T--) {
		scanf("%d%d%d", &n, &m, &k);
		memset(p, 0, sizeof(p));
		memset(last, 0, sizeof(last));
		memset(now, 0, sizeof(now));
		idx = 2;
		tot = 1;
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			addEdge(idx, idx + 1, 1);
			addEdge(idx + 1, idx, 0);
			addEdge(idx + 1, idx, 1);
			addEdge(idx, idx + 1, 0);
			if(p[u]) addEdge(p[u], idx, a[u]), addEdge(idx, p[u], 0);
			else addEdge(1, idx, 1), addEdge(idx, 1, 0);
			if(p[v]) addEdge(p[v], idx + 1, a[v]), addEdge(idx + 1, p[v], 0);
			else addEdge(1, idx + 1, 1), addEdge(idx + 1, 1, 0);
			p[u] = idx, p[v] = idx + 1;
			idx += 2;
		}
		for(int i = 0; i < k; i++) {
			scanf("%d", &b);
			if(p[b]) addEdge(p[b], idx, a[b]), addEdge(idx, p[b], 0);
			else addEdge(1, idx, 1), addEdge(idx, 1, 0);
		}
		t = idx;
		s = 1;
		long long maxflow = 0, flow;
		while(bfs()) {
			while(flow = dinic(s, inf)) {
				maxflow += flow;
			}
		}
		printf("%lld\n", maxflow);
	}
	return 0;
}
