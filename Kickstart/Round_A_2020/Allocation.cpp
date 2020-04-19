#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

const int maxs = 1e6+10;
const int mod = 1e9+7;

void solve_cases() {
	int n,b;
	cin >> n >> b;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		b -= a[i];
		if(b == 0) {
			cnt++;
			break;
		} else if(b < 0)
			break;
		cnt++;
	}
	cout << cnt << endl;
	return;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1,i = 1;
	cin >> t;
	while(i <= t) {
		cout << "Case #" << i << ": ";
		solve_cases();
		i++;
	}
	return 0;
}

