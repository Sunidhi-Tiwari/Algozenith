#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forloop(i,n) for(int i=0;i<n;i++)

void solve()
{   
    int n;
    cin>>n;
    int heights[n];
    forloop(i,n)
    cin>>heights[i];
    
    stack<int> st;
    
   int left[n];
   int right[n];
    
    for(int i = 0; i<n; i++)
    {
        while(!st.empty() && heights[st.top()]>= heights[i])
        st.pop();
        
        if(st.empty()) left[i] = -1;
        else left[i] = st.top();
        
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for(int i = n-1; i>=0; i--)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
        
        if(st.empty()) right[i] = n;
        else right[i] = st.top();
        
        st.push(i);
    }
    
    int area = 0;
    forloop(i,n)
    {
        area = max(area, (heights[i]*(right[i] - left[i] - 1)));
    }
    
    cout<<area<<"\n";
    return;
}

signed main()
{   IOS
        int t;
        cin>>t;
        while(t--)
        solve();
    
    
    return 0;
}