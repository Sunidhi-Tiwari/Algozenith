
        
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{   string s;
    cin>>s;
    
    set<pair<pair<int,int>,pair<int,int>>> st;
    
    int x = 0, y = 0, ans = 0; 
    
    pair<int,int> initial;
    pair<int,int> final;
    int n = s.length();
    forloop(i,n)
    {   
        initial = {x,y};
        pair<pair<int,int>,pair<int,int>> path1;
        pair<pair<int,int>,pair<int,int>> path2;
        
        char c = s[i];
        if(c == 'N')
        y = y+1;
        else if(c =='S')
        y = y-1;
        else if(c == 'E')
        x = x+1;
        else if(c == 'W')
        x = x-1;
        
        final = {x,y};
        
        path1 = {initial,final};
        path2 = {final,initial};
        
        if(st.find(path1) != st.end())
        ans+=1;
        else
        {   
            ans += 5;
            st.insert(path1);
            st.insert(path2);
        
        }
       
        
    }
    
    cout << ans <<"\n";
    
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