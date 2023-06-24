//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs( int node, vector<int> adjList[], vector<int> &vis)
    {
        vis[node] = 1;
        
        for( auto  neighbor: adjList[node] )
        {
            if( vis[neighbor] == -1 )
            {
                dfs(neighbor, adjList, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V];
        for( int i = 0; i < V; ++i )
        {
            for( int j = 0; j < V; ++j )
            {
                if(adj[i][j] == 1)
                {
                    adjList[i].push_back(j);
                }
            }
        }
        
        int count = 0;
        vector<int> vis(V,-1);
        for( int i = 0; i < V; ++i )
        {
            if( vis[i] == -1 )
            {
                // cout<<"hi";
                count++;
                dfs(i, adjList, vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends