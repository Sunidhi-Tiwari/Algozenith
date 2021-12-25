#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{   
    int n,m;
    cin>>n>>m;
    if(n==0)
    {
    cout<<"0\n";
    return;
    }
    vector<int> v(n);
    forloop(i,n)
    cin>>v[i];
    sort(v.begin(),v.end());
    int cost = v[0], total = 0, i = 1;
    
    while(cost<=m && i<n)
    {
        cost += v[i];
        total++;
        i++;
    }
    
    if(cost>m)
    cout<<total<<"\n";
    else
    cout<<total+1<<"\n";
    
    return;
}

signed main()
{   IOS
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}

