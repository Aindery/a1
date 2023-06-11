#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,ave;
vector<ll>a;
void kk(ll i)
{
    if(a[i]%ave==0) ans+=a[i]/ave-1;
    else ans+=a[i]/ave;
    ll diff=a[i]%ave;
    a[i+1]+=diff;
    if(diff!=0)ans++;
}
void kj(ll i)
{

    ans++;
    a[i+1]+=a[i];
}

void solve()
{
    ll n, m, sum = 0;
    cin >> n >> m;
    ll ma = max(n, m);
    a.resize(ma+2);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % m != 0)
    {
        cout << -1;
    }
    else
    {
        ave = sum / m;
        ll i=0,ms=max(n,m);
        while (i <= ms)
        {
            i++;
            if (a[i]<=0) continue;
            if(a[i] > ave) kk(i);
            else if (a[i] < ave)kj(i);
        }
        cout << ans;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }
    return 0;
}
