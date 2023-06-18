//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
            bool order=true;
    int start=1, end=N;
    while(1)
    {
        if(end-start<=K)
        {
            if(order)
                return end;
            else
                return start;
        }
        if(order)
        {
            start+=K;
        }
        else
        {
            end-=K;
        }
        order=!order;
    }
    return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends