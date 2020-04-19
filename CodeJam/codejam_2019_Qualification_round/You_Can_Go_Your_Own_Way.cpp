#include<iostream>
#include<vector>
typedef long long int ll;

using namespace std;

int main()
{
    ll t,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        ll n;
        string p;
        cin>>n>>p;
        ll i;
        for(i=0;i<p.length();i++)
        {
            if(p[i]=='S')
                p[i]='E';
            else
                p[i]='S';
        }
        cout<<"Case #"<<k<<": "<<p<<endl;
    }
    return 0;
}
