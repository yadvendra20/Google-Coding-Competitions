#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

const int maxs = 1e6+10;
const int mod = 1e9+7;

void solve_cases() {
	int n,k,p;
	cin >> n >> k >> p;
	vector<vector<int>> beautiVal(n+1,vector<int>(k+1,0));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k;j++) { 
			cin >> beautiVal[i][j];
			beautiVal[i][j] += beautiVal[i][j-1];
		}
	}
	vector<vector<int>> dp(n+1,vector<int>(p+1,0));
	for(int i=1;i<=n;i++)
		for(int j=0;j<=p;j++)
			for(int x=0;x<=min(j,k);x++)
				dp[i][j] = max(dp[i][j], beautiVal[i][x] + dp[i-1][j-x]);
	cout << dp[n][p] << endl;
	return;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t,i = 1;
	cin >> t;
	while(i <= t) {
		cout << "Case #" << i << ": ";
		solve_cases();
		i++;
	}
	return 0;
}

