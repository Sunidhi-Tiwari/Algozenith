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

int n,m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool isvalid(int x, int y)
{
      if(x >= 0 && x<n && y>=0 && y<m)
      return true;
      return false;
}

void solve()
{   
    
    cin>>n>>m;
    
    int dist[n][m];
    char grid[n][m];
    
    for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++)
    dist[i][j] = INT_MAX;
    
    for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++)
    cin>>grid[i][j];
    
    
    
    deque<pair<int,int>> dq;
    dq.push_front({0,0});
    
    dist[0][0] = 0;
    
    while(!dq.empty())
    { 
                                  auto cur = dq.front();
                                  dq.pop_front();
                                  
                                  for(int i = 0; i<4; i++)
                                  {
                                                                int x = dx[i] + cur.ff;
                                                                int y = dy[i] + cur.ss;
                                                                
                                                                if(isvalid(x,y))
                                                                {
                                                                             if(grid[x][y] == '.')
                                                                             {
                                                                                                           if(dist[x][y] > dist[cur.ff][cur.ss]) 
                                                                                                           {
                                                                                                           dist[x][y] = dist[cur.ff][cur.ss];
                                                                                                           
                                                                                                           dq.push_front({x,y});
                                                                                                           }
                                                                                                           
                                                                             }
                                                                             else 
                                                                             {
                                                                                                           for(int p = x-1; p<= x+1; p++)
                                                                                                           {
                                                                                                                                         for(int q = y-1; q<= y+1; q++)
                                                                                                                                         {
                                                                                                                                                                       if(isvalid(p,q))
                                                                                                                                                                       {
                                                                                                                                                                               if(dist[p][q] > dist[cur.ff][cur.ss] + 1) 
                                                                                                                                                                                {
                                                                                                                                                                                dist[p][q] = dist[cur.ff][cur.ss] + 1;
                                                                                                                                                                                dq.push_back({p,q});
                                                                                                                                                                                }
                                                                                                                                                                       }
                                                                                                                                                                       
                                                                                                                                         }
                                                                                                           }
                                                                             }
                                                                }
                                  }
                                  
    }
    
     
   cout<<dist[n-1][m-1];
    return;
}

signed main()
{   IOS
    /*int t;
    cin>>t;
    while(t--)*/
    solve();
    return 0;
}