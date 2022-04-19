#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
#define vi vector<int>
const int M = 1e9 + 7;

//vi ar[100001];
//int vis[100001];

int n,q;
int arr[200200];
int t[800800];

void build(int index, int l, int r)
{
                              if(l==r)
                              {
                                                            t[index] = arr[l];
                                                            return;
                              }
                              
                              int mid = (l+r)/2;
                              build(index*2, l, mid);
                              build(index*2+1, mid+1, r);
                              
                              t[index] = t[2*index] + t[2*index+1];

}

void update(int index, int l, int r, int pos, int val)
{
                              if(pos<l || pos>r) return;
                              if( l == r)
                              {
                                                            t[index] = val;
                                                            arr[l] = val;
                                                            return;
                              }
                              
                              int mid = (l+r)/2;
                              
                              update(index*2,l, mid, pos, val);
                              update(index*2+1, mid+1, r, pos, val);
                              
                              t[index] = t[2*index] + t[2*index+1];
                              
                              
}

int query(int index, int l, int r, int lq, int rq)
{
                              if(l>rq || lq>r) return 0;
                              
                              if(lq<=l && rq>=r) // lq <= l <= r <= rq
                              return t[index];
                              
                              int mid = (l+r)/2;
                              
                              return query(2*index, l, mid, lq, rq) + query(2*index+1, mid+1, r, lq, rq);
}

void solve()
{   
   cin>>n>>q;
   for(int i = 0; i<n; i++)
   cin>>arr[i];
   
   build(1,0,n-1);
   
  
   
   for(int i = 0; i<q; i++)
   {
                                int ch;
                                cin>>ch;
                                
                                if(ch == 1)
                                {
                                                              int x,v;
                                                              cin>>x>>v;
                                                              update(1,0,n-1,x-1,v);
                                }
                                else
                                {
                                                              int l,r;
                                                              cin>>l>>r;
                                                              cout<<query(1,0,n-1,l-1,r-1)<<"\n";
                                }
   }
   
}

signed main()
{   IOS
    /*int t;
    cin>>t;
    while(t--)*/
    solve();
    return 0;
}