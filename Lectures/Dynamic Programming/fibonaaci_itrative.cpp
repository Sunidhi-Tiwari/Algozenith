#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
const int M = 1e9 + 7;



void solve()
{   
    int n;
    cin>>n;
    int dp[n+1];
    dp[0] = 0; dp[1] = 1; 
    
    for(int i = 2; i<=n; i++)
    dp[i] = dp[i-1] + dp[i-2];
    
    cout<<dp[n]<<"\n";
    
    return;
}

signed main()
{   IOS
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}


