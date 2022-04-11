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

int n,m;
vi par;
vi dep;
int num,ans;
vector<pair<pair<int,int>, int>> edge;

bool comp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b)
{
                   return a.second < b.second;           
}

int findpar(int node)
{
                              if(par[node] == node)
                              return node;
                              
                              return par[node] = findpar(par[node]);
}

void unite(int x, int y)
{
                              int u = findpar(x);
                              int v = findpar(y);
                              
                              if(dep[u] < dep[v])
                              {par[u] = v;}
                              else if(dep[u] > dep[v])
                              {par[v] = u;}
                              else
                              {
                                                            par[u] = v;
                                                            dep[v]++;
                                                            
                              }
}

void solve()
{   
        cin>>n>>m;
        
        par.resize(n+1);
        dep.assign(n+1,0);
        
        for(int i = 1; i<=n; i++)
        par[i] = i;
        
        for(int i = 1; i<=m; i++)
        {
                                      int a,b,c;
                                      cin>>a>>b>>c;
                                      edge.push_back({{a,b},c});
                                      
        }
        
        sort(edge.begin(), edge.end(), comp);
        
        for(auto cur: edge)
        {
                                      int a = cur.ff.ff;
                                      int b = cur.ff.ss;
                                      int c = cur.ss;
                                      
                                      if(findpar(a) != findpar(b))
                                      {
                                                                    unite(a,b);
                                                                    num++;
                                                                    ans+= c;
                                      }
        }
        
        if(num == n-1) cout<<ans<<"\n";
        else
        cout<<"IMPOSSIBLE\n";
   
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


