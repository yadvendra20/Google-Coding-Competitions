#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,k = 1;
    cin>>t;
    while(k <= t)
    {
        int n,m,q;
        cin>>n>>m>>q;
        int p[m],r[q];
        for(int i=0;i<m;i++)
            cin>>p[i];
        for(int i=0;i<q;i++)
            cin>>r[i];
        
        map<int,int> mp;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=sqrt(p[i]);j++)
            {
                if(p[i]%j == 0)
                {
                    if(p[i]/j == j)
                        mp[j]++;
                    else
                    {
                        mp[p[i]/j]++;
                        mp[j]++;
                    }
                }
            }
        }
        
        int sum = 0;
        for(int i=0;i<q;i++)
            sum += n/r[i] - mp[r[i]];
        
        cout<<"Case #"<<k<<": "<<sum<<"\n";
        
        k++;   
    }
    return 0;
}
