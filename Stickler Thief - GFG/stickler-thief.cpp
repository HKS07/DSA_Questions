//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helpLoot( int hNo, int a[] )
    {
        if( hNo == 0 ) return a[0];
        
        
        //
        int first = INT_MIN, second = INT_MIN;
        if( hNo - 2 >=0 )
        first = a[hNo] + helpLoot(hNo-2,a);
        if( hNo - 1 >=0 )
         second = helpLoot(hNo-1,a);
         
         return max( first, second);
    }
    int FindMaxSum(int a[], int n)
    {
        // int a[] = arr;
        if( n == 2 ) return max(a[0],a[1]);
        vector<int> dp(n,0);
        dp[0] = a[0];
        
        for( int hNo = 1; hNo < n; ++hNo )
        {
            int pick = a[hNo];
            if(hNo>1)
                pick += dp[hNo-2];
            int nonPick = 0+ dp[hNo-1];
        
            dp[hNo]= max(pick, nonPick);
        }
        return dp[n-1];
        // return helpLoot(n-1,arr);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends