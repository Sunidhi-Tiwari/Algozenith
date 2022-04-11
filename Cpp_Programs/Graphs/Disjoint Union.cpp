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

int n,q;
int parent[10001];
int dep[10001];

void makeset(int n)

{
                              for(int i = 0; i<n; i++)
                              parent[i] = i;
                             
}

int findparent(int node)
{
                              if(parent[node] == node)
                              return node;
                              
                              return parent[node] = findparent(parent[node]);
}

void unite(int x, int y)
{                             
                              int u = findparent(x);
                              int v = findparent(y);
                              
                              if(dep[u]<dep[v])
                              parent[u] = v;
                              else if(dep[u]>dep[v])
                              parent[v] = u;
                              else
                              {
                              parent[u] = v; dep[v]++;}
}

void solve()
{   
    
    cin>>n>>q;
    makeset(n);
    
    while(q--)
    {
                                  int com;
                                  
                                  cin>>com;
                                  
                                  if(com == 0)
                                  {
                                                                int x,y;
                                                                cin>>x>>y;
                                                                unite(x,y);
                                  }
                                  else 
                                  {
                                                                 int x,y;
                                                                 cin>>x>>y;
                                                                 
                                                                 if(findparent(x) == findparent(y))
                                                                 cout<<"1\n";
                                                                 else
                                                                 cout<<"0\n";
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


