// 30 Dec 2021
// Binary Search Fundamentals
// an array consist of just 0s and 1s, find the first occurence of 1
// for input [0,0,1,1,1,1], output is 2


#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n; // no. of element in array
	int arr[n]; 
	
	for(int i = 0;i<n; i++)
	cin>>arr[i];  // taking input of array
	
	int s = 0;
	int e = n-1;
	int ans = -1;
	
	while(s<=e)
	{
	    int mid = (s+e)/2;
	    
	    if(arr[mid] == 1)
	    {
	    ans = mid;
	    e = mid - 1;
	    }
	    else
	    {
	        s = mid + 1;
	    }
	    
	}
	
	cout<<ans<<"\n";
	return 0;
	
	
}
