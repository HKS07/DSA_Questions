//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs( int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis )
    {
        vis[node] = true;
        dfsVis[node] = true;
        
        for( auto adjNode: adj[node] )
        {
            if( !vis[adjNode] ) 
                // if( dfs( adjNode, adj, vis, dfsVis )) return true;
            {
                bool b = dfs( adjNode, adj, vis, dfsVis );
                if( b ) return true;
            }
            else if( dfsVis[adjNode] ) return true;
        }
        dfsVis[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false),dfsVis(V,false);
        
        for( int i = 0; i < V; ++i )
        {
            if( !vis[i] )
                // if( dfs( i, adj, vis, dfsVis ) ) return true;
            {
                bool b = dfs( i, adj, vis, dfsVis );
                if( b ) return true;
            }
        }
        
        return false;
    }
    //  bool dfs(int node,vector<int>&vis,vector<int>&dfsvis,vector<int>adj[]){
    //     vis[node] = 1;
    //     dfsvis[node] = 1;
    //     for(auto i:adj[node]){
    //         if(!vis[i]){
    //             bool b = dfs(i,vis,dfsvis,adj);
    //             if(b) return 1;
    //         }
    //         else if(dfsvis[i]) return 1;
    //     }
    //     dfsvis[node] = 0;
    //     return 0;
    // }
    // bool isCyclic(int V, vector<int> adj[]) {
    //     vector<int>vis(V,0);
    //     vector<int>dfsvis(V,0);
    //     for(int i=0;i<V;i++){
    //         if(!vis[i]){
    //             bool b = dfs(i,vis,dfsvis,adj);
    //             if(b) return 1;
    //         }
    //     }
    //     return 0;
    // }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends