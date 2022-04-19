#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
#define vi vector<int>
const int M = 1e9 + 7;

int n,q;
int arr[200200];


struct node 
{
                              int odd;
                              int even;
                              node(int o =0, int e = 0)
                              {
                                                             odd = o;
                                                             even = e;

                              }
};

node t[800800];

node merge(node a, node b)
{
                             /* if(a.mini == b.mini)
                              return node(a.mini, a.cnt + b.cnt);
                              else if(a.mini < b.mini)
                              return a;
                              else return b; */
                              
                              return node(a.odd + b.odd, a.even + b.even);

}
void build(int index, int l, int r)
{
                              if(l==r)
                              {                             
                                                            if(arr[l]%2)
                                                            t[index] = node(1,0);
                                                            else
                                                            t[index] = node(0,1);
                                                            return;
                              }
                              
                              int mid = (l+r)/2;
                              build(index*2, l, mid);
                              build(index*2+1, mid+1, r);
                              
                              t[index] = merge(t[2*index],t[2*index+1]);

}

void update(int index, int l, int r, int pos, int val)
{
                              if(pos<l || pos>r) return;
                              if( l == r)
                              {                             
                                                            
                                                           // t[index] = node(val,1);
                                                            
                                                            if(val%2)
                                                            t[index] = node(1,0);
                                                            else
                                                            t[index] = node(0,1);
                                                            
                                                            arr[l] = val;
                                                            return;
                              }
                              
                              int mid = (l+r)/2;
                              
                              update(index*2,l, mid, pos, val);
                              update(index*2+1, mid+1, r, pos, val);
                              
                              t[index] = merge(t[2*index],t[2*index+1]);
                              
                              
}

node query(int index, int l, int r, int lq, int rq)
{
                              if(l>rq || lq>r) return 0;
                              
                              if(lq<=l && rq>=r) // lq <= l <= r <= rq
                              return t[index];
                              
                              int mid = (l+r)/2;
                              
                              return merge(query(2*index, l, mid, lq, rq),query(2*index+1, mid+1, r, lq, rq));
}

void solve()
{   
   cin>>n;
   for(int i = 0; i<n; i++)
   cin>>arr[i];
   cin>>q;
   build(1,0,n-1);
   
  
   
   for(int i = 0; i<q; i++)
   {
                                int ch;
                                cin>>ch;
                                
                                if(ch == 0)
                                {
                                                              int x,y;
                                                              cin>>x>>y;
                                                              update(1,0,n-1,x-1,y);
                                }
                                else
                                {
                                                              int l,r;
                                                              cin>>l>>r;
                                                              node x = query(1,0,n-1,l-1,r-1);
                                                              if(ch == 1)
                                                              cout<<x.even<<"\n";
                                                              else
                                                              cout<<x.odd<<"\n";
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


