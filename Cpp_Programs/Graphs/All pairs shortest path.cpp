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
const int N = 501;

int arr[N][N];
int dist[N][N];

void solve()
{   
    int n;
    cin>>n;
 
    
    for(int i = 1; i<=n; i++)
     for(int j = 1; j<=n; j++)
     cin>>dist[i][j];
     
     vi order(n);
     for(int i = 0; i<n; i++)
     cin>>order[i];
     
     reverse(order.begin(), order.end());
     
     vi ans;
     
     for(int k = 0; k<n; k++)
     {
                                   int node = order[k];
                                   
                                   
                                   for(int i = 1; i<=n; i++)
                                   {
                                   for(int j = 1; j<=n; j++)
                                   {
                                                                 dist[i][j] = min (dist[i][j] , dist[i][node] + dist[node][j]);
                                   }
                                   
                                   
                                   }
                                   
                                   int sum = 0;
                                   
                                   for(int i = 0; i<=k; i++)
                                   {
                                                                 for(int j = 0; j<=k; j++)
                                                                 {
                                                                                               sum += dist[order[i]][order[j]];
                                                                 }
                                   }
                                   
                                   ans.pb(sum);
     }
     
     reverse(ans.begin(), ans.end());
     
     for(auto i: ans)
     cout<<i<<" ";
    
   
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


