#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
#define vi vector<int>
const int M = 1e9 + 7;

//vi ar[100001];
//int vis[100001];


void solve()
{   
    int n,m,a,b;
    cin>>n>>m;
    
    vi ar[n+1];
    vi indeg(n+1,0);
   
    for(int i = 1; i<=m; i++)
    {cin>>a>>b;
    ar[a].pb(b);
    indeg[b]++;                             
    }
    
    queue<int> q;
    
    for(int i = 1; i<=n; i++)
    if(indeg[i] == 0) q.push(i);
    
    vi v;
    while(!q.empty())
    {
          int node = q.front();
          q.pop();
          
          v.pb(node);
          
          for(auto child: ar[node])
          {
          indeg[child]--;
          if(indeg[child] == 0) q.push(child);
          }
          
      }
    
    vi dp(n+1,0);
    dp[1] = 1;
    
    for(auto cur: v)
    {
           for(auto child: ar[cur])
           {
           dp[child] += dp[cur];
           dp[child] %= M;
           }
    }
    
    cout<<dp[n];
   
    return;
}

signed main()
{   IOS
    /*int t;
    cin>>t;
    while(t--)*/
    solve();
    return 0;
}


