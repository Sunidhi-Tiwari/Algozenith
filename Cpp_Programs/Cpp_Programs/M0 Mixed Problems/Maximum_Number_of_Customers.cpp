#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i = 0; i<n; i++)

void solve()
{   int n;
    cin>>n;
    vector<pair<int,int>> v;
    forloop(i,n)
    {
        int a,d;
        cin>>a>>d;
        v.push_back({a,1});
        v.push_back({d,-1});
    }

    
    
    sort(v.begin(),v.end());
    int cur = 0, max_cus = 0;
    for(auto i:v)
    {
        cur += i.second;
        max_cus = max(max_cus, cur);
    }
    cout<<max_cus<<"\n";
    return;
}

signed main()
{  
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}

