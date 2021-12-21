#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)
        
void solve()
{   
    int n;
    cin>>n;
    multiset<int> st;
    int cost = 0;
    forloop(i,n)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    
    while(st.size() != 1)
    {
        int num1 = *(st.begin());
        st.erase(st.begin());
        int num2 = *(st.begin());
        st.erase(st.begin());
        
        cost += num1+num2;
        st.insert(num1+num2);
    }
    
    cout << cost<<"\n";
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