#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
const int M = 1e9 + 7;



void solve()
{   
                              int n,k;
                              cin>>n>>k;
                              int a[n];
                          
                              forn(i,n)
                              {
                              cin>>a[i];
                              }
                              
                              int pre[n+1];
                              memset(pre, 0, sizeof(pre));
                              int cnt = 0;
                              for(int i = 0; i<n-k+1; i++)
                              {
                                                            if(i) pre[i] += pre[i-1];
                                                            
                                                            if( (a[i] == 0 && pre[i]%2 == 0) || (a[i] == 1 && pre[i]%2 == 1))
                                                            {
                                                                                          pre[i] += 1;
                                                                                          pre[i+k] -= 1;
                                                                                          cnt++;
                                                            }
                              }
                              
                              for(int i = n-k+1; i<n; i++)
                              pre[i] += pre[i-1];
                              
                             
                              
                              for(int i = 0; i<n; i++)
                              {
                                                  if( (a[i] == 0 && pre[i]%2 == 0) || (a[i] == 1 && pre[i]%2 == 1))
                                                 { cnt = -1;
                                                  break;
                                                 }
                              }
                              
                              
                              cout<<cnt<<"\n";
                              
                              
                              
    
    return;
}

signed main()
{   IOS
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}


