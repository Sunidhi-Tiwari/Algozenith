#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
    
	int n,k;
	cin>>n>>k;
	
	priority_queue<pair<int,pair<int,int>>> pq;
	
	int x,y, dis, distop;
	
	for(int i = 0; i<k; i++)
	{
	                             
	                              cin>>x>>y;
	                              dis = pow(x,2) + pow(y,2);
	                              pq.push({dis,{x,y}});
	}
	
	for(int i = k; i<n; i++)
	{
	                              
	                              cin>>x>>y;
	                              dis = pow(x,2) + pow(y,2);
	                              distop = pq.top().first;
	                     
	                              
	                              if((dis < distop) || (dis == distop && x<pq.top().second.first) )
	                              {
	                                                            pq.pop();
	                                                            pq.push({dis,{x,y}});
	                              }
	                              
	                                                   
	                              
	}
	
	vector<pair<int,int>> ans;
	

	
	while(!pq.empty())
	{
	                       
	                        
	                        ans.push_back({pq.top().second.first, pq.top().second.second});
	                        pq.pop();
	                        
	                        
	}
	
	reverse(ans.begin(),ans.end());
	
	for(auto i: ans)
	cout<<i.first<<" "<<i.second<<"\n";
	
	return;
    
  
        
}

signed main()
{
    
    solve();
    return 0;
}