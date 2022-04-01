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
bool vis[100001];
int size[100001];
int id[100001];
int cc = 1;

void dfs(int node)
{
                              if(vis[node]) return;
                              
                              vis[node] = true;
                              id[node] = cc;
                              size[cc]++;
                              
                              for(auto child: ar[node])
                              dfs(child);
}

void solve()
{   
    int n,m,q,a,b;
    cin>>n>>m>>q;
    
   
    for(int i = 1; i<=m; i++)
    cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
    
    for(int i = 1; i<=n; i++)
    {
                                  if(!vis[i])
                                  dfs(i), cc++;
    }
    
    
    
    while(q--)
    {
                                  int t;
                                  cin>>t;
                                  
                                  if(t==1)
                                  {
                                                                int x;
                                                                cin>>x;
                                                                cout<<size[id[x]]<<"\n";
                                  }
                                  
                                  if(t==2)
                                  {
                                                                int x,y;
                                                                cin>>x>>y;
                                                                if(id[x]==id[y])
                                                                cout<<"YES\n";
                                                                else
                                                                cout<<"NO\n";
                                  }
    }
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


