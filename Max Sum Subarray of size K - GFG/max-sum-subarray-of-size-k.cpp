//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long i = 0,j =0, sol = 0, sum = 0;
        
        while( j < N )
        {
            sum += Arr[j];
            if( j - i + 1 < K )
                ++j;
            else if( j - i + 1 == K )
            {
                sol = max( sol, sum);
                sum -= Arr[i];
                ++i;
                ++j;
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