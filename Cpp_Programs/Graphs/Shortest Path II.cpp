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



void solve()
{   
    int n,m,q;
    cin>>n>>m>>q;
    
    int ar[n][n];
    
    for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
    {
     if(i == j) ar[i][j] = 0;
     else
     ar[i][j] = 1e18;
    }
    
    for(int i = 0; i<m; i++)
    {
                                  int a,b,c;
                                  cin>>a>>b>>c;
                                  if(a==b) continue;
                                  ar[a-1][b-1] = ar[b-1][a-1] = min(ar[a-1][b-1], 1ll*c);
                                   
    }
    
    for(int k = 0; k<n; k++)
    {
                                  for(int i = 0; i<n; i++)
                                  {
                                                             for(int j = 0; j<n; j++)
                                                             {
                                                                                           ar[i][j] = min(ar[i][j] , ar[i][k] + ar[k][j]);
                                                             }
                                  }
    }
   
    
    while(q--)
    {
                                  int a,b;
                                  cin>>a>>b;
                                  if(ar[a-1][b-1] == 1e18)
                                  cout<<"-1\n";
                                  else
                                  cout<<ar[a-1][b-1]<<"\n";
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


