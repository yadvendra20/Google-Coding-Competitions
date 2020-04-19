#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t,k = 1;
    cin>>t;
    while(k <= t)
    {
        ll n,m;
        cin>>n>>m;
        
        ll A[n],ans;
        for(ll i=0;i<n;i++)
            cin>>A[i];
        ll i;
        for(i=1000;i>=0;i--)
        {
            ll xr = 0;
            for(ll j=0;j<n;j++)
                xr += (A[j] ^ i);
            if(xr <= m)
                break;
        }
        if(i < 0)
            ans = -1;
        else
            ans = i;
        cout<<"Case #"<<k<<": "<<ans<<"\n";
        k++;
    }
}