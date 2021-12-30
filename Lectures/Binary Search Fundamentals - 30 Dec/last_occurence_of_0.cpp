// 30 Dec 2021
// Binary Search Fundamentals
// an array consist of just 0s and 1s, find the last occurence of 0
// for input [0,0,1,1,1,1], output is 1

#include <iostream>
using namespace std;

int n;
int arr[100100];

int main() {
	// your code goes here
	cin>>n;
	for(int i = 0; i<n; i++)
	cin>>arr[i];
	
	int lo = 0;
	int hi = n-1;
	int ans = -1;
	
	while(lo<=hi) // O(lon(n))
	{
	    int mid = (lo+hi)/2;
	    if(arr[mid]==0)
	    {
	        ans = mid;
	        lo = mid + 1;
	    }
	    else
	    {
	        hi = mid - 1;
	    }
	}
	
	cout<<ans;
	return 0;
}

