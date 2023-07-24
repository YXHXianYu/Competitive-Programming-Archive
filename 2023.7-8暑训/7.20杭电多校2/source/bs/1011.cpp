#include<bits/stdc++.h>
#define PII pair<int, int>
using namespace std;
#define int long long
#define vec vector<int>
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
int n;

vec fac[N], invf[N];
vector<int> operator * (const vector<int>& x, const vector<int>& y) {
	vector<int> res(x.size() + y.size() + 10);
	int r = max(x.size(), y.size());
	
	for(int i = 0; i < x.size(); i++) {
		for(int j = 0; j < y.size(); j++) {
			res[i + j] += x[i] * y[i];
			res[i + j + 1] += res[i + j] / mod;
			res[i + j] %= mod;
		}
	}
	for(int i = 0; i < res.size() - 1; i++) {
		res[i + 1] += res[i] / mod;
		res[i] %= mod;
	}
	while(res.back() == 0) res.resize(res.size() - 1);
	return res;
}
vector<int> operator + (const vector<int>& x, const vector<int>& y) {
	vector<int> res;
	int r = max(x.size(), y.size());
	int carry = 0;
	for(int i = 0; i < r; i++) {
		int cur = carry;
		if(i < x.size()) cur += x[i];
		if(i < y.size()) cur += y[i];
		carry = cur / mod;
		res.push_back(cur % mod);
	}
	if(carry > 0) res.push_back(carry);
}
int compare(const vector<int>& x, const vector<int>& y) {
	if(x.size() > y.size()) return 1;
	if(x.size() < y.size()) return -1;
	for(int i = x.size() - 1; i > -1; i--) {
		if(x[i] > y[i]) return 1;
		if(x[i] < y[i]) return -1;
	}
	return 0;
}



int ksm(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) {
			ret = ret * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

void pre() {
	fac[0] = {1};
	for(int i = 1; i < N; ++i) {
		vec tmp = {i};
		fac[i] = fac[i - 1] * tmp;
	}
}

//int check(int k) {
//	
//	vec left = {1};
//	vec tmp = {k};
//	left = left * fac[k-1];
//	left = left * fac[n-k-1];
//	left = left * fac[n-1];
//	left = left * tmp;
//	vec right = {0};
//	for(int p = k + 2; p <= n; ++p) {
//		left = left * fac[p-1] * fac[n - p];
//		vec qwq = {1};	
//		qwq = qwq * fac[p-2]*fac[n-p]*fac[k]*fac[n-1-k];
//		right = right + qwq;
//	}
//	if(compare(left, right) < 0) return 1;
//	else return 0; 
//}

double sum[N];
int check(int k) {
	if(sum[k + 1] > 1) {
		return 1;
	}
	return 0;
}

void work() {
	
	cin>>n;
	sum[n] = 0;
	for(int i = n - 1; i >= 0; --i) {
		sum[i] = sum[i + 1] + 1.0/i;
	}
	if(n == 1) {
		cout<<0<<"\n";
		return;
	}
	if(n == 2) {
		cout<<0<<"\n";
		return;
	}
	int l = 1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		//cout<<"mid is "<<mid<<endl;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	cout<<l<<"\n";
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
