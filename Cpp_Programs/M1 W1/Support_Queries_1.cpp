#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{  
    multiset<int> ms;
    int q;
    cin>>q;
    int sum = 0;
    
    while(q--)
    {
     int n;
     cin>>n;
    
    
    if(n==1)
    {
        int x;
        cin>>x;
        ms.insert(x);
        sum += x;
    
    }
    else if(n==2)
    {
        int x;
        cin>>x;
        if(ms.find(x) != ms.end())
        {   
            sum = sum - x;
            ms.erase(ms.find(x));
        }
    }
    
    else if(n == 3)
    {
        char c;
        cin>>c;
        if(ms.empty())
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<(*ms.begin())<<"\n";
        }
    }
    else if(n == 4)
    {
        char c;
        cin>>c;
        if(ms.empty())
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<*(--ms.end())<<"\n";
        }
    }
    else if(n == 5)
    {
        char c;
        cin>>c;
        if(ms.empty())
        {
            cout<<"0\n";
        }
        else
        {
            cout<<sum<<"\n";
        }
    }
   
    }
    
    return;
}

signed main()
{   IOS
    solve();
    
    return 0;
}

