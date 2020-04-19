#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

const int maxs = 1e5+10;
const int mod = 1e9+7;

int n,k;
int nums[maxs];

int isPoss(int dopt) {
	int kTot = 0;
	for(int i=1;i<n;i++) {
		kTot += (int)ceil((nums[i] - nums[i-1])/(double)dopt) - 1;
		if(kTot > k)
			return 0;
	}
	return 1;
}

void solve_cases() {
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> nums[i];
	int lo = 1,hi = (int)1e9;
	while(lo <= hi) {
		int mid = (lo+hi)/2;
		if(isPoss(mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout << lo << endl;
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

