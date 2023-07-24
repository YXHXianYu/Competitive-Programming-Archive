#include<bits/stdc++.h>
#define int long long
#define lson t[p].ls
#define rson t[p].rs 
#define lson2 t2[p].ls
#define rson2 t2[p].rs 
using namespace std;
const int N = 2e5 + 1010;
const int inf = 1ll << 60;

int T;
int n, m;
int a[N], root[3];
struct node{
	int minn, sum, sz;
	int ls, rs;
	int tag;
}t[N*10];
struct node2{
	int sum,sz;
	int tag, tag2;
	int ls, rs;
}t2[N * 10];
int cnt = 0, tot = 0;

void update(int p) {
	t[p].minn = inf;
	if(t[lson].sz) t[p].minn = min(t[p].minn, t[lson].minn);
	if(t[rson].sz) t[p].minn = min(t[p].minn, t[rson].minn);
	t[p].sum = t[lson].sum + t[rson].sum;
	t[p].sz = t[lson].sz + t[rson].sz;
}

void update2(int p) {
	t2[p].sum = t2[lson2].sum + t2[rson2].sum;
	t2[p].sz = t2[lson2].sz + t2[rson2].sz;
}

void insert(int &p, int l, int r, int pos, int val) {
	if(!p) p = ++cnt;
	if(l == r) {
		t[p].minn = val;
		t[p].sum = val;
		t[p].sz = 1;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid) insert(lson, l, mid, pos, val);
	else insert(rson, mid + 1, r, pos, val);
	update(p);
//	cout<<"check insert: "<<l<<" "<<r<<" "<<pos<<" "<<t[p].sum<<endl;
}
void pushdown(int p) {
	int tag = t[p].tag;
	if(t[lson].sz)t[lson].minn -= tag;
	if(t[rson].sz)t[rson].minn -= tag;
	t[lson].sum -= t[lson].sz * tag;
	t[rson].sum -= t[rson].sz * tag;
	
	
	t[lson].tag += tag;
	t[rson].tag += tag;
}
void pushdown2(int p) {
	int tag = t2[p].tag, tag2 = t2[p].tag2;
//	cout<<"check pushdown(2) : "<<tag<<" "<<tag2<<endl;
	if(!tag) {
		if(t2[lson2].sz) t2[lson2].sum += tag2*t2[lson2].sz;
		if(t2[rson2].sz) t2[rson2].sum += tag2*t2[rson2].sz;
		t2[lson].tag2 += tag2;
		t2[rson].tag2 += tag2;
		return;
	}
	if(t2[lson2].sz) t2[lson2].sum *= -1;
	if(t2[rson2].sz) t2[rson2].sum *= -1;
	if(t2[lson2].sz) t2[lson2].sum += tag2*t2[lson2].sz;
	if(t2[rson2].sz) t2[rson2].sum += tag2 * t2[rson2].sz;
	t2[lson].tag2 *= -1;
	t2[rson].tag2 *= -1;
	t2[lson].tag2 += tag2;
	t2[rson].tag2 += tag2;
	t2[lson2].tag ^= 1;
	t2[rson2].tag ^= 1;
}

void insert2(int &p, int l, int r, int po, int val) {
	if(!p) p = ++tot;
	if(l == r) {
		
		t2[p].sz = 1;
		t2[p].sum = val;
		
//	cout<<"check insert(2)  "<<l<<" "<<r<<" "<<po<<" "<<t2[p].sum<<" "<<t2[p].sz<<endl;
		return;
	}
	pushdown2(p);
	int mid = l + r >> 1;
	if(po <= mid) insert2(lson2, l, mid, po, val);
	else insert2(rson2, mid + 1, r , po, val);
	update2(p);
//	cout<<"check insert(2)  "<<l<<" "<<r<<" "<<po<<" "<<t2[p].sum<<" "<<t2[p].sz<<endl;
}

void del2(int &p, int l, int r, int ql, int qr, int val) {
	if(t2[p].sz == 0) return;
	if(ql <= l && r <= qr) {
		t2[p].sum *= -1;
		t2[p].sum += val * t2[p].sz;
		t2[p].tag^= 1;
		t2[p].tag2 *= -1;
		t2[p].tag2 += val;
		return;
	}
	pushdown2(p);
	int mid = l + r >> 1;
	if(ql <= mid) del2(lson2, l, mid, ql, qr, val);
	if(qr > mid) del2(rson2, mid + 1, r, ql, qr, val);
	update2(p);
}

void del(int &p, int l, int r, int ql, int qr, int val) {
	if(t[p].sz == 0) return;
	if(ql <= l && r <= qr) {
		if(t[p].minn >= val) {
			t[p].sum -= t[p].sz * val;
			t[p].tag += val;
			t[p].minn -= val;
			return;
		}
		if(l == r) {
//			cout<<"insert2 "<<l<<" "<<val - t[p].minn<<endl;
			insert2(root[2], 1, n, l, val - t[p].minn);
			t[p].sz = 0;
			t[p].minn = inf;
			t[p].sum = 0;		
			return;
		}
	}
	pushdown(p);
	int mid = l + r >> 1;
	if(ql <= mid) del(lson, l, mid, ql, qr, val);
	if(qr > mid) del(rson, mid + 1, r, ql, qr , val);
	update(p);
//	cout<<"check del : " <<l<<" "<<r<<" "<<t[p].sum<<" "<<t[p].sz<<endl;
}

int query(int &p, int l, int r, int ql, int qr) {
	if(t[p].sz == 0) return 0;
	if(ql <= l &&  r <= qr) {
//		cout<<"check: "<<ql<<" "<<qr<<" "<<t[p].sum<<endl;
		return t[p].sum;
	}	
	pushdown(p);
	int mid = l + r >> 1;
	int ret = 0;
	if(ql <= mid) ret += query(lson,l, mid, ql, qr);
	if(qr > mid) ret += query(rson, mid + 1, r, ql, qr);
	return ret;
}
int query2(int &p, int l, int r, int ql, int qr) {
	
	if(t2[p].sz == 0) return 0;
	if(ql <= l &&  r <= qr) {
//		cout<<"check query(2) "<<l<<" "<<r<<" "<<t2[p].sum<<" "<<t2[p].sz<<endl;
		return t2[p].sum;
	}
	pushdown2(p);
	int mid = l + r >> 1;
	int ret = 0;
	if(ql <= mid) ret += query2(lson2, l, mid, ql, qr);
	if(qr > mid) ret += query2(rson2, mid + 1, r, ql, qr);
	return ret; 
}



void solve() {
	scanf("%lld%lld", &n, &m);
	cnt = 0, tot = 0;
	
	
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		insert(root[1], 1, n, i, a[i]);
	}
	
	
	for(int i = 1, opt, l , r, x; i <= m; ++i) {
		scanf("%lld%lld%lld", &opt, &l, &r);
		if(opt == 1) {
			scanf("%lld", &x);
			
			del2(root[2], 1, n, l, r, x);
			del(root[1], 1, n, l, r, x);
		}
		else {
			int ret = query2(root[2],1,n,l,r);
			ret += query(root[1], 1, n, l, r);
			printf("%lld\n", ret);
		}
	}
	root[1] = root[2] = 0;
	for(int i = 1; i <= cnt; ++i) {
		t[i].ls = t[i].rs = t[i].minn = t[i].sum = t[i].tag = t[i].sz = 0;
	}
	for(int i = 1; i <= tot; ++i) {
		t2[i].ls = t2[i].rs = t2[i].sz = t2[i].sum = t2[i].tag = t2[i].tag2 = 0;
	}
	
}


signed main() {
	scanf("%lld", &T);

	while(T--) {
		solve();
	}

	return 0;
}

