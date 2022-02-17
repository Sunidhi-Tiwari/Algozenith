#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
const int M = 1e9 + 7;
const int N = 1000001;

int dp[N];

int fib(int n)
{
                              if(n<=0)
                              return 0;
                              if(n == 1 || n==2)
                              return 1;
                              
                              if(dp[n] != -1)
                              return dp[n];
                              
                              dp[n] = fib(n-1) + fib(n-2);
                              
                              return dp[n];
}

signed main()
{   IOS
    
    memset(dp, -1, sizeof(dp));
    
    int n;
    cin>>n;
    cout<<fib(n)<<"\n";
    return 0;
}


