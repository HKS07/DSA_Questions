//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    void relax( vector<vector<int>>& edges, vector<int> &dist)
    {
        
    }
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S] = 0;
        for( int itr = 1; itr < V; ++itr )
        {
            // Now do relaxation for each edge
            for( int i = 0; i < edges.size(); ++i )
            {
                int u = edges[i][0], v = edges[i][1], edgeWt = edges[i][2];
                
                if( u != 1e8  )
                {
                    // already reached to u
                    if( dist[u] + edgeWt < dist[v] )
                    {
                        dist[v] = dist[u] + edgeWt;
                    }
                }
            }
        }
        // checking for negative cycle
        for( int i = 0; i < edges.size(); ++i )
            {
                int u = edges[i][0], v = edges[i][1], edgeWt = edges[i][2];
                
                if( u != 1e8  )
                {
                    // already reached to u
                    if( dist[u] + edgeWt < dist[v] )
                    {
                        return {-1};
                    }
                }
            }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends