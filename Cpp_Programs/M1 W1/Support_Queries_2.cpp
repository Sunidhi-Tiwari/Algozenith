#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{   int q;
    cin>>q;
    int k;
    cin>>k;
    int sum = 0;
      multiset<int> ms1, ms2;
    
    while(q--)
    {
    int n;
    cin>>n;
  
    
    if(n==1)
    {
        int x;
        cin>>x;
        
        ms1.insert(x);
        sum += x;
        if((int)ms1.size() > k)
        {   
            int y = *ms1.begin();
            ms1.erase(ms1.find(y));
            sum -= y;
            ms2.insert(y);
        }
        
    }
    
    else if(n==2)
    {
        int x;
        cin>>x;
        
        if(ms2.find(x) != ms2.end())
        ms2.erase(ms2.find(x));
        
        else if(ms1.find(x) != ms1.end())
        {
            ms1.erase(ms1.find(x));
            sum -= x;
            if(!ms2.empty())
            {   
                int y = *ms2.rbegin();
                ms1.insert(y);
                sum += y;
                ms2.erase(ms2.find(y));
            }
        }
    }
    
    else if(n==3)
    {
        char c;
        cin>>c;
        
        cout<<sum<<"\n";
    }
    }
    return;
}

signed main()
{   IOS
    
        solve();
    
    
    return 0;
}