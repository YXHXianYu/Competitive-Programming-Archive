#include<bits/stdc++.h>
#define int long long
using namespace std;

void work() {
	int n, m, d;
	cin >> n >> m >> d;
	
	int v = m / n;
	if(m % n != 0) v++;
	
	if(d <= v) cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	 cin >> t;
	while(t--) {
		work();
	}
	
	return 0;
} 