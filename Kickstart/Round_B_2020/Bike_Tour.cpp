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

void solve_cases()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	int peaks = 0;
	for(int i=1;i<n-1;i++)
		if(a[i] > a[i-1] and a[i] > a[i+1])
			peaks++;
	cout << peaks << endl;
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
