#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
const int M = 1e9 + 7;

bool comp(pair<int, int> a, pair<int, int> b)
{
                              return a.ss - a.ff < b.ss - b.ff;
}

void solve()
{   
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    
    for(int i = 0; i<n; i++)
    {
                                  int x,y;
                                  cin>>x>>y;
                                  v[i].ff = x;
                                  v[i].ss = y;
    }
    
    sort(v.begin(), v.end(), comp);
    
    int sum = v[0].ff;
    for(int i = 1; i<n; i++)
    {
             sum += (v[i].ff - (v[i-1].ff - v[i-1].ss));               
    }
    
    cout<<sum<<"\n";
    
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