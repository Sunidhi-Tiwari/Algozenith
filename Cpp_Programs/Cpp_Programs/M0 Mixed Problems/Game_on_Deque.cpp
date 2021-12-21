#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{   
    int n,q;
    cin>>n>>q;
    int maxe = 0;
    deque<int> dq;
    forloop(i,n)
    {
        int ele;
        cin>>ele;
        dq.push_back(ele);
        maxe = max(ele, maxe);
    }
    
    vector<pair<int, int>> v;
    v.push_back({0,0});
    while(dq.front()!= maxe)
    {
        int f = dq.front();
        dq.pop_front();
        int s =  dq.front();
        dq.pop_front();
        dq.push_back(min(f,s));
        dq.push_front(max(f,s));
        v.push_back({f,s});
    }
    
    dq.pop_front();
    
    while(q--)
    {
        int x;
        cin>>x;
        
        if(x<v.size())
        cout<<v[x].first<<" "<<v[x].second<<"\n";
        else
        {
            cout<<maxe<<" "<<dq[(x-v.size())%(n-1)]<<"\n";
        }
    }
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
