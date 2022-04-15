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

vi ar[200100];
int par[200100];
int depth[200100];




void dfs(int node, int p, int dep)
{
                              par[node] = p;
                              depth[node] = dep;
                              
                             
                              
                              for(auto child: ar[node])
                              {
                                                            if(child == p) continue;
                                                            dfs(child, node, dep+1);
                              }
}
void solve()
{   
    int n,a,b;
    cin>>n;
    
   
    for(int i = 1; i<=n-1; i++)
    cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
    
    
    dfs(1,0,0);
    int temp = 1;
    for(int i = 2; i<=n; i++)
    {                   
                                  if(depth[i]>depth[temp])
                                  temp = i;
                                  
                                  
    }
    
    int start = temp;
    
    dfs(temp, 0, 0);
    int max = 0;
    for( int i = 1; i<=n; i++)
    {
                                  if(depth[i] > max)
                                  max = depth[i];
    }
    
    cout<<max<<"\n";
   
}

signed main()
{   IOS
    /*int t;
    cin>>t;
    while(t--)*/
    solve();
    return 0;
}


