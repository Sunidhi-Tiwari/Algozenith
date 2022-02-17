#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define en '\n' 
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

//typedef vector < ll > vi;


#define all(x) x.begin(),x.end()
#define present(c, key)(find(all(c), key) != c.end())
#define tr(c, it) for (auto it:c)
#define fr(i, s, e) for(ll i = s; i < e; i++)
#define revfr(i, s, e) for(ll i = s - 1; i >= e; i--)
#define getv(v, n) for(ll i = 0; i < n; i++) cin >> v[i];

template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {

  for(auto element : v) {
    os << element <<' ';
  }

  return os;
}
inline void add(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

inline void sub(ll &a, ll b) {
    a -= b;
    if (a < 0) a += mod;
}

inline ll mul(ll a, ll b) {
    return (ll) ((long long) a * b % mod);
}

inline ll power(ll a, long long b) {
    ll res = 1;
    while (b > 0) {
    if (b & 1) {
    res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
    }
    return res;
}

inline ll inv(ll a) {
    a %= mod;
    if (a < 0) a += mod;
    ll b = mod, u = 0, v = 1;
    while (a) {
        ll t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    if (u < 0) u += mod;
    return u;
}
void solve()
{
    ll n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++)
    cin>>v[i];
    
    vector<int> a(n,1), b(n,1);
    
    for(int i = 1; i<n; i++)
    if(v[i]>v[i-1]) a[i] = a[i-1] + 1;
    
    for(int i = n-2; i>=0; i--)
    if(v[i]>v[i+1]) b[i] = b[i+1] + 1;
    int ans = 0;
    for(int i = 0; i<n; i++)
    ans += max(a[i],b[i]);
    
    cout<<ans<<"\n";
}


int main()
{
    fast
    ll t;cin>>t;while(t--)
    solve();
    return 0;
}