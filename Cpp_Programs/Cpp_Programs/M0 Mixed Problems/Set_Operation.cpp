#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{   
    int n,m;
    cin>>n>>m;
    set<int> U,I,D;
    forloop(i,n)
    {
        int x;
        cin>>x;
        U.insert(x);
        D.insert(x);
        
    }
   
    forloop(i,m)
    {
        
        int x;
        cin>>x;
        if(U.find(x) != U.end())
        {
            I.insert(x);
            D.erase(x);
        }
        U.insert(x);
        
    }
    
    
    for (auto i: U)
    cout<<i<<" ";
    cout<<"\n";
    for (auto i: I)
    cout<<i<<" ";
    cout<<"\n";
    for (auto i: D)
    cout<<i<<" ";
    cout<<"\n";
    
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


