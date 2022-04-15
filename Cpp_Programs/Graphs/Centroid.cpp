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

int n;
vi ar[200100];
int par[200100];
int subtree[200100];
vi ans;

void centroid(int node, int par)
{                             
                              bool flag = true;
                              
                              for(int child: ar[node])
                              {
                                                            
                              if(child != par && subtree[child]>n/2) 
                              {
                              flag = false;
                              centroid(child, node);
                              
                              }
                              }
                              
                              if(flag)
                              ans.push_back(node);
                              
                              
}


void dfs(int node, int p)
{
                              //par[node] = p;
                              subtree[node] = 1;
                              
                             
                              
                              for(auto child: ar[node])
                              {
                                                            if(child == p) continue;
                                                            dfs(child, node);
                                                            subtree[node] += subtree[child];
                              }
}
void solve()
{   
    int a,b;
    cin>>n;
    
   
    for(int i = 1; i<=n-1; i++)
    cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
    
    dfs(1,-1);
    
    centroid(1,-1);
    
    cout<<*min_element(ans.begin(), ans.end());
   
   
}

signed main()
{   IOS
    /*int t;
    cin>>t;
    while(t--)*/
    solve();
    return 0;
}


