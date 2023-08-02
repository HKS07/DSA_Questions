//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs( int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &s)
    {
        vis[node] = 1;
        
        for( auto it: adj[node] )
        {
            int adjNode = it.first;
            if( !vis[adjNode] ) dfs( adjNode, adj, vis, s);
        }
        s.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& e){
        vector<pair<int,int>> adj[N];
        
        for( int i = 0; i < M; ++i )
        {
            int u = e[i][0], v = e[i][1], wt = e[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> vis(N,0);
        stack<int> s;
        for( int i = 0; i < N; ++i )
        {
            if( !vis[i]  )
            {
                dfs(i, adj, vis, s);
            }
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        while( !s.empty() )
        {
            int node = s.top(); s.pop();
            if( dist[node] == 1e9 ) continue;
            for( auto it: adj[node] )
            {
                int v = it.first, wt = it.second;
                if( dist[node] + wt < dist[v] )
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends