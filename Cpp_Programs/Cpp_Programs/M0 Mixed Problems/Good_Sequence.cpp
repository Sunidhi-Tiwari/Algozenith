
        
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{   
    int n;
    cin>>n;
    map<int,int> mp;
    int count = 0;
    forloop(i,n)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    for(auto i: mp)
    {
        if(i.first > i.second)
        {
            count += i.second;
        }
        else if(i.first < i.second)
        {
            count += i.second - i.first;
        }
    }
    cout<<count<<"\n";
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