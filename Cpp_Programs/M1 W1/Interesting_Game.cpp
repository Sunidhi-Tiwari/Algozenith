#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 

void solve()
{   
    int n;
    cin>>n;
    
    vector<int> alice(n);
    vector<int> bob(n);
    
    forn(i,n)
    cin>>alice[i];
    
    int sum, sa = 0, sb = 0;
    priority_queue<pair<int,int>> pq;
    
    forn(i,n)
    {
        cin>>bob[i];
        sum = alice[i] + bob[i];
        pq.push(make_pair(sum, i));
    }
    int i = 0;
    while(!pq.empty())
    {
        if(i%2 == 0)
        {
            auto it = pq.top();
            sa += alice[it.second];
            pq.pop();
            
        }
        else
        {
            auto it = pq.top();
            sb += bob[it.second];
            pq.pop();
        }
        i++;
    }
    
    if(sa>sb) cout<<"Alice"<<"\n";
    else if(sa<sb) cout<<"Bob"<<"\n";
    else cout<<"Tie"<<"\n";
    
    
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
