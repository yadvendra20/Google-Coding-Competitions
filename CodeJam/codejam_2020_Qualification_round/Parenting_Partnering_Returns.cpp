#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl "\n"
using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

bool cmp(pair<pair<int,int>,int> &A,pair<pair<int,int>,int> &B) {
	return A.ff.ff < B.ff.ff;
}

void solve_cases() 
{
	int n;
	cin >> n;
	vector<pair<pair<int,int>,int>> ranges(n);
	vector<int> X(1500,0);
	int L,R;
	for(int i=0;i<n;i++) {
		cin >> L >> R;
		ranges[i].ff.ff = L;
		ranges[i].ff.ss = R;
		ranges[i].ss = i;
		X[L] += 1;
		X[R] -= 1;
	}
	bool flg = true;
	for(int i=1;i<X.size();i++) {
		X[i] += X[i-1];
		if(X[i] >= 3) {
			flg = false;
			break;
		}
	}
	if(!flg) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	sort(ranges.begin(),ranges.end(),cmp);
	char ans[n];
	
	int pr = 0;
	ans[ranges[0].ss] = 'C';
	for(int i=1;i<n;i++) {
		if(ranges[i].ff.ss <= ranges[pr].ff.ff or ranges[i].ff.ff >= ranges[pr].ff.ss) {
			pr = i;
			ans[ranges[i].ss] = 'C';
		} else 
			ans[ranges[i].ss] = 'J';
	}
	for(int i=0;i<n;i++)
		cout << ans[i];
	cout << endl;
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

