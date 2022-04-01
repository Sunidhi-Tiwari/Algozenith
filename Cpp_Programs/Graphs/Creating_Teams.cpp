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

vi ar[100001];
int vis[100001];
int col[100001];

bool dfs(int node, int c)
{
                              vis[node] = 1;
                              col[node] = c;
                              
                              for(auto child: ar[node])
                              {
                                                            if(!vis[child])
                                                            {
                                                                                          if(!dfs(child, c^1))
                                                                                          return false;
                                                            }
                                                            
                                                            if(col[child] == col[node])
                                                            return false;
                              
                              }
                              
                              return true;
}


void solve()
{   
    int n,m,a,b;
    cin>>n>>m;
    
   
    for(int i = 1; i<=m; i++)
    cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
    
    bool flag = true;
    
    for(int i = 1; i<=n; i++)
    {
                                  if(!vis[i])
                                  if(!dfs(i,0))
                                  flag = false;
    }
    
    if(flag)
    cout<<"YES";
    else
    cout<<"NO";
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


