#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

int n;
string s;
string foo(int prevMin,int l,int r) {
	if(l > r or l >= n or r < 0)
		return "";
	int mini = 10,minInd;
	for(int i=l;i<=r;i++) {
		if(s[i]-'0' < mini) {
			mini = s[i]-'0';
			minInd = i;
		}
	}
	string pref = "",suff = "";
	for(int i=0;i < mini - prevMin;i++)
		pref.pb('('),suff.pb(')');
	return pref + foo(mini,l,minInd-1) + to_string(mini) +  foo(mini,minInd+1,r) + suff;
}

void solve_cases() 
{
	cin >> s;
	n = s.length();
	cout << foo(0,0,n-1) << endl;
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

