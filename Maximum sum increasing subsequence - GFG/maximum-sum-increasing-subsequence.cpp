//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int help( int arr[], int idx, int prevIdx, int n,  vector<vector<int>> &dp)
	{
	    if( idx == n ) return 0;
	    if( dp[idx][prevIdx+1] != -1 ) return dp[idx][prevIdx+1];
	    // operation
	    int notTake = help( arr, idx + 1, prevIdx,n,dp );
	    int take = INT_MIN;
	    if( idx == -1 || arr[idx] > arr[prevIdx] )
	    {
	        take = arr[idx] + help( arr, idx + 1, idx, n,dp );
	    }
	    return dp[idx][prevIdx+1] = max( notTake, take);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp( n, vector<int> ( n + 1, -1));
	    return help( arr, 0, -1, n, dp );
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends