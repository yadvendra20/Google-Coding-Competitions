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
        cin>>n;
        ll no=n;
        vector<ll>anNo;
        while(no)
        {
            ll rem = no%10;
            if(rem==4)
                anNo.push_back(3);
            else
                anNo.push_back(rem);
                
            no/=10;
        }
        ll i,no_2=0;
        for(i=anNo.size()-1;i>=0;i--)
            no_2=(no_2*10)+anNo[i];
        cout<<"Case #"<<k<<": "<<no_2<<" "<<(n-no_2)<<endl;
    }
    return 0;
}
