//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int help( int idx, int W, int wt[], int val[], vector<vector<int>> &dp )
    {
        //base case
        if( idx == 0 )
        {
            if( wt[0] <= W ) return val[idx];
            else return 0;
        }
        if( dp[idx][W] != -1 ) return dp[idx][W];
        // operation and recursion
        int notTake = help( idx - 1, W, wt, val, dp );
        int take = INT_MIN;
        if( wt[idx] <= W )
        {
            take = val[idx] + help( idx - 1, W - wt[idx], wt, val, dp );
        }
        
        return dp[idx][W] = max( take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp( n, vector<int> ( W + 1, -1 ) );
       return help( n-1, W, wt, val, dp );
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends