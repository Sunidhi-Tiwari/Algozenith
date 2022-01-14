// consecutive one, two pointers


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
const int M = 1e9 + 7;



void solve()
{   
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n; i++)
    cin>>arr[i];
    
    int head = -1;
    int tail = 0;
    int cntzero = 0;
    int ans = 0;
    while(tail<n)
    {   // while there is a next element to take and we will not violate any con dition
    
       // ((arr[head+1]==0) + cntzero<=k)
    
        while(head+1<n && ((arr[head+1] == 1 && cntzero <= k )|| (arr[head+1] == 0 && cntzero<k)))
        {
        head++;
        if(arr[head] == 0) cntzero++;
        }
        // for debug;
        //cout<<tail<<" "head<<endl;
        //  update the answer accordingly
        
        ans = max(ans,head-tail+1);
        
        // move tail ahead and remove the last element's contribution
        
        if(head>=tail)
        {
            if(arr[tail]==0) cntzero--;
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout<<ans<<endl;
    
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


