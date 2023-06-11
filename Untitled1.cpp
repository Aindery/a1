#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
ll res;
ll a[(int)1e6+10];
int main()
{
    ll n,m;
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    ll temp=0;
    if(ans%m!=0) cout<<-1;
    else
    {
        ll val=ans/m;
        for(int i=1; i<=n; i++)
        {
            if(a[i]==val) continue;
            if(a[i]>val)
            {
                if(a[i]%val!=0)
                {
                    res+=a[i]/val;
                    temp=a[i]%val;
                    a[i+1]+=temp;
                    res++;
                }
                if(a[i]%val==0)
                {
                    res+=a[i]/val-1;
                }
            }
            else
            {
                a[i+1]+=a[i];
                res++;
            }
        }
        cout<<res;
    }
}
