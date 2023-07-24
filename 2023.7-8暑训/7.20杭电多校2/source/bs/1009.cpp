#include<bits/stdc++.h>
using namespace std;
#define int long long


void work() {
	string str;
	cin >> str;
	int n = str.size();
	
	int ans = 0;
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		if(str[i - 1] == str[i]) {
			cnt++;
		} else {
			ans += cnt - 1;
			cnt = 1;
		}
	}
	ans += cnt - 1;
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
