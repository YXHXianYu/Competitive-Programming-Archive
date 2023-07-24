#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100001];
signed main() {
	int t;
	cin >> t;
	int n, k;
	while(t--) {
		scanf("%lld%lld", &n, &k);
		int zcnt = 0;
		getchar();
		for(int i = 0; i < n; i++) {
			a[i] = getchar() - '0';
			zcnt += 1 - a[i];
		}
		int zzcnt = 0;
		for(int i = 1; i < n; i++) {
			if(a[i] == 1 && a[i - 1] == 0) zzcnt++;
		}
		if(a[n - 1] == 0) zzcnt++;
		if(zzcnt > k) {
			int fcnt = 0;
			for(int i = 0; i < n && fcnt < k; i++) {
				if(i < n - 1 && a[i] == 0 && a[i + 1] == 1) fcnt++;
				if(a[i] == 0) a[i] = 1;
			}
			for(int i = 0; i < n; i++) {
				printf("%lld", a[i]);
			}
		} else {
			if(n == 1) {
				if((zcnt & 1) != (k & 1)) printf("0");
				else printf("1");
			} else if(zcnt == 0 && k == 1){
				for(int i = 0; i < n - 1; i++) {
					printf("1");
				}
				printf("0");
			} else {
				for(int i = 0; i < n; i++) {
					printf("1");
				}
			}
		}
		puts("");
	}
}
