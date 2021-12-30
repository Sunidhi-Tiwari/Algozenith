// searching an element X

#include <iostream>
using namespace std;

int n,X;
int arr[100100];

int check(int x) // F(x) O(1) function
{
    if(arr[x]<X) return 0;
    else return 1;
}

int main() {
	// your code goes here
	cin>>n;
	for(int i = 0; i<n; i++)
	cin>>arr[i];
	cin>>X;
	
	int lo = 0;
	int hi = n-1;
	int ans = -1; // default answer
	
	while(lo<=hi) // O(log(n))
	{
	    int mid = (lo+hi)/2;
	    if(check(mid))
	    {
	        ans = mid;
	        hi = mid - 1;
	    }
	    else
	    {
	        lo = mid + 1;
	    }
	}
	
	cout<<ans;
	return 0;
}
