#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ff first 
#define ss second 


bool comp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b)
{
                              return a.ff.ff*b.ff.ss > b.ff.ff*a.ff.ss; 
}

void solve()
{   
    int n;
    cin>>n;
    vector<pair<pair<int,int>, string>> v;
    
    for(int i = 0; i<n; i++)
    {
                           string s;
                           cin>>s;
                           int ones = 0;
                           int zeros = 0;
                           for(char c: s)
                           {
                           if(c == '1') ones++ ;
                           else zeros++;
                                                         
                           }
                           v.push_back({{zeros,ones},s});
                                       
     }
    
    sort(v.begin(), v.end(), comp);
    
    string st = " ";
    
    for(auto i : v)
    st += i.ss;
    
    int zeros = 0;
    int sum = 0;
    int l = (int)st.length();
    for(int i = l-1; i>=0; i--)
    {
                                  if(st[i] == '1')
                                  sum += zeros;
                                  else
                                  zeros++;
    } 
    
    cout<<sum<<"\n";
    
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