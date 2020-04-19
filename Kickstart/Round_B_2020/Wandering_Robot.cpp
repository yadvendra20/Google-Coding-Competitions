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
double g[310][310];
void solve_cases()
{
	int w,h,l,u,r,d;
	cin >> w >> h >> l >> u >> r >> d;
	for(int i=1;i<=h+1;i++)
		for(int j=1;j<=w+1;j++)
			g[i][j] = 0.0;
	for(int i=h;i>=1;i--) {
		if((i>=u and i<=d) and (w>=l and w<=r)) break;
		g[i][w] = 1.0;
	}
	for(int j=w;j>=1;j--) {
		if((h>=u and h<=d) and (j>=l and j<=r)) break;
		g[h][j] = 1.0;
	}
	for(int i=h-1;i>=1;i--) {
		for(int j=w-1;j>=1;j--) {
			if((i>=u and i<=d) and (j>=l and j<=r)) ;
			else {
				g[i][j] = (g[i+1][j] + g[i][j+1])/2.0;
			}
		}
	}
	/*for(int i=1;i<=h;i++) {
		for(int j=1;j<=w;j++)
			cout << g[i][j] << " ";
		cout << endl;
	}*/
	cout << g[1][1] << endl;
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
