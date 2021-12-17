#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        cin>>v[i];
    }
    vector<int> left(n);
    vector<int> right(n);
    int maxl = 0, maxr =0;
    
    for(int i = 0; i<n; i++)
    {   maxl = max(maxl,v[i]);
        left[i] = maxl;
        maxr = max(maxr, v[n-i-1]);
        right[n-i-1] = maxr;
    }
    
    for(int i = 0; i<n; i++)
    {
        count += (min(left[i], right[i]) - v[i]);
    }
    cout<<count<<"\n";
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


