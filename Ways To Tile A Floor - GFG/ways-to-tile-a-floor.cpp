//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    
  public:
    int mod = 1e9 + 7;
    long long dp[100001];
    long long help( long long n )
    {
        if( n < 0 ) return 0;
        if( n == 0 ) return 1;
        if( dp[n] != -1 ) return dp[n];
        return dp[n] = (help(n-1)%mod + help(n-2)%mod)%mod;
    }
    long long numberOfWays(long long n) {
        memset(dp,-1,sizeof(dp));
        return help(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends