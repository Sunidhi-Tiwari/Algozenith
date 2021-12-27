#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)
#define pb push_back

void solve()
{   
    int n;
    cin>>n;
    int s = pow(2,n);
    int a[s];
    multiset<int> ms;
    forloop(i,s)
    {   int x;
        cin>>x;
        ms.insert(x);
    }
    
    vector<int> sum;
    sum.pb(*ms.begin());
    ms.erase(ms.find(*ms.begin()));
    
    while(!ms.empty())
    {
        int x = *ms.begin();
        cout<<x<<" ";
        
        int y = sum.size();
        
        for(int i = 0; i<y; i++)
        {
            int z = sum[i] + x;
            sum.pb(z);
            if(ms.find(z) != ms.end())
            ms.erase(ms.find(z));
            
        }
    }
    
    cout <<"\n";
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
