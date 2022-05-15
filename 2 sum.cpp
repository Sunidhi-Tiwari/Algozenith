#include<bits/stdc++.h>
using namespace std;

void solve(){
    
	int n,k;
	cin>>n>>k;
    
  
        
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	  if(n == 1)
	  {
                                 cout<<"N\n";
                                 return;
                                }
    
    
    sort(arr.begin(),arr.end());
    
    int left = 0;
    int right = n-1;
    int flag = 0;
    
    while(right>left)
    {
        if(arr[left] + arr[right] == k)
        {
        flag = 1;
        break;
        }
        else if(arr[left] + arr[right] > k)
        right--;
        else
        left++;
    }
    
    if(flag)
    cout<<"Y\n";
    else
    cout<<"N\n";
    
    return;
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}