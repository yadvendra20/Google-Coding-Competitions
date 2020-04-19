#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

void solve_cases() 
{
	int n;
	cin >> n;
	int a[n][n];
	int trace = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> a[i][j];
			if(i == j)
				trace += a[i][j];
		}
	}
	int rows = 0,cols = 0;
	bool flg = false;
	vector<int> vis(n,0);
	for(int i=0;i<n;i++) {
		for(int k=0;k<n;k++)
			vis[k] = 0;
		flg = false;
		for(int j=0;j<n;j++) {
			vis[a[i][j]-1]++;
			if(vis[a[i][j]-1] > 1)
				flg = true;
		}
		if(flg)
			rows++;
	}
	for(int j=0;j<n;j++) {
		for(int k=0;k<n;k++)
			vis[k] = 0;
		flg = false;
		for(int i=0;i<n;i++) {
			vis[a[i][j]-1]++;
			if(vis[a[i][j]-1] > 1)
				flg = true;
		}
		if(flg)
			cols++;
	}
	cout << trace << " " << rows << " " << cols << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1,i = 1;
	cin >> t;
	while(t--) {
		cout << "Case #" << i << ": ";
		solve_cases();
		i++;
	}
	return 0;
}

