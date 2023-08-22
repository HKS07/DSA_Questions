//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &a , int N){
        
        long l = 0, r = 0, sum = 0, sol = 0;
        
        while( r < N )
        {
            sum += a[r];
            
            if( r - l + 1 < k)
            {
                ++r;
            }
            else if( r - l + 1 == k )
            {
                sol = max( sol, sum);
                sum -= a[l];
                ++l; ++r;
            }
        }
        return sol;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends