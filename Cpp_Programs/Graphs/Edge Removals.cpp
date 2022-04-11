
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
#define vi vector<int>
const int M = 1e9 + 7;

int n,m,q;
int cc;
vector<pair<int,int>> edge;
map<int,int> mp;
stack<int> st;
int par[100001];
int dep[100001];
vector<int> ans;

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
                              {
                                        par[u] = v;                    
                              }
                              
                              else if(dep[u] > dep[v])
                              {
                                          par[v] = u;
                                          
                              }
                              
                              else
                              { 
                                                            par[u] = v;
                                                            
                                                            dep[v]++;

                                                            
                              }
                              
                              cc--;
                              
                              return;
}


void solve()
{   
    cin>>n>>m>>q;
    cc = n;
    
    edge.resize(m+1);
    
    
    for(int i = 1; i<=n; i++)
    par[i] = i;
    
    for(int i = 1; i<=m; i++)
    {
                                  int a,b;
                                  cin>>a>>b;
                                  edge[i] = {a,b};
    }
    
    
    while(q--)
    {
                                  int op;
                                  cin>>op;
                                  if(op == 2)
                                  {st.push(-1);
                                  }
                                  else
                                  {
                                      int idx;
                                      cin>>idx;
                                      mp[idx] = -1;
                                      st.push(idx);
                                  }
    }
    
    for(int i = 1; i<=m; i++)
    {
                                  if(mp[i] != -1)
                                  {
                                    if(findpar(edge[i].ff) != findpar(edge[i].ss))
                                    unite(edge[i].ff,edge[i].ss);
                                  }
    }
    
    
    while(!st.empty())
    {
                                  if(st.top() == -1)
                                 { ans.pb(cc);
                                   st.pop();
                                 }
                                  else
                                  {
                                                                int i = st.top();
                                                                st.pop();
                                                                
                                                                if(findpar(edge[i].ff) != findpar(edge[i].ss))
                                                                unite(edge[i].ff, edge[i].ss);
                                  }
    }
    
    reverse(ans.begin(), ans.end());
    
    for(auto i : ans)
    cout<<i<<"\n";
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


