#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl "\n"
using namespace std;

const int N = 1e5+5;
const int mod = 1e9;

void solve_cases()
{
	string s;
	cin >> s;
	stack<int> st;
	st.push(1);
	int S=0,N=0,W=0,E=0;
	for(int i=0;i<s.length();i++) {
		if(s[i] == '(');
		else if(s[i] >= '0' and s[i] <= '9')
			st.push((st.top()%mod * (s[i]-'0')%mod)%mod);
		else if(s[i] == ')')
			st.pop();
		else if(s[i] == 'S')
			S = (S%mod + st.top()%mod)%mod;
		else if(s[i] == 'N')
			N = (N%mod + st.top()%mod)%mod;
		else if(s[i] == 'W')
			W = (W%mod + st.top()%mod)%mod;
		else
			E = (E%mod + st.top()%mod)%mod;
	}
	int resR = (E - W),resC = (S - N);
	if(resR <= 0) resR += mod;
	if(resC <= 0) resC += mod;
	resR %= mod;
	resC %= mod;
	cout << resR+1 << " " << resC+1 << endl;
 	return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1,i = 1;
	cin >> T;
    while(T--) 
    {
        cout << "Case #" << i << ": ";
        solve_cases();
        i++;
    }
    return 0;
}
