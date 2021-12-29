

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
const int M = 1e9 + 7;

int binexp(int x, int y, int mod)
{
    int res = 1;
    x = x%mod;
    
    if(x == 0) return 0;
    
    while(y>0)
    {
        if (y%2)
        res = (res*x) % mod;
        y = y/2;
        x = (x*x)%mod;
    }
    return res;
}


void solve()
{   int t;
    cin>>t;
    
    
    vector<int> fact(2*10e5 + 1);
    int size = 2*1e5 + 1;
    fact[0] = 1;
    for(int i = 1; i<size; i++)
    fact[i] = ((i%M)*(fact[i-1]%M))%M;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
    int ans = (((fact[n+m])%M * binexp(fact[n],M-2,M))%M * binexp(fact[m],M-2,M)) % M;
    cout<<ans<<"\n";
    }
    return;
}

signed main()
{   IOS
   
    solve();
    
    return 0;
}